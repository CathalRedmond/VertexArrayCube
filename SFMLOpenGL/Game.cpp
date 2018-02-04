#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	int i = 0;
}

Game::~Game() {}

float vertices[] = { 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,-1.0f, -1.0f,
					 1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,-1.0f, 1.0f,
					 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,1.0f, 1.0f, 
					-1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,-1.0f, 1.0f,
					-1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f,1.0f, 1.0f,

					 1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f,1.0f, 1.0f };

float colors[] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
				   0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 
				   0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 
				   1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
				   1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
				   0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f };

unsigned int vertex_index[] = { 0, 1, 2, 3,
								4, 5, 6, 7, 
								8, 9, 10, 11, 
								12, 13, 14, 15, 
								16, 17, 18, 19, 
								20, 21, 22, 23, };

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

	if (transform)
	{
		for (int index = 0; index < 72; index += 3)
		{
			Vector3D vector(vertices[index], vertices[index + 1], vertices[index + 2]);
			vector = vector * m_matrix;

			vertices[index] = vector.Xf();

			vertices[index + 1] = vector.Yf();

			vertices[index + 2] = vector.Zf();
		}
		transform = false;
	}
	

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

