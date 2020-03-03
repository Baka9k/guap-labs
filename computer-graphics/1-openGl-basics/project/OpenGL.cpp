// Программа рисует цилиндр с помощью freeglut

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>


#define PI 3.1415927



// Нарисовать цилиндр
void draw_cylinder(
	GLfloat radius,   // радиус цилиндра
    GLfloat height,   // высота цилиндра
    GLubyte R,        // RGB цвет цилиндра
    GLubyte G,
    GLubyte B
) {

    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    // Нарисовать боковые стенки цилиндра
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        glVertex3f(x, y , 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    // Нарисовать верхнюю грань цилиндра
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();

}


// Вывести изображение
void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-40, 1.0, 0.0, 0.0);

    draw_cylinder(0.3, 1.0, 255, 160, 100);

    glFlush();

}

// Функция, вызываемая в случае изменения размера окна
void reshape(int width, int height) {

    if (width == 0 || height == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);

}


int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Draw cylinder");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;

}
