#include<GL/glut.h>
#include<iostream>
using namespace std;
struct Point{
	GLint x;
	GLint y;
};
struct Color{
	GLfloat r,g,b;
};
void setDrawingColor(GLfloat d, GLfloat e, GLfloat f)
{
	glColor3f(d, e, f);
}
void init()
{
	glClearColor(1.0, 1.0, 1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLint x, GLint y,Color setColor)
{
	setDrawingColor(setColor.r, setColor.g, setColor.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0,1.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450,250);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
    glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glEnd();
	glFlush();
}
void DDA(Point a,Point b)
{
	Color myLineColor = { 1.0, 0.0, 0.0 };
	GLint x1 = a.x;
	GLint y1 = a.y;
	GLint x2 = b.x;
	GLint y2 = b.y;
	setPixel(x1, y1, myLineColor);
	setPixel(x2, y2, myLineColor);
	GLint dx = x2 - x1;
	GLint dy = y2 - y1;
	GLint steps=abs(dy);//ASSUMED
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	GLfloat incrx = dx / float(steps);
	GLfloat incry = dy / float(steps);
	for (GLint i = 0; i < steps; i++)
	{
		x1 = x1 + incrx;
		y1 = y1 + incry;
		setPixel(x1, y1, myLineColor);
	}
}
void drawSquare()
{
	Point a, b,c,d;
	a.x = a.y = 300;
	b.x = 400; b.y = 300;
	c.x = c.y = 400;
	d.x = 300; d.y = 400;
	DDA(a, b);
	DDA(b, c);
	DDA(c, d);
	DDA(d, a);
}
void boundaryFill(int x, int y,Color fill,Color boundary)
{
	Color current;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &current);
	cout << current.r << current.g << current.b<<"\n";
	cout << boundary.r << boundary.g << boundary.b << "\n";
	if (boundary.r == current.r&&boundary.g != current.g&&boundary.b != current.b)	{
		cout << "here\n";
		setPixel(x, y, fill);
		boundaryFill(x + 1, y, fill, boundary);
		boundaryFill(x - 1, y, fill, boundary);
		boundaryFill(x, y + 1, fill, boundary);
		boundaryFill(x, y - 1, fill, boundary);
		//boundaryFill(x+1, y + 1, fill, boundary);
		//boundaryFill(x-1, y + 1, fill, boundary);
		//boundaryFill(x+1, y - 1, fill, boundary);
		//boundaryFill(x-1, y -1, fill, boundary);
	}
}
void floodFill(int x,int y,Color fillColor,Color oldColor)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_FLOAT, GL_RGB, &color);
	if (color.r == oldColor.r&&color.g == oldColor.g&&color.b == oldColor.b){
		setPixel(x, y, fillColor);
		floodFill(x + 1, y, fillColor, oldColor);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setAxes();
	drawSquare();
	Color fill, boundary,old;
	boundary = { 1.0, 0.0, 0.0 };
	fill = { 0.0, 1.0, 0.0 };
	boundaryFill(350,350, fill, boundary);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
