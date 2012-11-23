#include "Triangle.h"
#include <GL/gl.h>
#include <GL/glu.h>

Triangle::Triangle() :
    m_angle(0.f),
    m_speed(50.f)
{
}

void Triangle::Update(float deltaTime)
{
    m_angle += deltaTime * m_speed;

    // Keeping the angle lower than 360 degrees
    if (m_angle > 360)
    {
        m_angle -= 360;
    }
}

void Triangle::Render()
{
    glPushMatrix();

    glRotatef(m_angle, 0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f( 0.5,  0.5, 0.0);
    glVertex3f( 0.0,  0.5, 0.0);
    glEnd();

    glPopMatrix();
}

