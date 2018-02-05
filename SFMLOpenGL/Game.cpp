#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	 cubeVertexPosition[0] = Vector3D(1.0, 1.0, -2.0);
	 cubeVertexPosition[1] = Vector3D(-1.0, 1.0, -2.0);
	 cubeVertexPosition[2] = Vector3D(-1.0, -1.0, -2.0);
	 cubeVertexPosition[3] = Vector3D(1.0, -1.0, -2.0);
	 cubeVertexPosition[4] = Vector3D(1.0, 1.0, -4.0);
	 cubeVertexPosition[5] = Vector3D(-1.0, 1.0, -4.0);
	 cubeVertexPosition[6] = Vector3D(-1.0, -1.0, -4.0);
	 cubeVertexPosition[7] = Vector3D(1.0, -1.0, -4.0);


	 for (int index = 0; index < 8; index ++)
	 {
		 vertices[index * 3] = cubeVertexPosition[index].Xf();
		 vertices[(index * 3) + 1] = cubeVertexPosition[index].Yf();
		 vertices[(index * 3) + 2] = cubeVertexPosition[index].Zf();
	 }
}

Game::~Game() {}







void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					m_matrix = m_matrix.translate(0.1, 0.0);
					transform = true;
					break;
				case sf::Keyboard::S:
					m_matrix = m_matrix.translate(0.0, 0.1);
					transform = true;
					break;
				case sf::Keyboard::A:
					m_matrix = m_matrix.translate(0.1, 0.0);
					transform = true;
					break;
				case sf::Keyboard::D:
					m_matrix = m_matrix.translate(-0.1, 0.0);
					transform = true;
					break;
				case sf::Keyboard::Z:
					m_matrix = m_matrix.rotationZ(2);
					transform = true;
					break;
				case sf::Keyboard::X:
					m_matrix = m_matrix.rotationZ(-2);
					transform = true;
					break;
				case sf::Keyboard::C:
					m_matrix = m_matrix.rotationY(2);
					transform = true;
					break;
				case sf::Keyboard::V:
					m_matrix = m_matrix.rotationY(-2);
					transform = true;
					break;
				case sf::Keyboard::B:
					m_matrix = m_matrix.rotationX(2);
					transform = true;
					break;
				case sf::Keyboard::N:
					m_matrix = m_matrix.rotationX(-2);
					transform = true;
					break;
				case sf::Keyboard::F:
					m_matrix = m_matrix.scale(110, 110);
					transform = true;
					break;
				case sf::Keyboard::G:
					m_matrix = m_matrix.scale(90, 90);
					transform = true;
					break;
				default:
					break;
				}
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0f,0.0f,-10.0f);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();



	Vector3D centre;
	for (int index = 0; index < 8; index++)
	{
		centre = centre + cubeVertexPosition[index];
	}
	centre = centre * (1 / 8.0);

	if (transform)
	{
		for (int index = 0; index < 8; index++)
		{
			cubeVertexPosition[index] = ((cubeVertexPosition[index] - centre) * m_matrix) + centre;
			vertices[index * 3] = cubeVertexPosition[index].Xf();
			vertices[(index * 3) + 1] = cubeVertexPosition[index].Yf();
			vertices[(index * 3) + 2] = cubeVertexPosition[index].Zf();
		}
		transform = false;
	}
	

}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);


	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

