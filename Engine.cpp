#include <iostream>
#include <chrono>
#include <thread>
#include <gl/glew.h>
#include <GLFW/glfw3.h>


#include "Engine.h"
#include "Matrix.h"
#include "Vector.h"
#include "PhysicsObject.h"
#include "InputManager.h"

using namespace std;

void DebugMatrix() {
    // Create an identity matrix
    Matrix mat;
    std::cout << "Initial Identity Matrix:\n";
    mat.Print();
    
        mat.Translate(2.0f, 3.0f);
        std::cout << "\nAfter Translation (2, 3):\n";
        mat.Print();
        mat.Scale(1.5f, 0.5f);
        std::cout << "\nAfter Scaling (1.5, 0.5):\n";
        mat.Print();
        mat.Rotate(3.14159f / 4);
        std::cout << "\nAfter Rotation (45 degrees):\n";
        mat.Print();

        Vector vec(1.0f, 1.0f);
        Vector transformedVec = mat * vec;
        std::cout << "\nTransformed Vector (1,1) after all transformations: ("
            << transformedVec.x << ", " << transformedVec.y << ")\n";

}

void TestPhysics() {
    PhysicsObject testObject;
    testObject.SetPosition(Vector(0, 0, 0));  // Start at (0,0)
    testObject.SetVelocity(Vector(0, 0, 0));  // No initial movement
    testObject.SetMass(1.0f);  // Normal mass

    Vector gravity(0, -9.81f, 0);  // Simulate Earth gravity
    float deltaTime = 0.016f;  // Simulate ~60 FPS (16ms per frame)

    std::cout << "Initial Position: "; testObject.GetPosition().Print();

    for (int i = 0; i < 10; i++) {  // Simulate 10 frames
        testObject.ApplyForce(gravity * testObject.GetMass());  // Apply gravity
        testObject.Update(deltaTime);  // Update motion

        std::cout << "Frame " << i + 1 << " - Position: ";
        testObject.GetPosition().Print();
        std::cout << "Velocity: ";
        testObject.GetVelocity().Print();
    }
}

Engine::Engine() : running(true), fps(60), window(nullptr)
{
}
Engine::~Engine()
{
	cout << "Engine Deconstructed" << endl;
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Engine::Init()
{
    std::cout << "Initializing Game Objects..." << std::endl;

    InputManager::Init(window);
    Shader* engineShader = renderer.GetShader();
    if (!engineShader) {
        std::cerr << "ERROR: Renderer has no shader!" << std::endl;
        return;
    }
    GameObject* fallingObject = new GameObject(0.5f, 0.5f, *engineShader);
    fallingObject->GetPhysics()->ApplyForce(Vector(0.0f, -9.8f));

    global_manager.AddObject(fallingObject);

    std::cout << "Game Objects Initialized!" << std::endl;
}
void Engine::Run()
{

    InitOpenGL();
    Init();
    if (!running)
    {
        return;
    }
	cout << "Engine Running" << endl;

    std::chrono::milliseconds frameTime(1000 / fps);

    //TestPhysics();

    while (running && !glfwWindowShouldClose(window))
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        Update();
        Render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(frameTime - (endTime - startTime));
    }
}
void Engine::Update()
{
    float deltaTime = 0.016f; // Simulated dt
    global_manager.Update(deltaTime);
    InputManager::Update();
    std::cout << "Engine Updating..." << std::endl;
}
void Engine::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    global_manager.DrawObjects();
	//cout << "Engine Rendering" << endl;
    renderer.Render();
}

void Engine::InitOpenGL() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        running = false;
        return;
    }

    window = glfwCreateWindow(800, 600, "OpenGL Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        running = false;
        return;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        running = false;
    }
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    renderer.Init();
}



int Engine::GetFPS()
{
    return fps;
}

void Engine::SetFPS(int new_fps)
{
    fps = new_fps;
}
