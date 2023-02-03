/*
    Aluno: Igor Carvalho da Silva  
    Email: igor.carvalho@icomp.ufam.edu.br
*/
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void drawHouse(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8f, 0.0f, 0.003f); 
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.0f, 0.8f);
    glEnd();

    glColor3f(1.0f, 0.7f, 0.0f); 
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(-0.8f,-0.8f);
    glEnd();

    glColor3f(0.003f, 0.0f, 0.788f); 
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.3f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
    glEnd();


    glColor3f(0.0f, 0.69f, 0.49f);
    glBegin(GL_QUADS);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.7f,-0.1f);
    glVertex2f(0.7f, -0.4f);
    glVertex2f(0.3f, -0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(741, 741);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My Object");
    glutDisplayFunc(drawHouse);
    glutMainLoop();
};
