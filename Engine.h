#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "GameObjectManager.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Init();
	void Run();
	int GetFPS();
	void SetFPS(int new_fps);
private:
	bool running;
	int fps = 60;

	GLFWwindow* window;
	Renderer renderer;
	GameObjectManager global_manager;

	void InitOpenGL();
	void Update();
	void Render();
};