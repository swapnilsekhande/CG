#include<GL/glut.h>
#include<iostream>
using namespace std;
int x1,y1,x2,y2;
void init() {
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display() {
    glBegin(GL_POINTS);
int dx,dy,steps;
dx=x2-x1;
dy=y2-y1;
if(dx>dy) {
    steps=dx;
} else {
    steps=dy;
}

int xincr = dx/steps;
int yincr = dy/steps;
int x, y;
x = x1;
y = y1;
for(int i=0; i<steps;i++) {
    x = x+xincr;
    y = y+yincr;
    glVertex2i(x,y);
}

    


    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    cout << "Enter x1, y1, x2, y2" <<endl;
    cin>>x1>>y1>>x2>>y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}