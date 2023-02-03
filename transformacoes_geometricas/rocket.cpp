/*
    Aluno: Igor Carvalho da Silva  
    Email: igor.carvalho@icomp.ufam.edu.br
*/
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>

void bico(){
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(3.0f,6.0f,0.0f);
    glVertex3f(4.0f,8.0f,0.0f);
    glVertex3f(5.0f,6.0f,0.0f);
    glEnd();
}

void corpo(){
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex3f(3.0f,1.0f,0.0f);
    glVertex3f(5.0f,1.0f,0.0f);
    glVertex3f(5.0f,6.0f,0.0f);
    glVertex3f(3.0f,6.0f,0.0f);
    glEnd();
}

void asaEsquerda(){
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(1.5f,1.0f,0.0f);
    glVertex3f(3.0f,1.0f,0.0f);
    glVertex3f(3.0f,3.0f,0.0f);
    glEnd();
}

void asaDireita(){
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(5.0f,1.0f,0.0f);
    glVertex3f(6.5f,1.0f,0.0f);
    glVertex3f(5.0f,3.0f,0.0f);
    glEnd();
}

void foguete(){
    bico();
    corpo();
    asaEsquerda();
    asaDireita();
}

void desenhaFoguete(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    foguete();
    glFlush();
}

void display(){
    glTranslatef(-30.0f,-30.0f,0.0f);
    for(float i = 1; i <= 180; i++){
        glRotatef(-0.925, 0.0f, 0.0f, 1.0f);
        // glPushMatrix();
        glTranslatef(0.0002f, 0.5f, 0.0f);
        desenhaFoguete();
        // glPopMatrix();
        usleep(20000);
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(980, 740);
    glutCreateWindow("Rocket");
    glOrtho(-30, 30, -30, 30, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
};
