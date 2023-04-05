#pragma once
#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include "core.h"

class Mover
{
public:
	Mover() {
		size = 2.0f;
		m_position = cyclone::Vector3(5, 20, 0);
		m_velocity = cyclone::Vector3(0, 0, 0);
		m_acc = cyclone::Vector3(0, -9.8, 0);
		m_mass = 1.0;
		damping = 0.99;
	};
	~Mover() {};
	
	float size;
	cyclone::Vector3 m_position;
	cyclone::Vector3 m_velocity;
	cyclone::Vector3 m_acc;
	float m_mass;
	float damping;

	void update(float duration);
	void stop();
	void draw(int shadow);
	void checkEdges();
	
};
