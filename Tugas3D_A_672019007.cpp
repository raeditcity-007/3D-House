#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
//Radithya Airlangga-672019007
//Tugas 3D Grafika Komputer A (Asisten)
void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 150);
    glutCreateWindow("Radithya Airlangga-672019007");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glViewport(10, 10, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);//Lantai coklat
    glColor3f(0.29, 0.2, 0);
    glVertex3f(-60, 0.0, 50.0);
    glVertex3f(80, 0.0, 50.0);
    glVertex3f(80, 0.0, -80.0);
    glVertex3f(-60, 0.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//Lantai hijau
    glColor3f(0.04, 0.6, 0.05);
    glVertex3f(80, 0.0, 60.0);
    glVertex3f(-60, 0.0, 60.0);
    glVertex3f(-60, 0.0, 50.0);
    glVertex3f(80, 0.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Lantai coklat
    glColor3f(0.56, 0.5, 0.02);
    glVertex3f(0, 0.5, 0.0);
    glVertex3f(60, 0.5, 0.0);
    glVertex3f(60, 0.5, 50.0);
    glVertex3f(0, 0.5, 50.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.25, 0.21, 0.02);
    glVertex3f(0.0, 0.5, 10.0);
    glVertex3f(60.0, 0.5, 10.0);
    glVertex3f(0.0, 0.5, 20.0);
    glVertex3f(60.0, 0.5, 20.0);
    glVertex3f(0.0, 0.5, 30.0);
    glVertex3f(60.0, 0.5, 30.0);
    glVertex3f(0.0, 0.5, 40.0);
    glVertex3f(60.0, 0.5, 40.0);
    glVertex3f(0.0, 0.5, 50.0);
    glVertex3f(60.0, 0.5, 50.0);
    //s
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, 0.5, 50.0);
    glVertex3f(10.0, 0.5, 0.0);
    glVertex3f(10.0, 0.5, 50.0);
    glVertex3f(20.0, 0.5, 0.0);
    glVertex3f(20.0, 0.5, 50.0);
    glVertex3f(30.0, 0.5, 0.0);
    glVertex3f(30.0, 0.5, 50.0);
    glVertex3f(40.0, 0.5, 0.0);
    glVertex3f(40.0, 0.5, 50.0);
    glVertex3f(50.0, 0.5, 0.0);
    glVertex3f(50.0, 0.5, 50.0);
    glVertex3f(60.0, 0.5, 0.0);
    glVertex3f(60.0, 0.5, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Lantai abu
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0, 0.5, -40.0);
    glVertex3f(-60, 0.5, -40.0);
    glVertex3f(-60, 0.5, 50.0);
    glVertex3f(0, 0.5, 50.0);
    glEnd();
    glBegin(GL_QUADS);//atap besi
    glColor3f(0.53, 0.53, 0.53);
    glVertex3f(0, 60.5, -80.0);
    glVertex3f(-60, 60.5, -80.0);
    glVertex3f(-60, 60.5, 50.0);
    glVertex3f(0, 60.5, 50.0);
    glVertex3f(0, 60, -80.0);
    glVertex3f(-60, 60, -80.0);
    glVertex3f(-60, 60, 50.0);
    glVertex3f(0, 60, 50.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.27, 0.27, 0.27);
    glVertex3f(-5.0, 0.5, -40.0);
    glVertex3f(-5.0, 0.5, 50.0);
    glVertex3f(-10.0, 0.5, -40.0);
    glVertex3f(-10.0, 0.5, 50.0);
    glVertex3f(-15.0, 0.5, -40.0);
    glVertex3f(-15.0, 0.5, 50.0);
    glVertex3f(-20.0, 0.5, -40.0);
    glVertex3f(-20.0, 0.5, 50.0);
    glVertex3f(-25.0, 0.5, -40.0);
    glVertex3f(-25.0, 0.5, 50.0);
    glVertex3f(-30.0, 0.5, -40.0);
    glVertex3f(-30.0, 0.5, 50.0);
    glVertex3f(-35.0, 0.5, -40.0);
    glVertex3f(-35.0, 0.5, 50.0);
    glVertex3f(-40.0, 0.5, -40.0);
    glVertex3f(-40.0, 0.5, 50.0);
    glVertex3f(-45.0, 0.5, -40.0);
    glVertex3f(-45.0, 0.5, 50.0);
    glVertex3f(-50.0, 0.5, -40.0);
    glVertex3f(-50.0, 0.5, 50.0);
    glVertex3f(-55.0, 0.5, -40.0);
    glVertex3f(-55.0, 0.5, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Lantai rumput
    glColor3f(0.02, 0.56, 0.09);
    glVertex3f(80, 0.5, -40.0);
    glVertex3f(60, 0.5, -40.0);
    glVertex3f(60, 0.5, 50.0);
    glVertex3f(80, 0.5, 50.0);
    glEnd();

    glBegin(GL_QUADS);//Pagar
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(-10, 0.0, 50.0);
    glVertex3f(10, 0.0, 50.0);
    glVertex3f(10, 35.0, 50.0);
    glVertex3f(-10, 35.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Pagar hijau
    glColor3f(0, 0.75, 0.21);
    glVertex3f(-10, 0.0, 50.1);
    glVertex3f(10, 0.0, 50.1);
    glVertex3f(10, 35.0, 50.1);
    glVertex3f(-10, 35.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);//Pagar
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(65, 0.0, 50.0);
    glVertex3f(80, 0.0, 50.0);
    glVertex3f(80, 35.0, 50.0);
    glVertex3f(65, 35.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Pagar hijau
    glColor3f(0, 0.75, 0.21);
    glVertex3f(65, 0.0, 50.1);
    glVertex3f(80, 0.0, 50.1);
    glVertex3f(80, 35.0, 50.1);
    glVertex3f(65, 35.0, 50.1);
    glEnd();
    //
    glBegin(GL_QUADS);//Pagar
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(10, 0.0, 50.0);
    glVertex3f(65, 0.0, 50.0);
    glVertex3f(65, 20.0, 50.0);
    glVertex3f(10, 20.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//Pagar
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(-60, 0.0, 50.0);
    glVertex3f(-55, 0.0, 50.0);
    glVertex3f(-55, 35.0, 50.0);
    glVertex3f(-60, 35.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//PagarKanan
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(80, 0.0, 50.0);
    glVertex3f(80, 0.0, -80.0);
    glVertex3f(80, 35.0, -80.0);
    glVertex3f(80, 35.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//PagarKiri
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(-60, 0.0, 50.0);
    glVertex3f(-60, 0.0, -80.0);
    glVertex3f(-60, 45.0, -80.0);
    glVertex3f(-60, 45.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);//PagarKiri
    glColor3f(0.19, 0.2, 0.2);
    glVertex3f(-60, 0.0, 30.0);
    glVertex3f(-60, 0.0, -80.0);
    glVertex3f(-60, 60.0, -80.0);
    glVertex3f(-60, 60.0, 30.0);
    glEnd();
    glBegin(GL_QUADS);//tembok kiri
    glColor3f(0.56,0.56,0.56);
    glVertex3f(0, 0.0, 0.0);
    glVertex3f(0, 60.0, 0.0);
    glVertex3f(0, 60.0, -80.0);
    glVertex3f(0, 0.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//tembok kiri
    glColor3f(0.56, 0.56, 0.56);
    glVertex3f(-60, 0.0, -80.1);
    glVertex3f(80, 0.0, -80.1);
    glVertex3f(80, 63.0, -80.1);
    glVertex3f(-60, 63.0, -80.1);
    glEnd();
    glBegin(GL_QUADS);//atap
    glColor3f(0.24, 0.2, 0.04);
    glVertex3f(30, 80.0, 0.0);
    glVertex3f(0, 62.0, 0.0);
    glVertex3f(0, 62.0, -80.0);
    glVertex3f(30, 80.0, -80.0);
    glVertex3f(30, 80.0, 0.0);
    glVertex3f(60, 62.0, 0.0);
    glVertex3f(60, 62.0, -80.0);
    glVertex3f(30, 80.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//list
    glColor3f(0.33, 0.26, 0);
    glVertex3f(0, 62.0, 0.0);
    glVertex3f(0, 60.0, 0.0);
    glVertex3f(0, 60.0, -80.0);
    glVertex3f(0, 62.0, -80.0);
    glBegin(GL_QUADS);//tembok kiri
    glColor3f(1, 1, 0.97);
    glVertex3f(-0.1, 20.0, -20.0);
    glVertex3f(-0.1, 25.0, -20.0);
    glVertex3f(-0.1, 25.0, -25.0);
    glVertex3f(-0.1, 20.0, -25.0);
    glVertex3f(-0.1, 20.0, -14.0);
    glVertex3f(-0.1, 25.0, -14.0);
    glVertex3f(-0.1, 25.0, -19.0);
    glVertex3f(-0.1, 20.0, -19.0);
    //
    glVertex3f(-0.1, 26.0, -20.0);
    glVertex3f(-0.1, 31.0, -20.0);
    glVertex3f(-0.1, 31.0, -25.0);
    glVertex3f(-0.1, 26.0, -25.0);
    glVertex3f(-0.1, 26.0, -14.0);
    glVertex3f(-0.1, 31.0, -14.0);
    glVertex3f(-0.1, 31.0, -19.0);
    glVertex3f(-0.1, 26.0, -19.0);
    //
    glVertex3f(-0.1, 32.0, -20.0);
    glVertex3f(-0.1, 36.0, -20.0);
    glVertex3f(-0.1, 36.0, -25.0);
    glVertex3f(-0.1, 32.0, -25.0);
    glVertex3f(-0.1, 32.0, -14.0);
    glVertex3f(-0.1, 36.0, -14.0);
    glVertex3f(-0.1, 36.0, -19.0);
    glVertex3f(-0.1, 32.0, -19.0);
    //
    glVertex3f(-0.1, 37.0, -20.0);
    glVertex3f(-0.1, 42.0, -20.0);
    glVertex3f(-0.1, 42.0, -25.0);
    glVertex3f(-0.1, 37.0, -25.0);
    glVertex3f(-0.1, 37.0, -14.0);
    glVertex3f(-0.1, 42.0, -14.0);
    glVertex3f(-0.1, 42.0, -19.0);
    glVertex3f(-0.1, 37.0, -19.0);
    //
    glVertex3f(-0.1, 43.0, -20.0);
    glVertex3f(-0.1, 48.0, -20.0);
    glVertex3f(-0.1, 48.0, -25.0);
    glVertex3f(-0.1, 43.0, -25.0);
    glVertex3f(-0.1, 43.0, -14.0);
    glVertex3f(-0.1, 48.0, -14.0);
    glVertex3f(-0.1, 48.0, -19.0);
    glVertex3f(-0.1, 43.0, -19.0);
    glEnd();
    glBegin(GL_QUADS);//list
    glColor3f(0.33, 0.26, 0);
    glVertex3f(0, 52.0, 0.0);
    glVertex3f(0, 50.0, 0.0);
    glVertex3f(60, 50.0, 0.0);
    glVertex3f(60, 52.0, 0.0);
    glColor3f(0.33, 0.26, 0);
    glVertex3f(0, 45.0, 0.1);
    glVertex3f(0, 43.0, 0.1);
    glVertex3f(60, 43.0, 0.1);
    glVertex3f(60, 45.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//tembok depan
    glColor3f(0.56,0.56,0.56);
    glVertex3f(0, 0.0, 0.0);
    glVertex3f(0, 45.0, 0.0);
    glVertex3f(60, 45.0, 0.0);
    glVertex3f(60, 0.0, 0.0);
    glVertex3f(0, 50.0, -0.01);
    glVertex3f(0, 62.0, -0.01);
    glVertex3f(60, 62.0, -0.01);
    glVertex3f(60, 50.0, -0.01);
    glEnd();
    glBegin(GL_QUADS);//atap besi
    glColor3f(0.53, 0.53, 0.53);
    glVertex3f(0, 55.5, -80.0);
    glVertex3f(60, 55.5, -80.0);
    glVertex3f(60, 55.5, 50.0);
    glVertex3f(0, 55.5, 50.0);
    glVertex3f(0, 55, -80.0);
    glVertex3f(60, 55, -80.0);
    glVertex3f(60, 55, 50.0);
    glVertex3f(0, 55, 50.0);
    glEnd();
    glBegin(GL_QUADS);//atap besi
    glColor3f(0.53, 0.54, 0.53);
    glVertex3f(0, 60.5, -80.0);
    glVertex3f(0, 55.5, -80.0);
    glVertex3f(0, 55.5, 50.0);
    glVertex3f(0, 60.5, 50.0);
    glEnd();
    glBegin(GL_QUADS);//kramik
    glColor3f(0.37, 0.56, 0.4);
    glVertex3f(0, 0.0, 0.01);
    glVertex3f(0, 20.0, 0.01);
    glVertex3f(60, 20.0, 0.01);
    glVertex3f(60, 0.0, 0.01);
    glEnd();
    glBegin(GL_QUADS);//jendela depan
    glColor3f(0.32, 0.16, 0);
    glVertex3f(5, 12.0, 0.5);
    glVertex3f(18, 12.0, 0.5);
    glVertex3f(18, 43.0, 0.5);
    glVertex3f(5, 43.0, 0.5);
    glEnd();
    glBegin(GL_QUADS);//jendela depan
    glColor3f(0.24, 0.24, 0.24);
    glVertex3f(7, 13.0, 0.6);
    glVertex3f(16, 13.0, 0.6);
    glVertex3f(16, 42.0, 0.6);
    glVertex3f(7, 42.0, 0.6);
    glEnd();
    //
    glBegin(GL_QUADS);//jendela depan
    glColor3f(0.32, 0.16, 0);
    glVertex3f(45, 12.0, 0.5);
    glVertex3f(58, 12.0, 0.5);
    glVertex3f(58, 43.0, 0.5);
    glVertex3f(45, 43.0, 0.5);
    glEnd();
    glBegin(GL_QUADS);//jendela depan
    glColor3f(0.24, 0.24, 0.24);
    glVertex3f(47, 13.0, 0.6);
    glVertex3f(56, 13.0, 0.6);
    glVertex3f(56, 42.0, 0.6);
    glVertex3f(47, 42.0, 0.6);
    glEnd();
    glBegin(GL_LINES);//
    glColor3f(0.46, 0.69, 0.49);
    glVertex3f(0, 2, 0.01);
    glVertex3f(60, 2, 0.01);
    glVertex3f(0, 4, 0.01);
    glVertex3f(60, 4, 0.01);
    glVertex3f(0, 6, 0.01);
    glVertex3f(60, 6, 0.01);
    glVertex3f(0, 8, 0.01);
    glVertex3f(60, 8, 0.01);
    glVertex3f(0, 10, 0.01);
    glVertex3f(60, 10, 0.01);
    glVertex3f(0, 12, 0.01);
    glVertex3f(60, 12, 0.01);
    glVertex3f(0, 14, 0.01);
    glVertex3f(60, 14, 0.01);
    glVertex3f(0, 16, 0.01);
    glVertex3f(60, 16, 0.01);
    glVertex3f(0, 18, 0.01);
    glVertex3f(60, 18, 0.01);
    glVertex3f(0, 0, 0.01);
    glVertex3f(0, 20, 0.01);
    glVertex3f(10, 0, 0.01);
    glVertex3f(10, 20, 0.01);
    glVertex3f(10, 0, 0.01);
    glVertex3f(10, 20, 0.01);
    glVertex3f(20, 0, 0.01);
    glVertex3f(20, 20, 0.01);
    glVertex3f(30, 0, 0.01);
    glVertex3f(30, 20, 0.01);
    glVertex3f(40, 0, 0.01);
    glVertex3f(40, 20, 0.01);
    glVertex3f(50, 0, 0.01);
    glVertex3f(50, 20, 0.01);
    glVertex3f(60, 0, 0.01);
    glVertex3f(60, 20, 0.01);
    glEnd();
    glBegin(GL_QUADS);//pintu
    glColor3f(0.31, 0.25, 0.04);
    glVertex3f(20, 0.0, 0.3);
    glVertex3f(20, 45.0, 0.3);
    glVertex3f(40, 45.0, 0.3);
    glVertex3f(40, 0.0, 0.3);
    glVertex3f(20, 0.0, 0.5);
    glVertex3f(20, 45.0, 0.5);
    glVertex3f(40, 45.0, 0.5);
    glVertex3f(40, 0.0, 0.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.22, 0.18, 0);
    glVertex3f(30, 0, 0.5);
    glVertex3f(30, 45.0, 0.5);
    glVertex3f(20, 0, 0.5);
    glVertex3f(20, 45.0, 0.5);
    glVertex3f(40, 0, 0.5);
    glVertex3f(40, 45.0, 0.5);
    glVertex3f(20, 45.0, 0.5);
    glVertex3f(40, 45.0, 0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.37, 0.31, 0.06);
    glVertex3f(0, 62.0, 0.0);
    glVertex3f(60, 62.0, 0.0);
    glVertex3f(30, 80.0, 0.0);
    glVertex3f(0, 62.0, -80.0);
    glVertex3f(60, 62.0, -80.0);
    glVertex3f(30, 80.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.29, 0.23, 0);
    glVertex3f(20.0, 45, 0);
    glVertex3f(25.0, 45, 0);
    glVertex3f(25.0, 50, 0);
    glVertex3f(20.0, 50, 0);
    glVertex3f(40.0, 45, 0);
    glVertex3f(45.0, 45, 0);
    glVertex3f(45.0, 50, 0);
    glVertex3f(40.0, 50, 0);
    glEnd();
    glBegin(GL_LINES);//ventilasi
    glColor3f(0.29, 0.23, 0);
    glVertex3f(0.0, 45, 0);
    glVertex3f(0.0, 50, 0);
    glVertex3f(5.0, 45, 0);
    glVertex3f(5.0, 50, 0);
    glVertex3f(10.0, 45, 0);
    glVertex3f(10.0, 50, 0);
    glVertex3f(15.0, 45, 0);
    glVertex3f(15.0, 50, 0);
    glVertex3f(30.0, 45, 0);
    glVertex3f(30.0, 50, 0);
    glVertex3f(35.0, 45, 0);
    glVertex3f(35.0, 50, 0);
    glVertex3f(50.0, 45, 0);
    glVertex3f(50.0, 50, 0);
    glVertex3f(55.0, 45, 0);
    glVertex3f(55.0, 50, 0);
    glVertex3f(60.0, 45, 0);
    glVertex3f(60.0, 50, 0);
    glEnd();

    glBegin(GL_QUADS);//tembok kanan
    glColor3f(0.56, 0.56, 0.56);
    glVertex3f(60, 0.0, 0.0);
    glVertex3f(60, 60.0, 0.0);
    glVertex3f(60, 60.0, -80.0);
    glVertex3f(60, 0.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//list
    glColor3f(0.33, 0.26, 0);
    glVertex3f(60, 62.0, 0.0);
    glVertex3f(60, 60.0, 0.0);
    glVertex3f(60, 60.0, -80.0);
    glVertex3f(60, 62.0, -80.0);
    glBegin(GL_QUADS);//tembok kecil
    glColor3f(0.39, 0.39, 0.39);
    glVertex3f(60, 0.0, -40.0);
    glVertex3f(60, 60.0, -40.0);
    glVertex3f(80, 60.0, -40.0);
    glVertex3f(80, 0.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);//tembok kecil
    glColor3f(0.39, 0.39, 0.39);
    glVertex3f(79, 0.0, -40.0);
    glVertex3f(79, 60.0, -40.0);
    glVertex3f(79, 60.0, -80.0);
    glVertex3f(79, 0.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//atap
    glColor3f(0.24, 0.2, 0.04);
    glVertex3f(60, 60.0, -40.0);
    glVertex3f(70, 70.0, -40.0);
    glVertex3f(70, 70.0, -80.0);
    glVertex3f(60, 60.0, -80.0);

    glVertex3f(80, 60.0, -40.0);
    glVertex3f(80, 60.0, -80.0);
    glVertex3f(70, 70.0, -80.0);
    glVertex3f(70, 70.0, -40.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap
    glColor3f(0.35, 0.27, 0.01);
    glVertex3f(60, 60, -40.0);
    glVertex3f(80, 60, -40.0);
    glVertex3f(70, 70, -40.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap
    glColor3f(0.35, 0.27, 0.01);
    glVertex3f(60, 60, -80.0);
    glVertex3f(80, 60, -80.0);
    glVertex3f(70, 70, -80.0);
    glEnd();
    glBegin(GL_QUADS);//tembok kamar
    glColor3f(0.56, 0.56, 0.56);
    glVertex3f(0, 0.0, -40.0);
    glVertex3f(0, 60.0, -40.0);
    glVertex3f(-60, 60.0, -40.0);
    glVertex3f(-60, 0.0, -40.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.37, 0.31, 0.06);
    glVertex3f(-60, 60.0, -30.0);
    glVertex3f(0, 60.0, -30.0);
    glVertex3f(-30, 80.0, -30.0);
    glVertex3f(-60, 60.0, -80.0);
    glVertex3f(0, 60.0, -80.0);
    glVertex3f(-30, 80.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//atap
    glColor3f(0.24, 0.2, 0.04);
    glVertex3f(-60, 60.0, -30.0);
    glVertex3f(-30, 80.0, -30.0);
    glVertex3f(-30, 80.0, -80.0);
    glVertex3f(-60, 60.0, -80.0);
    glVertex3f(0, 60.0, -30.0);
    glVertex3f(-30, 80.0, -30.0);
    glVertex3f(-30, 80.0, -80.0);
    glVertex3f(0, 60.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);//kaca
    glColor3f(0.24, 0.24, 0.24);
    glVertex3f(0, 15.0, -39.5);
    glVertex3f(0, 55.0, -39.5);
    glVertex3f(-60, 55.0, -39.5);
    glVertex3f(-60, 15.0, -39.5);
    glBegin(GL_QUADS);//tembok kamar coklat
    glColor3f(0.23, 0.21, 0.09);
    glVertex3f(0, 49.0, -39);
    glVertex3f(0, 55.0, -39);
    glVertex3f(-60, 55.0, -39);
    glVertex3f(-60, 49.0, -39);
    glEnd();
    glBegin(GL_QUADS);//tembok kamar coklat
    glColor3f(0.23, 0.21, 0.09);
    glVertex3f(0, 12.0, -39);
    glVertex3f(0, 20.0, -39);
    glVertex3f(-60, 20.0, -39);
    glVertex3f(-60, 12.0, -39);
    glEnd();
    glBegin(GL_QUADS);//tembok kamar coklat
    glColor3f(0.23, 0.21, 0.09);
    glVertex3f(0, 15.0, -39);
    glVertex3f(0, 55.0, -39);
    glVertex3f(-2, 55.0, -39);
    glVertex3f(-2, 15.0, -39);
    glEnd();
    glBegin(GL_QUADS);//tembok kamar coklat
    glColor3f(0.23, 0.21, 0.09);
    glVertex3f(-60, 15.0, -39);
    glVertex3f(-60, 55.0, -39);
    glVertex3f(-58, 55.0, -39);
    glVertex3f(-58, 15.0, -39);
    glEnd();
    glBegin(GL_QUADS);//tembok kamar coklat
    glColor3f(0.23, 0.21, 0.09);
    glVertex3f(-36, 15.0, -39);
    glVertex3f(-36, 55.0, -39);
    glVertex3f(-34, 55.0, -39);
    glVertex3f(-34, 15.0, -39);
    //w
    glVertex3f(-28, 15.0, -39);
    glVertex3f(-28, 55.0, -39);
    glVertex3f(-26, 55.0, -39);
    glVertex3f(-26, 15.0, -39);
    glEnd();
    glBegin(GL_LINES);//jendela
    glColor3f(0.25, 0.21, 0.02);
    glVertex3f(-26.0, 22, -39);
    glVertex3f(-36.0, 22, -39);
    glVertex3f(-26.0, 25, -39);
    glVertex3f(-36.0, 25, -39);
    glVertex3f(-26.0, 28, -39);
    glVertex3f(-36.0, 28, -39);
    glVertex3f(-26.0, 31, -39);
    glVertex3f(-36.0, 31, -39);
    glVertex3f(-26.0, 34, -39);
    glVertex3f(-36.0, 34, -39);
    glVertex3f(-26.0, 37, -39);
    glVertex3f(-36.0, 37, -39);
    glVertex3f(-26.0, 40, -39);
    glVertex3f(-36.0, 40, -39);
    glVertex3f(-26.0, 43, -39);
    glVertex3f(-36.0, 43, -39);
    glVertex3f(-26.0, 46, -39);
    glVertex3f(-36.0, 46, -39);
    glEnd();
    //pagar tok
    glBegin(GL_QUADS);//pagar //y35
    glColor3f(0.05, 0.05, 0.05);
    glVertex3f(-55, 0.0, 50);
    glVertex3f(-34, 0.0, 50);
    glVertex3f(-34, 10.0, 50);
    glVertex3f(-55, 10.0, 50);
    glVertex3f(-10, 0.0, 50);
    glVertex3f(-33.5, 0.0, 50);
    glVertex3f(-33.5, 10.0, 50);
    glVertex3f(-10, 10.0, 50);
    //
    glVertex3f(-55, 0.0, 50);
    glVertex3f(-53, 0.0, 50);
    glVertex3f(-53, 35.0, 50);
    glVertex3f(-55, 35.0, 50);
    glVertex3f(-10, 0.0, 50);
    glVertex3f(-12, 0.0, 50);
    glVertex3f(-12, 35.0, 50);
    glVertex3f(-10, 35.0, 50);
    //
    glVertex3f(-55, 33.0, 50);
    glVertex3f(-34, 33.0, 50);
    glVertex3f(-34, 35.0, 50);
    glVertex3f(-55, 35.0, 50);
    glVertex3f(-10, 33.0, 50);
    glVertex3f(-33.5, 33.0, 50);
    glVertex3f(-33.5, 35.0, 50);
    glVertex3f(-10, 35.0, 50);
    //
    glVertex3f(-36, 0.0, 50);
    glVertex3f(-34, 0.0, 50);
    glVertex3f(-34, 35.0, 50);
    glVertex3f(-36, 35.0, 50);
    glVertex3f(-31.5, 0.0, 50);
    glVertex3f(-33.5, 0.0, 50);
    glVertex3f(-33.5, 35.0, 50);
    glVertex3f(-31.5, 35.0, 50);
    //
    glVertex3f(-55, 22.0, 50);
    glVertex3f(-34, 22.0, 50);
    glVertex3f(-34, 20.0, 50);
    glVertex3f(-55, 20.0, 50);
    glVertex3f(-10, 22.0, 50);
    glVertex3f(-33.5, 22.0, 50);
    glVertex3f(-33.5, 20.0, 50);
    glVertex3f(-10, 20.0, 50);
    //
    glVertex3f(-55, 31.0, 50);
    glVertex3f(-34, 31.0, 50);
    glVertex3f(-34, 30.0, 50);
    glVertex3f(-55, 30.0, 50);
    glVertex3f(-10, 31.0, 50);
    glVertex3f(-33.5, 31.0, 50);
    glVertex3f(-33.5, 30.0, 50);
    glVertex3f(-10, 30.0, 50);
    //
    glVertex3f(-45, 0.0, 50);
    glVertex3f(-44, 0.0, 50);
    glVertex3f(-44, 30.0, 50);
    glVertex3f(-45, 30.0, 50);
    glVertex3f(-22, 0.0, 50);
    glVertex3f(-21, 0.0, 50);
    glVertex3f(-21, 30.0, 50);
    glVertex3f(-22, 30.0, 50);
    //segi y21 kanankiri || y25 atasbawah || -4721 -44.516 4221 44.526
    glVertex3f(-47, 21.0, 50);
    glVertex3f(-44.5, 16.0, 50);
    glVertex3f(-42, 21.0, 50);
    glVertex3f(-44.5, 26.0, 50);
    glVertex3f(-24, 21.0, 50);
    glVertex3f(-21.5, 16.0, 50);
    glVertex3f(-19, 21.0, 50);
    glVertex3f(-21.5, 26.0, 50);
    //
    glVertex3f(-50, 0.0, 50);
    glVertex3f(-49, 0.0, 50);
    glVertex3f(-49, 30.0, 50);
    glVertex3f(-50, 30.0, 50);
    glVertex3f(-40, 0.0, 50);
    glVertex3f(-39, 0.0, 50);
    glVertex3f(-39, 30.0, 50);
    glVertex3f(-40, 30.0, 50);
    //
    glVertex3f(-27, 0.0, 50);
    glVertex3f(-26, 0.0, 50);
    glVertex3f(-26, 30.0, 50);
    glVertex3f(-27, 30.0, 50);
    glVertex3f(-17, 0.0, 50);
    glVertex3f(-16, 0.0, 50);
    glVertex3f(-16, 30.0, 50);
    glVertex3f(-17, 30.0, 50);
    glEnd();
    //ganti
    glBegin(GL_QUADS);//Pagar
    glColor3f(0.05, 0.05, 0.05);
    glVertex3f(10, 33.0, 50.0);
    glVertex3f(65, 33.0, 50.0);
    glVertex3f(65, 35.0, 50.0);
    glVertex3f(10, 35.0, 50.0);
//a
    glVertex3f(10, 20.0, 50.0);
    glVertex3f(65, 20.0, 50.0);
    glVertex3f(65, 22.0, 50.0);
    glVertex3f(10, 22.0, 50.0);
    //
    glColor3f(0.05, 0.05, 0.05);
    glVertex3f(63, 20.0, 50.0);
    glVertex3f(65, 20.0, 50.0);
    glVertex3f(65, 35.0, 50.0);
    glVertex3f(63, 35.0, 50.0);
    glColor3f(0.05, 0.05, 0.05);
    glVertex3f(10, 20.0, 50.0);
    glVertex3f(12, 20.0, 50.0);
    glVertex3f(12, 35.0, 50.0);
    glVertex3f(10, 35.0, 50.0);
    //
    glColor3f(0.05, 0.05, 0.05);
    glVertex3f(15, 20.0, 50.0);
    glVertex3f(16, 20.0, 50.0);
    glVertex3f(16, 35.0, 50.0);
    glVertex3f(15, 35.0, 50.0);
    //
    glVertex3f(20, 20.0, 50.0);
    glVertex3f(21, 20.0, 50.0);
    glVertex3f(21, 35.0, 50.0);
    glVertex3f(20, 35.0, 50.0);
    //
    glVertex3f(25, 20.0, 50.0);
    glVertex3f(26, 20.0, 50.0);
    glVertex3f(26, 35.0, 50.0);
    glVertex3f(25, 35.0, 50.0);
    //
    glVertex3f(30, 20.0, 50.0);
    glVertex3f(31, 20.0, 50.0);
    glVertex3f(31, 35.0, 50.0);
    glVertex3f(30, 35.0, 50.0);
    //
    glVertex3f(35, 20.0, 50.0);
    glVertex3f(36, 20.0, 50.0);
    glVertex3f(36, 35.0, 50.0);
    glVertex3f(35, 35.0, 50.0);
    //
    glVertex3f(40, 20.0, 50.0);
    glVertex3f(41, 20.0, 50.0);
    glVertex3f(41, 35.0, 50.0);
    glVertex3f(40, 35.0, 50.0);
    //
    glVertex3f(45, 20.0, 50.0);
    glVertex3f(46, 20.0, 50.0);
    glVertex3f(46, 35.0, 50.0);
    glVertex3f(45, 35.0, 50.0);
    glVertex3f(50, 20.0, 50.0);
    glVertex3f(51, 20.0, 50.0);
    glVertex3f(51, 35.0, 50.0);
    glVertex3f(50, 35.0, 50.0);
    //
    glVertex3f(55, 20.0, 50.0);
    glVertex3f(56, 20.0, 50.0);
    glVertex3f(56, 35.0, 50.0);
    glVertex3f(55, 35.0, 50.0);
    glVertex3f(60, 20.0, 50.0);
    glVertex3f(61, 20.0, 50.0);
    glVertex3f(61, 35.0, 50.0);
    glVertex3f(60, 35.0, 50.0);
    glEnd();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}
void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w': //Zoom Out
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd': //Geser Kiri
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's': //Zoom In
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a': //Geser Kanan
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
        //geser bawah
    case '1':
        glTranslatef(0.0, 3.0, 0.0);
        break;
        //geser atas
    case '2':
        glTranslatef(0.0, -3.0, 0.0);
        break;
        //melihat bentuk rumah bagian dalam
    case '3':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }

    }
    tampil();
}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, lebar / tinggi, 5.0, 700.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}