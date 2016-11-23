#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl\GL.h> 
#include <gl\GLU.h>
#include "Matrix.h"
using namespace std;
using namespace sf;
///Name: Keenan McEntee
///Student No: C00201892
///Open GL program to show the use of Matrix + Vector Classes.
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
	const int PRIMITIVES;
	void updateMatrix();
	GLuint index;
	Clock clock;
	Clock clock2;
	Time elapsed;
	Time elapsedRotate;
	customVector::Vector3 pt1;
	customVector::Vector3 pt2;
	customVector::Vector3 pt3;
	customVector::Vector3 pt4;
	customVector::Vector3 pt5;
	customVector::Vector3 pt6;
	customMatrix::Matrix m1;
	customMatrix::Matrix m2;
	void keyboardHandling();
	const float MOVE = 0.0001f;
	float rotationAngle =0.01f;
};