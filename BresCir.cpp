#include<GL/glut.h>
#include<iostream>
using namespace std; 
int radius;
void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glOrtho(-500,500,500,-500,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}
void drawPoints(int x,int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);
        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);
    glEnd();
}
void Circle()
{
    MyInit();
 
    int x=0, y=radius;
    drawPoints(x,y);
    int d = 3-2*radius;
     
    while(x<=y)
    {
        if(d < 0)
        {
            x = x+1;
            d = d + 4*x +6;
        }
        else if(d>=0)
        {
            x = x+1;
            y = y-1;
            d = d + 4*(x-y) + 10;
        }
 
        drawPoints(x,y);
    }
 
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Bresenham Circle");
     
    cout<<"Enter the radius of Circle:";
    cin>>radius;
    glutDisplayFunc(Circle);    
    glutMainLoop();
    return 0;
}

