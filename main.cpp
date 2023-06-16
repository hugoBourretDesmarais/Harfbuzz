#include <stdio.h>
#include <stdlib.h>

#include <hb.h>
#include <hb-ft.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H


#include <cairo.h>
#include <cairo-ft.h>

#define WIDTH 256
#define HEIGHT 256

static void render_glyph(FT_GlyphSlot slot)
{
    FT_Bitmap* bitmap = &slot->bitmap;
    
    // Convert the FreeType bitmap to a Cairo image surface
    cairo_surface_t *surface = cairo_image_surface_create_for_data(bitmap->buffer, 
                                                                   CAIRO_FORMAT_A8, 
                                                                   bitmap->width, 
                                                                   bitmap->rows, 
                                                                   bitmap->pitch);
    cairo_t *cr = cairo_create(surface);

    cairo_set_source_rgba(cr, 1, 1, 1, 1);
    cairo_mask_surface(cr, surface, slot->bitmap_left, HEIGHT - slot->bitmap_top);

    cairo_surface_write_to_png(surface, "glyph.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}

int main()
{
    FT_Library library;
    FT_Face face;
    FT_Error error;

    error = FT_Init_FreeType(&library);
    if (error) {
        printf("An error occurred during library initialization\n");
        exit(1);
    }

    error = FT_New_Face(library, "NotoColorEmoji-Regular.ttf", 0, &face);
    if (error) {
        printf("An error occurred during font loading\n");
        exit(1);
    }

    FT_Set_Pixel_Sizes(face, 0, HEIGHT);

    hb_font_t *hb_font;
    hb_font = hb_ft_font_create(face, NULL);

    hb_codepoint_t glyph;
    hb_font_get_glyph(hb_font, 0x1F60A, 0, &glyph); // Emoji U+1F60A "SMILING FACE WITH SMILING EYES"

    error = FT_Load_Glyph(face, glyph, FT_LOAD_DEFAULT);
    if (error) {
        printf("An error occurred during glyph loading\n");
        exit(1);
    }

    FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

    render_glyph(face->glyph);

    hb_font_destroy(hb_font);
    FT_Done_Face(face);
    FT_Done_FreeType(library);

    return 0;
}



// Custom function to get the glyph's horizontal advance
//hb_position_t my_h_advance_func(hb_font_t *font, void *font_data,
                                 //hb_codepoint_t glyph, void *user_data) {
    //hb_font_t *parent_font = (hb_font_t *)user_data;
    //hb_position_t advance = hb_font_get_glyph_h_advance(parent_font, glyph);
    //std::cout << "Advance for glyph " << glyph << ": " << advance << std::endl;
    //return advance * 1.5;  // Multiply the advance width by 1.5
//}

//int HBFunctionOverload() {
    //std::cout << "----- Start! -----" << std::endl;
    //const char* fontfile = "Roboto-Bold.ttf";
    //const char* text = "Hello ffi";

    //FT_Library ft_library;
    //FT_Face ft_face;

    //// Initialize freetype library
    //if (FT_Init_FreeType(&ft_library)) {
        //std::cerr << "Could not initialize freetype library." << std::endl;
        //return 1;
    //}

    //// Create FT_Face
    //if (FT_New_Face(ft_library, fontfile, 0, &ft_face)) {
        //std::cerr << "Could not open font." << std::endl;
        //return 1;
    //}

    //// Set font size
    //FT_Set_Char_Size(ft_face, 16 * 64, 0, 300, 0);

    //// Create hb_font
    //hb_font_t* parent_font;
    //hb_font_t* hb_font;

    //parent_font = hb_ft_font_create(ft_face, NULL);
    //hb_font = hb_font_create_sub_font(parent_font);

    //// Create new font funcs and set our custom function
    //hb_font_funcs_t *funcs = hb_font_funcs_create();
    //hb_font_funcs_set_glyph_h_advance_func(funcs, my_h_advance_func, parent_font, NULL);  // Set the custom function
    //hb_font_set_funcs(hb_font, funcs, NULL, NULL);  // Use the new funcs in our font
    //hb_font_funcs_destroy(funcs);  // We can destroy the funcs now, the font keeps a reference

    //// Create hb_buffer and populate
    //hb_buffer_t* hb_buffer;
    //hb_buffer = hb_buffer_create();
    //hb_buffer_add_utf8(hb_buffer, text, -1, 0, -1);
    //hb_buffer_guess_segment_properties(hb_buffer);

    //// Shape!
    //hb_shape(hb_font, hb_buffer, NULL, 0);

    //// Get glyph information and positions out of buffer
    //unsigned int len = hb_buffer_get_length(hb_buffer);
    //hb_glyph_info_t* info = hb_buffer_get_glyph_infos(hb_buffer, NULL);
    //hb_glyph_position_t* pos = hb_buffer_get_glyph_positions(hb_buffer, NULL);

    //// Print them out
    //for (unsigned int i = 0; i < len; i++) {
        //std::cout << "Cluster " << info[i].cluster << " ";
        //std::cout << "Glyph " << info[i].codepoint << " ";
        //std::cout << "at (" << pos[i].x_advance/64.0 << ", " << pos[i].y_advance/64.0 << ")" << std::endl;
    //}

    //// Cleanup
    //hb_buffer_destroy(hb_buffer);
    //hb_font_destroy(hb_font);
    //hb_font_destroy(parent_font);
    //FT_Done_Face(ft_face);
    //FT_Done_FreeType(ft_library);

    //return 0;
//}


// hb_blob_t is a data type in HarfBuzz used to represent an opaque, 
// reference-counted blob of binary data. It can be used to manage memory 
// related to font data, handling operations like referencing, dereferencing, 
// and destroying the memory when it is no longer needed.

// hb_blob_create, hb_blob_get_length, hb_blob_get_data, hb_blob_destroy


// Example of hb_blob_get_data 
// unsigned int length;
// hb_blob_t *blob = hb_blob_create_from_file("path/to/font/file");
// const char *data = hb_blob_get_data(blob, &length);

// Now you can read the font data from the "data" pointer. Remember not to go past "length" bytes.

    //hb_blob_t *blob;
    //blob = hb_blob_create("test", 4, HB_MEMORY_MODE_READONLY, NULL, NULL);
    //unsigned int blob_length = hb_blob_get_length(blob);
    //hb_blob_destroy(blob);

    //return 0;