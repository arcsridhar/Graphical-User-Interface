#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLineWidth(4.0);
    glPointSize(2.0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1,1,1,-1,-1,-1);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}

void GLobj::ngon(int n)
{
    float degree, vertx, verty, rotate, degToRad;
    rotate = 360.0/n;
    degree = rotate/2 + 180;
    degToRad = 180/3.14159;
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++, degree += rotate)
    {
        if(n == 5)
        {
            vertx = 0.2 * sin(degree/degToRad);
            verty = 0.2 * sin((90 - degree)/degToRad);
            glVertex3f(vertx-0.30, verty-0.30, 1);

        }
        else if(n == 6)
        {
            vertx = 0.2 * sin(degree/degToRad);
            verty = 0.2 * sin((90 - degree)/degToRad);
            glVertex3f(vertx+0.5, verty+0.5, 0);
        }
        else if(n == 8)
        {
            vertx = 0.2 * sin(degree/degToRad);
            verty = 0.2 * sin((90 - degree)/degToRad);
            glVertex3f(vertx-0.45, verty+0.45, 0);
        }
        else if(n == 100)
        {
            vertx = 0.2 * sin(degree/degToRad);
            verty = 0.2 * sin((90 - degree)/degToRad);
            glVertex3f(vertx+0.2, verty-0.6, 0);
        }
    }

    glEnd();
}


//Paints the GL scene
void GLobj::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();
    //Draw points
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glColor3f (1.0, 1.5, 0.5);
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.9, 0.5);
    glEnd();

    //Draw Line
    glLoadIdentity();
    glLineWidth(4.0);
    glTranslatef(0.3,-0.2, 0);
    glBegin(GL_LINES);
    glColor3f (1.5, 0.5, 0.5);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.2, -0.2);
    glEnd();


    //Draw Pentagon
    glLoadIdentity();
    glColor3f(1, 0.5, 0.5);
    ngon(5);
    glEnd();

    //Draw Hexagon
    glLoadIdentity();
    glColor3f(0, 1.5, 1);
    ngon(6);
    glEnd();

    // Draw Octagon
    glLoadIdentity();
    glColor3f(0, 0.5, 0.5);
    ngon(8);
    glEnd();

    //Draw Circle
    glLoadIdentity();
    glColor3f(0, 1, 0);
    ngon(100);
    glEnd();

    // Draw Square
    glLoadIdentity();
    glTranslatef(0.6,-0.6, 0);
    glBegin(GL_POLYGON);
    glColor3f (1, 0.5, 0);
    glVertex3f(-0.1, -0.1,  0.1);
    glVertex3f( 0.1, -0.1,  0.1);
    glVertex3f( 0.1,  0.1,  0.1);
    glVertex3f(-0.1,  0.1,  0.1);
    glEnd();

    // Draw triangle
    glLoadIdentity();
    glColor3f(1.0, 1.0, 0.0); // Color (RGB): Yellow
    glLineWidth(3.0); // Set line width to 2.0
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.4, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.6, -0.6);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.6, -0.4);
    glEnd();


    //Draw a CUBE
    glLoadIdentity();

    glRotatef(45, 0, 1, 1);
    glTranslatef(0.1,-0.1, 0);

    glBegin(GL_QUADS);
    // Red for the 1st side
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.2f, 0.2f,-0.2f);
    glVertex3f(-0.2f, 0.2f,-0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f( 0.2f, 0.2f, 0.2f);
    // Orange for the 2nd side
    glColor3f(1.0f,0.5f,0.0f);
    glVertex3f( 0.2f,-0.2f, 0.2f);
    glVertex3f(-0.2f,-0.2f, 0.2f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f( 0.2f,-0.2f,-0.2f);
    // Yellow for the 3rd side
    glColor3f (1.0f,1.0f,0.0f);
    glVertex3f( 0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f,-0.2f, 0.2f);
    glVertex3f( 0.2f,-0.2f, 0.2f);
    // Light Magenta for 4th side
    glColor3f (2.0,  0.0, 0.5);
    glVertex3f( 0.2f,-0.2f,-0.2f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f(-0.2f, 0.2f,-0.2f);
    glVertex3f( 0.2f, 0.2f,-0.2f);
    // Blue for the 5th side
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f,-0.2f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f(-0.2f,-0.2f, 0.2f);
    // Green for the 6th side
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 0.2f, 0.2f,-0.2f);
    glVertex3f( 0.2f, 0.2f, 0.2f);
    glVertex3f( 0.2f,-0.2f, 0.2f);
    glVertex3f( 0.2f,-0.2f,-0.2f);

    glEnd();


    glFlush ();
}
