#include "Game.h"

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(1.0f, 1.0f, 1.0f);
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	
	glNewList(index, GL_COMPILE);
	/*glBegin(GL_TRIANGLES);
	{
		
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();*/
	//glEndList();
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.3, 0.0, -2.0);
		glVertex3f(0.15, 0.3, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(0.4, 0.0, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.3, 0.0, -2.0);

	}
	glEnd();
	glEndList();
	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.0, 0.3, -2.0);
		glVertex3f(0.2, 0.2, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.0, 0.2, -2.0);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(0.2, 0.2, -2.0);
		glVertex3f(0.1, 0.0, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.0, 0.2, -2.0);
		glVertex3f(0.65, 0.3, -2.0);
		glVertex3f(0.7, 0.2, -2.0);
		glVertex3f(0.8, 0.1, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.2, 0.1, -2.0);
		glVertex3f(0.4, 0.2, -2.0);
		glVertex3f(0.6, 0.3, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.1, 0.2, -2.0);
		glVertex3f(0.2, 0.3, -2.0);
		glVertex3f(0.3, 0.4, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.5, 0.0, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.5, 0.5, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 0.5, -2.0);

	}
	glEnd();
	glEndList();
	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.4, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.1, 0.4, -2.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.4, 0.0, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.5, 0.1, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.4, 0.2, -2.0);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.2, 0.3, -2.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.1, 0.4, -2.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		//rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glScalef(1.0f, 1.0001f, 1.000001f); //Scales the object depending on the axis defined.
	glTranslatef(0.0001f, 0.0f, 0.0f); //Moves the start location for drawing all points across to a new location using the origin as 0,0
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); //Spins the drawings around the axis defined by the float.
	cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

