#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Matrix3.h"
#include "Vector3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	 // Uncomment for Part 2
	 // ********************
	 const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;

	Vector3Class topLeft, topRight, bottomRight, bottomLeft;
	Vector3Class square[4];
	 // ********************
};