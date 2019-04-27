#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLfloat tri[3][3]={{100,100,0},{200,100,0},{150,200,0}};
GLfloat rot_angle,arb_x=100,arb_y=100;

void drawtri(){
    glBegin(GL_LINE_LOOP);
    glVertex3fv(tri[0]);
    glVertex3fv(tri[1]);
    glVertex3fv(tri[2]);
    glEnd(); 
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(arb_x,arb_y,0.0);
    glRotatef(rot_angle,0.0,0.0,1.0);
    glTranslatef(-arb_x,-arb_y,0.0);
    glColor3f(0,1,0);
    drawtri();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1,0,0);
    drawtri();
	glFlush();
}
void init(){
    glClearColor(0.2,0.8,0.8,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,500,-100,500);
}
int main(int argc,char **argv){
    printf("\nEnter the rotation angle : ");
    scanf("%f",&rot_angle);
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Triangle rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
