#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3D.h>
#include <Matrix3D.h>

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
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	Vector3D cubeVertexPositions[8];
	bool transform{ false };
	Matrix3D m_matrix;
	Vector3D colours[6];

	float rotationAngle = 0.0f;
};