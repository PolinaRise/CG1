#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H


#include "Image.h"
#include "Player.h"
#define GLFW_DLL
#include <GLFW/glfw3.h>


struct InputState
{
  bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 100, lastY = 200; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse         = true;  // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;

void OnKeyboardPressed(GLFWwindow* window, int key, int scancode, int action, int mode);

void processPlayerMovement(Player &player);

void OnMouseButtonClicked(GLFWwindow* window, int button, int action, int mods);

void OnMouseMove(GLFWwindow* window, double xpos, double ypos);

void OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset);

#endif
