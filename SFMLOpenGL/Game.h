/// <summary> /// Change 1 Add GL.H and Glu.h 
/// 
/// This hooks up OpenGL with our Game 
/// </summary> 

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl\GL.h> 
#include <gl\GLU.h>
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

	float rotationAngle = 0.01f;
};