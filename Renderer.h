#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <hb-ft.h>

class Renderer {
public:
    void render_glyphs(const std::vector<FT_Bitmap*>& bitmaps);
};

#endif // RENDERER_H
