#include <vector>
#include <chrono>

#include "FontHandler.h"
#include "Renderer.h"

#include <hb.h>
#include <hb-ft.h>

#include <ft2build.h>

#define WIDTH 256
#define HEIGHT 256

class TextShapingPerformanceTester
{
private:
    const char* fontfile;
    FontHandler fh;
    std::vector<double> timings;

    bool shapeSameStringSingle(const char* text);
    bool onlyMeasureShaping(const char* text);

public:
    TextShapingPerformanceTester(const char* fontfile);
    void shapeSameString(int numberOfTests, const char* text);
    void runRandomStringTests(int stringLength, int numberOfTests);
    void runRandomStringOnlyShapingTests(int stringLength, int numberOfTests);
    double getAverageTime();
    double getMinTime();
    double getMaxTime();
    double getMedianTime();
    void printAllTimings();
};
