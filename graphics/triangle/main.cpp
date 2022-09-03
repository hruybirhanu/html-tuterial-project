
#include <windows.h>

#include <GL/glut.h>
#include <stdlib.h>
void init(){
    glClearColor(1,0,1,0);
    glColor3f(1,1,0);
    glPointSize(4);
    glLineWidth(4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);

}
void drawline(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
glVertex2f(100,100);
glVertex2f(300,100);

glVertex2f(100,400);
glVertex2f(300,100);

glVertex2f(100,100);
glVertex2f(100,400);

glVertex2f(50,50);
glVertex2f(50,80);

glVertex2f(35,80);
glVertex2f(65,80);



    glEnd();
    glFinish();


}
int main(){
glutInitWindowSize(650,480);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("computer graphics");
glutDisplayFunc(drawline);
init();
glutMainLoop();
return 0;

}
