#include "TextShapingPerformanceTester.h"
#include <GL/glew.h> // Include the GLEW header file
#include <GLFW/glfw3.h> // Include the GLFW header file

void performTextShapingTest() {
    char* fontFile = "Resources/Roboto-Bold.ttf";

    // PERFORMANCE TESTS
    // TextShapingPerformanceTester tester(fontFile);
    // tester.shapeSameString(100, "ffi");
    // tester.runRandomStringTests(1, 100);
    // tester.runRandomStringOnlyShapingTests(10, 200);

    // printf("Average time taken: %.10lf milliseconds\n", tester.getAverageTime());
    // printf("Minimum time taken: %.10lf milliseconds\n", tester.getMinTime());
    // printf("Maximum time taken: %.10lf milliseconds\n", tester.getMaxTime());
    // printf("Median time taken: %.10lf milliseconds\n", tester.getMedianTime());

    // tester.printAllTimings();

    // Example using FT, HB, and Renderer
    FontHandler fh;
    fh.initFont(fontFile, false);
    fh.shape("ffi.", true);

    Renderer renderer;
    renderer.render_glyphs(fh.getGlyphs());

    fh.destroyFont();
}

int main() {
    //performTextShapingTest();
    // OpenGL Window creation and context set-up

    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
