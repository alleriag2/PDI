#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <GL/freeglut.h>
#define PI 3.1415926
using namespace std;

float lado = 2.0;

float ladot = 4.0;

float raio = 2.257;
float quantity = 300;



void square(void)
{
	glBegin(GL_QUADS);
    /* green square */
    glVertex2f(-lado, lado);
    glVertex2f(-lado, -lado);
    glVertex2f(lado,-lado);
    glVertex2f(lado, lado);
    glEnd();
}

void circle(void)
{
    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; // posições x e y

    for (int i = 0; i < quantity; i++)
    {
        float t = (2.0f * PI * float(i)) / (float(100));
        float x = raio * cosf(t);
        float y = raio * sinf(t);
        if (i < 150)
        {
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(x + cx, y + cy);
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(x + cx, y + cy);
        }
    }
    glEnd();
}

void triangle(void)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(3 * ladot, ladot);
    glVertex2f(2 * ladot, 0.0);
    glVertex2f(4 * ladot, 0.0);

    glEnd();
}

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    //glTranslatef(12,12,0);Translated
    //glScalef(2,4,0);//Escala
    glRotatef(90,0,0,1);//Rotate
    

    //glScalef(1, -1, 1); // Reflexão no eixo Y
    circle();
    square();
    triangle();
    
    glFlush();
}


void backgroundDisplay() {
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void reshapeFigure(int width, int height){
    glViewport(0,0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25, 25, -25, 25);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Transformacao");

    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeFigure);
    backgroundDisplay();
    
    glutMainLoop();

    return 0; /* ANSI C requires main to return int. */
}

