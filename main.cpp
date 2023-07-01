#include <GL/glew.h> // Include the GLEW header file
#include <GLFW/glfw3.h> // Include the GLFW header file
#include <cstdio>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    printf("Resizing Viewport");
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    // OpenGL Window creation and context set-up

    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    if (glewInit() != GLEW_OK)
        return -1;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Render here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


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
    //FontHandler fh;
    //fh.initFont(fontFile, false);
    //fh.shape("ffi.", true);

    //Renderer renderer;
    //renderer.render_glyphs(fh.getGlyphs());

    //fh.destroyFont();
}