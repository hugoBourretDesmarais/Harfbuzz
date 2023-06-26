#include <algorithm>
#include <random>
#include "TextShapingPerformanceTester.h"

TextShapingPerformanceTester::TextShapingPerformanceTester(const char* fontfile) 
    : fontfile(fontfile) {}

bool TextShapingPerformanceTester::shapeSameStringSingle(const char* text) 
{
    // Initialize the font
    if (fh.initFont(fontfile, false)) {
        return false;
    }

    // Shape the text
    if (fh.shape(text, false)) {
        return false;
    }

    // Cleanup
    fh.destroyFont();

    return true;
}

void TextShapingPerformanceTester::shapeSameString(int numberOfTests, const char* text) {
    timings.clear();
    for (int i = 0; i < numberOfTests; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        shapeSameStringSingle(text);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        timings.push_back(duration.count());
    }
}

void TextShapingPerformanceTester::runRandomStringTests(int stringLength, int numberOfTests) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    timings.clear();
    for (int i = 0; i < numberOfTests; i++) {
        std::string str;
        for (int i = 0; i < stringLength; i++) {
            str += alphanum[dis(gen)];
        }

        auto c = str.c_str();

        auto start = std::chrono::high_resolution_clock::now();
        shapeSameStringSingle(c);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(stop - start);
        timings.push_back(duration.count());
    }
}

void TextShapingPerformanceTester::runRandomStringOnlyShapingTests(int stringLength, int numberOfTests) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    timings.clear();

    // Initialize the font
    if (fh.initFont(fontfile, false)) {
        std::cout << "Failed to initialize font" << std::endl;
    }

    for (int i = 0; i < numberOfTests; i++) {
        std::string str;
        for (int i = 0; i < stringLength; i++) {
            str += alphanum[dis(gen)];
        }

        onlyMeasureShaping(str.c_str());
    }

    // Cleanup
    fh.destroyFont();
}

bool TextShapingPerformanceTester::onlyMeasureShaping(const char* text) 
{
    auto start = std::chrono::high_resolution_clock::now();

    // Shape the text
    fh.shape(text, false);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(stop - start);
    timings.push_back(duration.count());

    return true;
}

double TextShapingPerformanceTester::getAverageTime() {
    double sum = 0;
    for (auto& n : timings)
        sum += n;
    return sum / timings.size();
}

double TextShapingPerformanceTester::getMinTime() {
    return *std::min_element(timings.begin(), timings.end());
}

double TextShapingPerformanceTester::getMaxTime() {
    return *std::max_element(timings.begin(), timings.end());
}

double TextShapingPerformanceTester::getMedianTime() {
    if (timings.size() % 2 == 0)
        return (timings[timings.size()/2 - 1] + timings[timings.size()/2]) / 2.0;
    else
        return timings[timings.size()/2];
}

void TextShapingPerformanceTester::printAllTimings() {
    for (int i = 0; i < timings.size(); i++) {
        printf("Timing %d: %.10lf milliseconds\n", i + 1, timings[i]);
    }
}