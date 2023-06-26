#include "TextShapingPerformanceTester.h"

int main()
{
    char* fontFile = "Resources/Roboto-Bold.ttf";

    // PERFORMANCE TESTS
//    TextShapingPerformanceTester tester(fontFile);

    ////tester.shapeSameString(100, "ffi");
    ////tester.runRandomStringTests(1, 100);
    //tester.runRandomStringOnlyShapingTests(10, 200);

    //printf("Average time taken: %.10lf milliseconds\n", tester.getAverageTime());
    //printf("Minimum time taken: %.10lf milliseconds\n", tester.getMinTime());
    //printf("Maximum time taken: %.10lf milliseconds\n", tester.getMaxTime());
    //printf("Median time taken: %.10lf milliseconds\n", tester.getMedianTime());

    //tester.printAllTimings();

    // Example using FT, HB, and Renderer

    FontHandler fh;
    fh.initFont(fontFile, false);
    fh.shape("ffi.", true);

    Renderer renderer;
    renderer.render_glyphs(fh.getGlyphs());

    fh.destroyFont();

    return 0;
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