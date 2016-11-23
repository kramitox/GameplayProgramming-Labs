#include "Game.h"

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), PRIMITIVES(10)
{
	index = glGenLists(PRIMITIVES);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

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
	pt1.Equals(customVector::Vector3(0,0,-2));
	pt2.Equals(customVector::Vector3(0.3, 0, -2));
	pt3.Equals(customVector::Vector3(0.3, 0.3, -2));
	pt4.Equals(customVector::Vector3(0.5, 0.4, -2));
	pt5.Equals(customVector::Vector3(0.2, 0.2, -2));
	pt6.Equals(customVector::Vector3(0, 0.5, -2));

	m1.Equals(pt1, pt2, pt3);
	m2.Equals(pt4, pt5, pt6);
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(1.0f, 1.0f, 1.0f);
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	

}

void Game::update()
{
	keyboardHandling();
	m1.Equals(m1 * m1.RotationZ(rotationAngle));
	m2.Equals(m2 * m2.RotationZ(rotationAngle));
	updateMatrix();
		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}

}

void Game::draw()
{
	//cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glScalef(1.0f, 1.0000f, 1.000000f); //Scales the object depending on the axis defined.
	//glTranslatef(0.0000f, 0.0f, 0.0f); //Moves the start location for drawing all points across to a new location using the origin as 0,0
	//glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); //Spins the drawings around the axis defined by the float.
	
	//cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}
void Game::updateMatrix()
{
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(pt1.getX()), GLfloat(pt1.getY()), GLfloat(pt1.getZ()));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(pt2.getX()), GLfloat(pt2.getY()), GLfloat(pt2.getZ()));
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(GLfloat(pt3.getX()), GLfloat(pt3.getY()), GLfloat(pt3.getZ()));
	}
	glEnd();
	glEndList();
	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(pt1.getX()), GLfloat(pt1.getY()), GLfloat(pt1.getZ()));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(pt2.getX()), GLfloat(pt2.getY()), GLfloat(pt2.getZ()));
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(pt3.getX()), GLfloat(pt3.getY()), GLfloat(pt3.getZ()));
	}
	glEnd();
	glEndList();
	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(pt1.getX()), GLfloat(pt1.getY()), GLfloat(pt1.getZ()));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(pt2.getX()), GLfloat(pt2.getY()), GLfloat(pt2.getZ()));


	}
	glEnd();
	glEndList();
	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
	}
	glEnd();
	glEndList();
	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(GLfloat(m2.A21), GLfloat(m2.A22), GLfloat(m2.A23));
	}
	glEnd();
	glEndList();
	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(GLfloat(m2.A21), GLfloat(m2.A22), GLfloat(m2.A23));
	}
	glEnd();
	glEndList();
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(GLfloat(m2.A21), GLfloat(m2.A22), GLfloat(m2.A23));
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m2.A31), GLfloat(m2.A32), GLfloat(m2.A33));
	}
	glEnd();
	glEndList();
	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));

	}
	glEnd();
	glEndList();
	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));
	}
	glEnd();
	glEndList();
	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A11), GLfloat(m1.A12), GLfloat(m1.A13));
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m1.A21), GLfloat(m1.A22), GLfloat(m1.A23));
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(GLfloat(m1.A31), GLfloat(m1.A32), GLfloat(m1.A33));
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(GLfloat(m2.A11), GLfloat(m2.A12), GLfloat(m2.A13));
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(GLfloat(m2.A21), GLfloat(m2.A22), GLfloat(m2.A23));
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(GLfloat(m2.A31), GLfloat(m2.A32), GLfloat(m2.A33));
	}
	glEnd();
	glEndList();

}
void Game::keyboardHandling()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pt1.setX(pt1.getX() + MOVE);
		pt2.setX(pt2.getX() + MOVE);
		pt3.setX(pt3.getX() + MOVE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pt1.setX(pt1.getX() - MOVE);
		pt2.setX(pt2.getX() - MOVE);
		pt3.setX(pt3.getX() - MOVE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pt1.setY(pt1.getY() - MOVE);
		pt2.setY(pt2.getY() - MOVE);
		pt3.setY(pt3.getY() - MOVE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pt1.setY(pt1.getY() + MOVE);
		pt2.setY(pt2.getY() + MOVE);
		pt3.setY(pt3.getY() + MOVE);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		current = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		current = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		current = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		current = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		current = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		current = 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		current = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		current = 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		current = 9;
	}

}
