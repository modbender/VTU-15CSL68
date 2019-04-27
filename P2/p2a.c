#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLfloat tris[3][3]={{0,0,0},{100,0,0},{50,100,0}};
GLfloat rotangle;

void drawtris(){
    glBegin(GL_LINE_LOOP);
    glVertex3fv(tris[0]);
    glVertex3fv(tris[1]);
    glVertex3fv(tris[2]);
    glEnd(); 
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(rotangle,0.0,0.0,1.0);
    glColor3f(0,1,0);
    drawtris();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1,0,0);
    drawtris();
    glFlush();
}
void init(){
    glClearColor(0.2,0.8,0.8,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,500,-100,500);
}
int main(int argc,char **argv){
    printf("\nEnter the rotation angle: ");
    scanf("%f",&rotangle);
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Triangle rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

