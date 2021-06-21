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

float convertion(float degrees){
	return (degrees * PI)/(180);
}

void square(void)
{
    glBegin(GL_QUADS);
    /* green square */
    glVertex2f(-lado, lado);
    glVertex2f(-lado, -lado);
    glVertex2f(lado, -lado);
    glVertex2f(lado, lado);
    glEnd();
}

void square_translated(float x, float y)
{
    glBegin(GL_QUADS); 
    /* green square */
    glVertex2f(-lado + x, lado + y);
    glVertex2f(-lado + x, -lado + y);
    glVertex2f(lado + x, -lado + y);
    glVertex2f(lado + x, lado + y);
    glEnd();
}

float * point_x_y(float x, float y, float converted){
	float * point = new float(2);
	point[0] = (x*cos(converted)) - (y*sin(converted));
	point[1] = (x*sin(converted)) + (y*cos(converted));
	
	return point;
}

void square_rotation(float d_converted)
{
    glBegin(GL_QUADS);

    //rotated coordinates
	float * square1 = point_x_y(-lado, lado, d_converted);
	float * square2 = point_x_y(-lado, -lado, d_converted);
	float * square3 = point_x_y(lado, -lado, d_converted);
	float * square4 = point_x_y(lado, lado, d_converted);
    /* green square */
    glVertex2f(-lado + square1[0], lado + square1[1]);
    glVertex2f(-lado + square2[0], -lado + square2[1]);
    glVertex2f(lado + square3[0], -lado + square3[1]);
    glVertex2f(lado + square4[0], lado + square4[1]);
    glEnd();
}

void square_scaled(float scaled_x)
{
    glBegin(GL_QUADS);
    /* green square */
    glVertex2f(-lado * scaled_x, lado * scaled_x);
    glVertex2f(-lado * scaled_x, -lado * scaled_x);
    glVertex2f(lado * scaled_x, -lado * scaled_x);
    glVertex2f(lado * scaled_x, lado * scaled_x);
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
        
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void circle_translated(float tx,float ty)
{
    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; 

    for (int i = 0; i < quantity; i++)
    {
        float t = (2.0f * PI * float(i)) / (float(100));
        float x = raio * cosf(t);
        float y = raio * sinf(t);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x + cx + tx, y + cy + ty);
    }
    glEnd();
}

void circle_rotation(float d_converted)
{
    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; // center pos x e y
    

    for (int i = 0; i < quantity; i++)
    {
        float t = (2.0f * PI * float(i)) / (float(100));
        float x = raio * cosf(t);
        float y = raio * sinf(t);
        
        //rotated coordinates
    	float new_x = ((x+cx)*cos(d_converted)) - ((y+cy)*sin(d_converted));
		float new_y = ((x+cx)*sin(d_converted)) + ((y+cy)*cos(d_converted));
        //draw
		glVertex2f(x + cx + new_x, y + cy + new_y);
        
        new_x, new_y = 0;
    }
    glEnd();
}

void circle_scaled(float scaled_x,float scaled_y)
{
    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; 

    for (int i = 0; i < quantity; i++)
    {
        float t = (2.0f * PI * float(i)) / (float(100));
        float x = raio * cosf(t);
        float y = raio * sinf(t);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f((x + cx) * scaled_x, (y + cy) * scaled_y);
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

void triangle_translated(float tx, float ty)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(3 * ladot + tx, ladot + ty);
    glVertex2f(2 * ladot + tx, 0.0 + ty);
    glVertex2f(4 * ladot + tx, 0.0 + ty);

    glEnd();
}

void triangle_rotation(float d_converted)
{  
    //rotated
    float * ladot1 = point_x_y(3*ladot, ladot, d_converted);
    float * ladot2 = point_x_y(2*ladot, 0, d_converted);
    float * ladot3 = point_x_y(4*ladot, 0, d_converted);
    
    glBegin(GL_TRIANGLES);

    glVertex2f(3 * ladot + ladot1[0], ladot + ladot1[1]);
    glVertex2f(2 * ladot + ladot2[0], ladot2[1]);
    glVertex2f(4 * ladot + ladot3[0], ladot2[1]);

    glEnd();
}

void triangle_scaled(float scale_x)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(3 * ladot * scale_x, ladot * scale_x);
    glVertex2f(2 * ladot * scale_x, 0.0);
    glVertex2f(4 * ladot * scale_x, 0.0);

    glEnd();
}

void rotation(float degrees){
	//rotation
	
	float c_degrees = convertion(degrees);
    square_rotation(c_degrees);
    circle_rotation(c_degrees);
    triangle_rotation(c_degrees);
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glScalef(1, -1, 1); // Reflexão no eixo Y
    
	//circle();
    //square();
    //triangle();
	
	//translation
    //square_translated(5,5);
    //circle_translated(5,5);
    //triangle_translated(5,5);
    
    //Scale
    //circle_scaled(2, 2);
    //square_scaled(2.0);
    //triangle_scaled(2.0);
    
    
    //rotation
    rotation(30);
	
    glFlush();
}

void backgroundDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void reshapeFigure(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Scaled");

    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeFigure);
    backgroundDisplay();

    glutMainLoop();

    return 0; 
}
