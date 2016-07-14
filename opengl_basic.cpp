
//DDA

#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#define ROUND(a) ((int)(a+0.5))
using namespace std;
int cor_1, cor_2, cor_3, cor_4;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x, int y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void DDA(int cor_1, int cor_2, int cor_3, int cor_4)
{
	int dx, dy, step, offset = 250;
	dx = (cor_3 - cor_1);
	dy = (cor_4 - cor_2);
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	setPixel(offset + cor_3, offset + cor_4);
	for (int i = 0; i < step; i++)
	{
		cor_1 = cor_1 + dx / step;
		cor_2 = cor_2 + dy / step;
		cout << "cor_1 = " << cor_1 << "  cor_2 = " << cor_2 << "\n";
		setPixel(offset + ROUND(cor_1), offset + ROUND(cor_2));
	}
}
void display()
{
	setAxes();
	if (cor_1 < cor_3)
		DDA(cor_1, cor_2, cor_3, cor_4);
	else
		DDA(cor_3, cor_4, cor_1, cor_2);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> cor_1 >> cor_2 >> cor_3 >> cor_4;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}





//Bresenham's Line drawing Algorithm

#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int cor_1, cor_2, cor_3, cor_4;
int offset = 250;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x, int y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void bresenham(int cor_1, int cor_2,int cor_3,int cor_4)
{
	setPixel(offset + cor_1, offset + cor_2);
	int dx, dy, D;
	dx = abs(cor_3 - cor_1);
	dy = abs(cor_4 - cor_2);
	if (dx >dy)
	{
		int m = 2 * dy;
		D = m - dx;

		for (cor_1 = cor_1 + 1; cor_1 <= cor_3; cor_1++)
		{
			if (D > 0)
			{
				cor_2 = cor_2 + 1;
				setPixel(offset + cor_1, offset + cor_2);
				D = D + (m - 2 * dx);
			}
			else
			{
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m;
			}
		}
	}
	else if ((dx)<(dy))
	{
		int m = 2*dx;
		D = m - dy;
		for (cor_2 = cor_2 + 1; cor_2 < cor_4; cor_2++)
		{
			if (D > 0)
			{
				cor_1 = cor_1 + 1;
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m - 2 * dy;
			}
			else
			{
				setPixel(offset + cor_1, offset + cor_2);
				D = D + m;
			}
		}
	}
	else if (dx == dy&&(dx!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		glVertex2i(cor_3,cor_4);
		glEnd();
		glFlush();
	}
	else if ((dx == 0)&&(dy!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		for (int i = 0; i < 50; i++)
		{
			glVertex2i(cor_3, cor_4+i);
		}
		glEnd();
		glFlush();
	}
	else if ((dy == 0)&&(dx!=0))
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(cor_1, cor_2);
		for (int i = 0; i < 500; i++)
		{
			glVertex2i(cor_3 + i, cor_4);
		}
		glEnd();
		glFlush();
	}
	else
		exit(0);
}
void display()
{
	setAxes();
	if (cor_1 > cor_3)
		bresenham(offset+cor_3,offset+ cor_4,offset+ cor_1,offset+ cor_2);
	else
		bresenham(offset+cor_1,offset+ cor_2,offset+ cor_3,offset+ cor_4);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> cor_1 >> cor_2 >> cor_3 >> cor_4;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



//Midpoint Circle


#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#define offset 250
using namespace std;
int center_x, center_y,radius;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(int x, int y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(offset+x,offset+ y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void midCir(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

	while (x >= y)
	{
		setPixel(x + x0, y + y0);
		setPixel(y + x0, x + y0);
		setPixel(-x + x0, y + y0);
		setPixel(-y + x0, x + y0);
		setPixel(-x + x0, -y + y0);
		setPixel(-y + x0, -x + y0);
		setPixel(x + x0, -y + y0);
		setPixel(y + x0, -x + y0);
		y++;
		if (decisionOver2 <= 0)
		{
			decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
		}
		else
		{
			x--;
			decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
		}
	}
}
void display()
{
    	setAxes();
		midCir(center_x, center_y,radius);
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> center_x >> center_y>>radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}




//Parametric Circle


#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define offset 250
using namespace std;
GLfloat center_x, center_y, radius;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(d, e, f);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void setPixel(GLfloat x, GLfloat y)
{
	setDrawingColor(0.0, 255.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(offset + x, offset + y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0, 255.0, 255.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void param()
{
	for (GLfloat i =0; i<=360; i = i + 1)
	{
		GLfloat a = center_x + radius*GLfloat(cos(3.14*(i / (GLfloat)180)));
		GLfloat b = center_y + radius*GLfloat(sin(3.14*(i / (GLfloat)180)));
		cout << "a =" << a << " b = " << b<<"\n";
		//setDrawingColor(0.0, 255.0, 0.0);
		//glClear(GL_COLOR_BUFFER_BIT);
		setPixel(a, b);
		/*GLfloat c = center_x + radius*GLfloat(cos(3.14*((i +90)/ (GLfloat)180)));
		GLfloat d = center_y + radius*GLfloat(sin(3.14*((i +90)/ (GLfloat)180)));
		setDrawingColor(255, 0, 255);
		setPixel(c, d);
		GLfloat e = center_x + radius*GLfloat(cos(3.14*((i + 180) / (GLfloat)180)));
		GLfloat f = center_y + radius*GLfloat(sin(3.14*((i+180) / (GLfloat)180)));
		setDrawingColor(255, 0, 0);
		setPixel(e, f);
		GLfloat g = center_x + radius*GLfloat(cos(3.14*((i + 270) / (GLfloat)180)));
		GLfloat h = center_y + radius*GLfloat(sin(3.14*((i + 270) / (GLfloat)180)));
		setDrawingColor(0, 0, 255.0);
		setPixel(g, h);*/
	}
}
void display()
{
	setAxes();
	param();
}
int main(int argc, char **argv)
{
	cout << "Enter the coordinates\n";
	cin >> center_x >> center_y >> radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("OPENGL EXAMPLE 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}




//Midpoint Ellipse

#include<iostream>
#include<GL/glut.h>
#define offset 250
#define ROUND(a) ((int)(a+0.5))
int xCenter,yCenter,Rx , Ry;
void setDrawingColor(GLfloat d = 255.0, GLfloat e = 255.0, GLfloat f = 255.0)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(d, e, f);
}
void setPixel(int x, int y)
{
	setDrawingColor();
	glBegin(GL_POINTS);
	glVertex2i(offset+x, offset+y);
	glEnd();
	glFlush();
}
void setAxes()
{
	setDrawingColor(0.0,0.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(250, 250);
	glVertex2i(450, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 450);
	glVertex2i(250, 250);
	glVertex2i(250, 50);
	glVertex2i(250, 250);
	glVertex2i(50, 250);
	glEnd();
	glFlush();
}
void ellipseMidPoint(int xCenter, int yCenter, int Rx, int Ry)
{
	setAxes();
	int Rx2 = Rx*Rx;
	int Ry2 = Ry*Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2*y;
	void ellipsePlotPoints(int,int,int,int);
	ellipsePlotPoints(xCenter, yCenter, x, y);
	p = ROUND(Ry2 - (Rx2*Ry) + (0.25*Rx2));
	while (px < py)
	{
		x++;
		px += twoRy2;
		if (p < 0)
			p += Ry2 + px;
		else{
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}

	p = ROUND(Ry2*(x + 0.5)*(x + 0.5) + Rx2*(y - 1)*(y - 1) - Rx2*Ry2);
	while (y > 0)
	{
		y--;
		py -= twoRx2;
		if (p>0)
			p += Rx2 - py;
		else{
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
}
void ellipsePlotPoints(int xCenter, int yCenter, int  x, int y)
{
	setPixel(xCenter + x, yCenter + y);
	setPixel(xCenter - x, yCenter + y);
	setPixel(xCenter + x, yCenter - y);
	setPixel(xCenter - x, yCenter - y);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	ellipseMidPoint(xCenter,yCenter, Rx, Ry);
}
int main(int argc,char **argv)
{
	std::cout << "Enter the xCente, yCenter,rx and ry\n";
	std::cin >> xCenter >> yCenter >> Rx >> Ry;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



//Flood-Fill Algorithm

#include<GL/glut.h>

#include<stdio.h>

#include<math.h>


struct das
{
	
int x;
	int y;

} p[100000];


int top;

float oldcolor[3], fillcolor[3];


void push(int x, int y)
{

	top++;
	
if (top == 100000)

		exit(0);
	
p[top].x = x;

	p[top].y = y;

}


void pop(int *x, int *y)
{

	*x = p[top].x;
 *y = p[top].y;

	top--;

}


void setPixel(int x, int y)
{

	glColor3fv(fillcolor);

	glPointSize(10);

	glBegin(GL_POINTS);

	glVertex2f(x, y);

	glEnd();

	glFlush();

}


void floodfill(int x, int y)
{

	int xc, yc;

	push(x, y);

	float currentcolor[3];

	setPixel(x, y);


	while (top>0)
	{

		pop(&xc, &yc);

		glReadPixels(xc + 10, yc, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);

		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{

			setPixel(xc + 10, yc); push(xc + 10, yc);

		}


		glReadPixels(xc - 10, yc, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);

		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{

			setPixel(xc - 10, yc); push(xc - 10, yc);

		}


		glReadPixels(xc, yc + 10, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);

		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{

			setPixel(xc, yc + 10); push(xc, yc + 10);

		}


		glReadPixels(xc, yc - 10, 1.0, 1.0, GL_RGB, GL_FLOAT, currentcolor);

		if (currentcolor[0] == oldcolor[0] && currentcolor[1] == oldcolor[1] && currentcolor[2] == oldcolor[2])
		{

			setPixel(xc, yc - 10); push(xc, yc - 10);

		}
	
}

}




void drawPolygon()
{

	glColor3f(1.0, 1.0, 1.0);

	glLineWidth(10);

	glBegin(GL_LINES);

	glVertex2f(100, 100);

	glVertex2f(100, 400);

	glVertex2f(100, 400);

	glVertex2f(400, 400);

	glVertex2f(400, 400);

	glVertex2f(400, 100);

	glVertex2f(400, 100);

	glVertex2f(100, 100);

	glEnd();

	glFlush();

}


void init()
{

	glClearColor(0.0, 1.0, 1.0, 0.0);

	glLoadIdentity();

	gluOrtho2D(0, 500, 0, 500);

}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();

	drawPolygon();

	fillcolor[0] = 0.0; fillcolor[1] = 255.0; fillcolor[2] = 0.0;

	glReadPixels(300, 300, 1.0, 1.0, GL_RGB, GL_FLOAT, oldcolor);

	floodfill(300, 300);

}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(0, 0);

	glutCreateWindow(" ");

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;

}

