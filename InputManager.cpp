#include "InputManager.h"

GLFWwindow* InputManager::window = nullptr;

void InputManager::Init(GLFWwindow* glfw_window)
{
	window = glfw_window;
}
void InputManager::Update()
{
	glfwPollEvents();
}

bool InputManager::IsKeyPressed(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}
bool InputManager::IsKeyReleased(int key)
{
	return glfwGetKey(window, key) == GLFW_RELEASE;
}
bool InputManager::IsKeyHeld(int key)
{
	return glfwGetKey(window, key) == GLFW_REPEAT;
}

void InputManager::GetMousePosition(double& x, double& y)
{
	glfwGetCursorPos(window, &x, &y);
}
bool InputManager::IsMouseButtonPressed(int button)
{
	return glfwGetMouseButton(window, button) == GLFW_PRESS;
}