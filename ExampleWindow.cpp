#include <cmath>
#include "ExampleWindow.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

static constexpr double Pi = 3.14;

ExampleWindow::ExampleWindow(int width, int height)
: Window(800, 600)
{
	_angle = 0.;
	_eye_level = 0.;
}

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
    glEnd();
}

void cube(){
    glBegin(GL_QUADS);
	
    glColor3d(0.7, 0.5, 0.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	
    glColor3d(0.0, 0.5, 0.2);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	
    glColor3d(0.0, 1.0, 0.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(1.0, 1.0, 1.0);
	
    glColor3d(1.0, 1.0, 0.0);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
    
    glColor3d(1.0, 0.0, 0.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(-1.0, -1.0, 1.0);
    
    glColor3d(0.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	glEnd();
}

void ExampleWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
            5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);
    glRotated(_angle, 0.0, 0.0, 1.0);
    glScaled( 0.4, 0.4, 0.4 );
    glPushMatrix();
    glTranslated(0.0, 0.0, -1.0);
    cube();
    glTranslated(-2.5, 0.0, 0.0);
    cube();
    glTranslated(5.0, 0.0, 0.0);
    cube();
    glTranslated(-1.0, 0.0, 2.0);
    cube();
    glTranslated(-2.5, 0.0, 0.0);
    cube();
    glTranslated(1.25, 0.0, 2.0);
    cube();
    glPopMatrix();
}

void ExampleWindow::handle_logic()
{
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

    _eye_level = sin(_angle / 180. * Pi);
}
