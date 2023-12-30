#include "iostream"
#include "glad.h"
#include "glfw/glfw3.h"
#include "Globals.hpp"
#include "Player.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 

void startAllGO() {
    for (GameObject* go : gameObjects) {
        go->Start();
    }
}

void updateAllGo() {
    for (GameObject* go : gameObjects) {
        go->Update();
    }
}

int main() { 
    Player player;

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Root Engine", nullptr, nullptr);
    if (window ==  NULL) {
        std::cout << "Cannot create window please review your code again...";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 1280, 720);

    startAllGO();

    while(!glfwWindowShouldClose(window)) {
        updateAllGo();
        
        glClearColor(.75f, 0.75f, 0.75f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

