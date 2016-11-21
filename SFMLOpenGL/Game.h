#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl\GL.h> 
#include <gl\GLU.h>
#include "Matrix.h"
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
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;
	customVector::Vector3 pt1;
	customVector::Vector3 pt2;
	customVector::Vector3 pt3;
	customVector::Vector3 pt4;
	customVector::Vector3 pt5;
	customVector::Vector3 pt6;
	customMatrix::Matrix m1;
	customMatrix::Matrix m2;
	float rotationAngle = 20.0f;
};