
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
glVertex2f(100,200);
glVertex2f(100,100);
glVertex2f(200,100);
glVertex2f(100,200);
glVertex2f(150,250);
glVertex2f(250,150);
glVertex2f(250,250);
glVertex2f(150,250);
glVertex2f(250,250);

glVertex2f(250,250);
glVertex2f(200,200);

glVertex2f(200,200);
glVertex2f(100,200);

glVertex2f(150,250);
glVertex2f(150,150);

glVertex2f(200,100);
glVertex2f(200,200);

glVertex2f(250,250);
glVertex2f(150,250);

glVertex2f(150,150);
glVertex2f(250,150);

glVertex2f(100,100);
glVertex2f(100,200);

glVertex2f(100,100);
glVertex2f(150,150);

glVertex2f(200,100);
glVertex2f(250,150);



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
