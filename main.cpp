#include <stdio.h>
#include <stdlib.h>

#include "FontHandler.h"
#include "Renderer.h"

#include <hb.h>
#include <hb-ft.h>

#include <ft2build.h>

#define WIDTH 256
#define HEIGHT 256


int main()
{
    const char* fontfile = "Resources/Roboto-Bold.ttf";
    const char* text = "ffi.";

    FontHandler fh;
  
    // Initialize the font
    if (fh.initFont(fontfile)) {
        return 1;
    }

    // Shape the text
    if (fh.shape(text)) {
        return 1;
    }

    // Render the glyphs
    std::vector<FT_Bitmap*> glyphs = fh.getGlyphs();
    Renderer renderer;

    renderer.render_glyphs(glyphs);

    // Cleanup
    fh.destroyFont();
}


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