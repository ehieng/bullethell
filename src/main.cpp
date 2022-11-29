#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//declare callback func for when window is resized
    void framebuffer_size_callback(GLFWwindow* window, int width, int height){
                glViewport(0, 0, width, height);
    }   

//sets close window to true if esc is pressed
    void processInput(GLFWwindow *window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

int main()
{
    //start gflw window
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
    //create window object
        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

        //check if it failed
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }

        //makes our window the current window this thread uses
        glfwMakeContextCurrent(window);

    //check if glad runs first before rendering
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

    //tell opengl window size
        glViewport(0, 0, 800, 600);

        //when window resizes, update the viewport
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //render loop
        while(!glfwWindowShouldClose(window))
        {
            //input
            processInput(window); //check for escape key

            //rendering

                
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //when clearing color buffer, it will use this color
                glClear(GL_COLOR_BUFFER_BIT); //clear color buffer


            //swap buffers and handle inputs
            glfwPollEvents(); //polls keyboard inputs 
            glfwSwapBuffers(window); //swap color buffers to render

            
        }

    //terminate glfw after done rendering window
    glfwTerminate();


    return 0;
}

