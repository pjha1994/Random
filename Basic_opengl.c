//window

#include<GL/glut.h>
#include<stdio.h>

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glLoadIdentity();
glOrtho(0,500,0,500,-1,1);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (" Window Name ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop(); 
 return 0;
}
