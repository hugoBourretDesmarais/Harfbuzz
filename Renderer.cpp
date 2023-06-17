#include "Renderer.h"
#include <iostream>
#include <vector>

void Renderer::render_glyphs(const std::vector<FT_Bitmap*>& bitmaps)
{
    // ASCII shades from light to dark
    const char* shades = " .:-=+*#%@";

    // Iterate over all bitmap
    for (auto bitmap : bitmaps) {
        // Print bitmap dimensions
        printf("Bitmap dimensions: Width = %d, Rows = %d, Pitch = %d\n", 
            bitmap->width, bitmap->rows, bitmap->pitch);

        // Print the bitmap content
        for (int i = 0; i < bitmap->rows; i++) {
            for (int j = 0; j < bitmap->width; j++) {
                // Get the pixel brightness (0 = black, 255 = white)
                unsigned char pixel = bitmap->buffer[i * bitmap->pitch + j];
                
                // Convert the brightness to an index in the shades array (0 = white, 10 = black)
                int shade_index = (255 - pixel) / 26;  // Integer division, range is 0-10
                
                // Print the corresponding ASCII character
                putchar(shades[shade_index]);
            }
            putchar('\n');
        }

        // Print a newline to separate the bitmaps
        printf("\n\n");
    }
}
