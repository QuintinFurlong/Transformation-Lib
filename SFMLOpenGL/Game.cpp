#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"),
primatives(2),
topLeft(-2.0, 0.5, -5.0),
topRight(-1.0, 0.5, -5.0),
bottomRight(-1.0, -0.5, -5.0)
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

	Matrix3 m1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		topLeft =  m1.Rotation(1) * topLeft;
		topRight = m1.Rotation(1) * topRight;
		bottomRight = m1.Rotation(1) * bottomRight;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		topLeft = m1.Rotation(-1) * topLeft;
		topRight = m1.Rotation(-1) * topRight;
		bottomRight = m1.Rotation(-1) * bottomRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		topLeft = m1.Scale(99, 101) * topLeft;
		topRight = m1.Scale(99, 101) * topRight;
		bottomRight = m1.Scale(99, 101) * bottomRight;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		topLeft = m1.Scale(101, 99) * topLeft;
		topRight = m1.Scale(101, 99) * topRight;
		bottomRight = m1.Scale(101, 99) * bottomRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		topLeft = m1.Translate(.1,.1) * topLeft;
		topRight = m1.Translate(.1, .1) * topRight;
		bottomRight = m1.Translate(.1, .1) * bottomRight;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		topLeft = m1.Translate(-.1, -.1) * topLeft;
		topRight = m1.Translate(-.1, -.1) * topRight;
		bottomRight = m1.Translate(-.1, -.1) * bottomRight;
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);


	glBegin(GL_TRIANGLES); {
		glColor3f(.5, .5, 1);
		glVertex3f(topLeft.X(), topLeft.Y(), topLeft.Z());
		glVertex3f(topRight.X(), topRight.Y(), topRight.Z());
		glVertex3f(bottomRight.X(), bottomRight.Y(), bottomRight.Z());
	}
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}