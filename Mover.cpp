#include "Mover.h"


void Mover::draw(int shadow) {
	
	if (shadow)
		glColor3f(0.1f, 0.1f, 0.1f);
	else {
		glColor3f(1.0f, 0.0f, 0.0f);
		glLoadName(1);
	}
	
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glutSolidSphere(size, 30, 30);
	
}

void Mover::update(float duration) {

	if ((1 / m_mass) < 0.0f)return;
	cyclone::Vector3 f = cyclone::Vector3(0, 0, 0);
	cyclone::Vector3 resultingAcc = m_acc;
	resultingAcc.addScaledVector(f, 1 / m_mass);
	m_velocity.addScaledVector(resultingAcc, duration);
	m_position.addScaledVector(m_velocity, duration);

	checkEdges();
}

void Mover::checkEdges() {
	if (m_position.y <= (0 + size)) {
		m_velocity.y *= -1;
	}
}