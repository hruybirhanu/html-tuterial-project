#include <windows.h>

#include <GL/glut.h>






void init(){
    glClearColor(1,1,1,0);
    glColor3f(1,1,0);
    glPointSize(4);
    glLineWidth(4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,800);

}
void drawline(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(140,100);
    glVertex2f(200,100);
    glVertex2f(200,100);
    glVertex2f(200,300);
    glVertex2f(200,300);
    glVertex2f(300,300);
    glVertex2f(300,300);
    glVertex2f(300,350);
    glVertex2f(300,350);
    glVertex2f(200,350);
    glVertex2f(200,350);
    glVertex2f(200,500);
    glVertex2f(140,100);
    glVertex2f(140,300);
    glVertex2f(140,300);
    glVertex2f(40,300);
    glVertex2f(40,300);
    glVertex2f(40,350);
    glVertex2f(40,350);
    glVertex2f(140,350);
    glVertex2f(140,350);
    glVertex2f(140,500);
    glVertex2f(140,500);
    glVertex2f(200,500);
    glVertex2f(200,500);
    glVertex2f(170,450);
    glVertex2f(170,450);
    glVertex2f(140,500);
    glVertex2f(140,100);
    glVertex2f(170,150);
    glVertex2f(170,150);
    glVertex2f(200,100);




    glEnd();
    glFinish();


}
int main(){
glutInitWindowSize(800,800);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("computer graphics");
glutDisplayFunc(drawline);
init();
glutMainLoop();
return 0;

}
