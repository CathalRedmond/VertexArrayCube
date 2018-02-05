#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>

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

	bool transform{ false };
	Matrix3D m_matrix;

	float rotationAngle = 0.0f;

	float vertices[24];
	
	float colors[24] = { 1.0f,0.0f,0.0f,
						 0.0f,1.0f,0.0f,
						 0.0f,0.0f,1.0f,
					     1.0f,1.0f,0.0f,
		                 0.0f,1.0f,1.0f,
						 1.0f,0.0f,1.0f,
						 0.5f,0.5f,0.0f,
						 0.0f,0.0f,0.5f, };

	unsigned int vertex_index[36] = { 0,1,2,  0,2,3,
									  4,5,6,  4,6,7,
									  1,2,5,  2,5,6,
									  0,3,4,  3,4,7,
									  0,1,4,  1,4,5,
									  2,3,6,  3,6,7, };
	Vector3D cubeVertexPosition[8];

	
	


};