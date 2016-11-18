#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

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
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	//cout << "Update up" << endl;
}

void Game::draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f); 
		glVertex3f(-0.8, -0.5, -2.0);
		glVertex3f(-0.7, -0.5, -2.0);
		glVertex3f(-0.75,-0.3, -2.0);
	}
	glEnd();
	glBegin(GL_POINTS);
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.8, -0.2, -2.0);
		glVertex3f(-0.7, -0.2, -2.0);
		glVertex3f(-0.6, -0.2, -2.0);
	}
	glEnd();
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.8, -0.1, -2.0);
		glVertex3f(-0.7, -0.1, -2.0);
		
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.8, -0.1, -2.0);
		glVertex3f(-0.7, -0.1, -2.0);
		glVertex3f(-0.65, -0.2, -2.0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.8, -0.0, -2.0);
		glVertex3f(-0.7, -0.0, -2.0);
		glVertex3f(-0.65, -0.1, -2.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.8, 0.1, -2.0);
		glVertex3f(-0.7, 0.1, -2.0);
		glVertex3f(-0.65, 0.2, -2.0);
		glVertex3f(-0.7, 0.2, -2.0);
		glVertex3f(-0.8, 0.2, -2.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.8, 0.3, -2.0);
		glVertex3f(-0.7, 0.3, -2.0);
		glVertex3f(-0.65, 0.4, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.7, 0.4, -2.0);
		glVertex3f(-0.8, 0.4, -2.0);
		glVertex3f(-0.65, 0.5, -2.0);
	}
	glEnd();
	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.4, -0.5, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.2, -0.5, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.2, -0.3, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.4, -0.3, -2.0);

	}
	glEnd();
	
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.4, -0.1, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.2, -0.1, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.2, -0.2, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.4, -0.2, -2.0);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-0.4, 0.1, -2.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.2, 0.1, -2.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.2, 0.2, -2.0);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.4, 0.2, -2.0);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-0.4, 0.3, -2.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.3, 0.3, -2.0);
	}
	window.display();
	//cout << "Draw up" << endl;
}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

