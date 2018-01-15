#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"),
primatives(2),
topLeft(-2.0, 0.5, -5.0),
topRight(-1.0, 0.5, -5.0),
bottomRight(-1.0, -0.5, -5.0),
bottomLeft(-2.0, -0.5, -5.0)
{
}

Game::~Game() {}

void Game::run()
{
	srand(time(nullptr));
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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x /
		window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	isRunning = true;
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
}

void Game::update()
{
	cout << "Update up" << endl;
	rotationAngle = 0.01;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//positive x, move right
	{
		glTranslatef(0.001f, 0.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//negative x, move left
	{
		glTranslatef(-0.001f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//positive y, move up
	{
		glTranslatef(0.0f, 0.001f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//negative y, move down
	{
		glTranslatef(0.0f, -0.001f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))//positive z, move out
	{
		glTranslatef(0.0f, 0.0f, 0.001f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))//negative z, move in
	{
		glTranslatef(-0.0f, 0.0f, -0.001f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		glRotatef(rotationAngle, -1.0f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glRotatef(rotationAngle, 0.0f, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, -1.0f);
	}
			
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		glScalef(1.0001f, 1.0f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		glScalef(0.9999f, 1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		glScalef(1.0f, 1.0001f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		glScalef(1.0f, 0.9999f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		glScalef(1.0f, 1.0f, 1.0001f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		glScalef(1.0f, 1.0f, 0.9999f);
	}
	Matrix3 m1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		topLeft =  m1.RotationZ(1) * topLeft;
		topRight = m1.RotationZ(1) * topRight;
		bottomRight = m1.RotationZ(1) * bottomRight;
		bottomLeft = m1.RotationZ(1) * bottomLeft;
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);


	glBegin(GL_QUADS); {
		glColor3f(.5, .5, 1);
		glVertex3f(topLeft.X(), topLeft.Y(), topLeft.Z());
		glVertex3f(topRight.X(), topRight.Y(), topRight.Z());
		glVertex3f(bottomRight.X(), bottomRight.Y(), bottomRight.Z());
		glVertex3f(bottomLeft.X(), bottomLeft.Y(), bottomLeft.Z());
	}
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}