#include "FontHandler.h"

// Define font properties
FT_Library FontHandler::ft_library;
FT_Face FontHandler::ft_face;
hb_font_t* FontHandler::parent_font;
hb_font_t* FontHandler::hb_font;
hb_buffer_t* FontHandler::hb_buffer;

hb_position_t FontHandler::my_h_advance_func(hb_font_t *font, void *font_data,
                                 hb_codepoint_t glyph, void *user_data) {
    hb_font_t *parent_font = (hb_font_t *)user_data;
    hb_position_t advance = hb_font_get_glyph_h_advance(parent_font, glyph);
    std::cout << "Advance for glyph " << glyph << ": " << advance << std::endl;
    return advance * 1.5;  // Multiply the advance width by 1.5
}

int FontHandler::initFont(const char* fontfile, const bool overrideXAdvance = false) 
{
    // Initialize freetype library
    if (FT_Init_FreeType(&ft_library)) {
        std::cerr << "Could not initialize freetype library." << std::endl;
        return 1;
    }

    // Create FT_Face
    if (FT_New_Face(ft_library, fontfile, 0, &ft_face)) {
        std::cerr << "Could not open font." << std::endl;
        return 1;
    }

    // Set font size
    FT_Set_Char_Size(ft_face, 16 * 64, 0, 300, 0);

    if (overrideXAdvance) {
        // Create hb_font
        parent_font = hb_ft_font_create(ft_face, NULL);
        hb_font = hb_font_create_sub_font(parent_font);

        // Create new font funcs and set our custom function
        hb_font_funcs_t *funcs = hb_font_funcs_create();
        hb_font_funcs_set_glyph_h_advance_func(funcs, FontHandler::my_h_advance_func, parent_font, NULL);  // Set the custom function
        hb_font_set_funcs(hb_font, funcs, NULL, NULL);  // Use the new funcs in our font
        hb_font_funcs_destroy(funcs);  // We can destroy the funcs now, the font keeps a reference
    }
    else {
        // Create hb_font
        hb_font = hb_ft_font_create(ft_face, NULL);
    }

    // Create hb_buffer and populate
    hb_buffer = hb_buffer_create();

    return 0;
}

void FontHandler::destroyFont() {
    hb_buffer_destroy(hb_buffer);
    hb_font_destroy(hb_font);
    hb_font_destroy(parent_font);
    FT_Done_Face(ft_face);
    FT_Done_FreeType(ft_library);

    for (FT_Bitmap* bitmap : glyphs_bitmaps)
    {
        delete bitmap;
    }
    glyphs_bitmaps.clear();
}

int FontHandler::shape(const char* text, const bool debug) 
{
    // Clear buffer
    hb_buffer_clear_contents(hb_buffer);

    hb_buffer_add_utf8(hb_buffer, text, -1, 0, -1);
    hb_buffer_guess_segment_properties(hb_buffer);

    // Shape!
    hb_shape(hb_font, hb_buffer, features.empty() ? NULL : &features[0], features.size());

    // Get glyph information and positions out of buffer
    unsigned int len = hb_buffer_get_length(hb_buffer);
    hb_glyph_info_t* info = hb_buffer_get_glyph_infos(hb_buffer, NULL);
    hb_glyph_position_t* pos = hb_buffer_get_glyph_positions(hb_buffer, NULL);

    if(debug)
    {
        glyphs_info.assign(info, info + len);

        // Print them out
        for (unsigned int i = 0; i < len; i++) {
            std::cout << "Cluster " << info[i].cluster << " ";
            std::cout << "Glyph " << info[i].codepoint << " ";
            std::cout << "at (" << pos[i].x_advance/64.0 << ", " << pos[i].y_advance/64.0 << ")" << std::endl;
        }
    }

    return 0;
}

void FontHandler::enableFeatures(const std::vector<std::string>& featuresStr) 
{
    features.clear();
    for (const std::string& feature : featuresStr) 
    {
        hb_feature_t hbFeature;
        if (hb_feature_from_string(feature.c_str(), -1, &hbFeature)) 
        {
            features.push_back(hbFeature);
        } 
        else 
        {
            std::cerr << "Could not parse feature: " << feature << std::endl;
        }
    }
}

std::vector<FT_Bitmap*> FontHandler::getGlyphs() {
    std::vector<FT_Bitmap*> bitmaps;

    for (const hb_glyph_info_t& glyph_info : glyphs_info) {
        FT_Load_Glyph(ft_face, glyph_info.codepoint, FT_LOAD_DEFAULT);

        FT_GlyphSlot slot = ft_face->glyph;
        FT_Render_Glyph(slot, FT_RENDER_MODE_NORMAL);

        FT_Bitmap* bitmap_copy = new FT_Bitmap;
        *bitmap_copy = slot->bitmap;  // Copy the bitmap
        bitmaps.push_back(bitmap_copy);
    }

    return bitmaps;
}
