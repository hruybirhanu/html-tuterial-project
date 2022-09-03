#include <windows.h>
#include <GL/glut.h>
void init(){
    glClearColor(1,0,1,0);
    glColor3f(0,1,0);
    glLineWidth(4);
    glPointSize(4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);

}

void drawline(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    glVertex2f(190,200);
   glVertex2f(150,300);


    glVertex2f(250,300);
    glVertex2f(150,300);


    glVertex2f(290,200);
    glVertex2f(190,200);



    glVertex2f(290,200);
    glVertex2f(250,300);


    glVertex2f(190,200);
    glVertex2f(190,100);


    glVertex2f(290,200);
    glVertex2f(290,100);



    glVertex2f(150,300);
    glVertex2f(150,190);


    glVertex2f(150,190);
    glVertex2f(190,100);


    glVertex2f(190,100);
    glVertex2f(290,100);
  glEnd();
    glFinish();
}
int main(){
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("com. Graphics");
   glutDisplayFunc(drawline);
    init();
    glutMainLoop();
    return 0;

}
