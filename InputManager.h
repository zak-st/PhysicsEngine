#pragma once

#include <GLFW/glfw3.h>

class InputManager
{
public:
	static void Init(GLFWwindow* glfw_window);
	static void Update();

	static bool IsKeyPressed(int key);
	static bool IsKeyReleased(int key);
	static bool IsKeyHeld(int key);

	static void GetMousePosition(double& x, double& y);
	static bool IsMouseButtonPressed(int button);

private:
	static GLFWwindow* window;
};

