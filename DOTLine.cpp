#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const float PI=3.14;
void drawLine(int x0,int y0,int x1,int y1)
{
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);   
    double m=(double)(y1-y0)/(x1-x0);       
    double y=(double)y0;
    double x=(double)x0;
    if(m<1)    
    {       
        while(x<=x1)        
        {
            glVertex2d(x,floor(y));
            cout << floor(y);
            cout << x;
            y=y+m;
            x++;
        }
    }
    else   
     {
        double m1=1/m;
        while(y<=y1)       
         {
            glVertex2d(floor(x),y);           
            y++;
            x=x+m1;
        }
    }
    glEnd();
}

void init(void)
{   
    glClearColor(0.0,0.0,0.0,0.0);   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100,0.0,100.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(20,30,90,80);   
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("DDA Line Drawing!");
    init();
    glutDisplayFunc(display);   
    glutMainLoop();
    return 0;
}

