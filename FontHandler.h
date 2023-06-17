#ifndef FONT_HANDLER_H
#define FONT_HANDLER_H

#include <hb.h>
#include <hb-ft.h>
#include <iostream>

class FontHandler {
public:
    int shape(const char* text);
    int initFont(const char* fontfile);
    void destroyFont();
    std::vector<FT_Bitmap*> getGlyphs();
    
private:
    static hb_position_t my_h_advance_func(hb_font_t *font, void *font_data,
                                 hb_codepoint_t glyph, void *user_data);
    
    // Define font properties
    static FT_Library ft_library;
    static FT_Face ft_face;
    static hb_font_t* parent_font;
    static hb_font_t* hb_font;
    static hb_buffer_t* hb_buffer;

    std::vector<hb_glyph_info_t> glyphs_info;
    std::vector<FT_Bitmap*> glyphs_bitmaps;
};

#endif