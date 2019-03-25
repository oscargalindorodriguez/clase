//
//Laboratorio de computacion grafica
//Grupo:1
//Alumno Galindo Rodriguez Oscar
//PRACTICA 6
//Solar  System
//Fecha: 22 de marzo de 2019
#include "Main.h"


//dediniendo tiempos
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna_tierra = 0;
int luna_marte = 0;
int luna_jupiter1 = 0;
int luna_jupiter2 = 0;
int luna_saturno1 = 0;
int luna_saturno2 = 0;
int luna_urano1 = 0;
int luna_urano2 = 0;
int luna_neptuno1 = 0;
int luna_neptuno2 = 0;
int anillo = 0;




float camaraZ = 0.0;
float camaraX = 0.0;

					
GLfloat LuzAmbiental[] = { 0.0, 0.0, 0.0, 1.0 };					
GLfloat LuzDifusa[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LuzEspectacular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LuzPosicion[] = { 0.0,0.0,0.0 };


// sol
GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//planeta tierra
GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };
//satelite lunar
GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };
//planeta marte
GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


	glLightiv(GL_LIGTH , GL_DIFFUSE, LUZ_AMBIENTAL);


	glEnable(GL_LIGHT);


}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//cam
	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);

	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicion );
	glEnable(GL_LIGHTING);

	//sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(4.0, 12, 12);
	glPopMatrix();
	//primer planeta mercurio
	glPushMatrix();
	glRotatef(mercurio, 0, 1, 0);
	glTranslatef(8.0, 0.0, 0.0);
	glColor3f(1.0, 0.458, 0.078);
	glRotatef(mercurio, 0, 1, 0);
	glutSolidSphere(0.5, 12, 12);
	glPopMatrix();

	//segundo planeta-venus

	glPushMatrix();
	glRotatef(venus, 0, 1, 0);
	glTranslatef(9.0, 0.0, 0.0);
	glColor3f(0.9, 0.8, 0.4);
	glRotatef(venus, 0, 1, 0);
	glutSolidSphere(0.8, 12, 12);
	glPopMatrix();

	//tercer planeta tierra

	glPushMatrix();
	glRotatef(tierra, 0, 1, 0);
	glTranslatef(10.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(tierra, 0, 1, 0);
	glutSolidSphere(0.95, 12, 12);
	//satelite lunar de la tierra
	glPushMatrix();
	glRotatef(luna_tierra, 0, 1, 0);
	glTranslatef(1.3, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_tierra, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPopMatrix();

	//cuarto planeta- marte
	glPushMatrix();
	glRotatef(marte, 0, 1, 0);
	glTranslatef(12.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 0, 1, 0);
	glutSolidSphere(0.8, 12, 12);
	//marte tiene dos lunas fobos y deimos
	glPushMatrix();
	glRotatef(luna_marte, 0, 1, 0);
	glTranslatef(1.3, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_marte, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPopMatrix();

	//jupiter

	glPushMatrix();
	glRotatef(jupiter, 0, 1, 0);
	glTranslatef(12.0, 0.0, 0.0);
	glColor3f(1.4, 0.4, 0.07);
	glRotatef(jupiter, 0, 1, 0);
	glutSolidSphere(2.0, 12, 12);

	//lunas de jupiter

	glPushMatrix();
	glRotatef(luna_jupiter1, 0, 1, 0);
	glTranslatef(2.3, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_jupiter1, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(luna_jupiter2, 0, 1, 0);
	glTranslatef(2.8, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_jupiter2, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPopMatrix();

	//planeta-saturno

	glPushMatrix();
	glRotatef(saturno, 0, 1, 0);
	glTranslatef(17.0, 0.0, 0.0);
	glColor3f(0.8, 0.5, 0.5);
	glRotatef(saturno, 0, 1, 0);
	glutSolidSphere(2.0, 12, 12);

	//lunas de saturno

	glPushMatrix();
	glRotatef(luna_saturno1, 0, 1, 0);
	glTranslatef(2.3, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_saturno1, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(luna_saturno2, 0, 1, 0);
	glTranslatef(3.0, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_saturno2, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	//creando anillos de saturno

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(45, 1, 0, 0);
	glutSolidTorus(0.2, 2.3, 30, 30);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidTorus(0.2, 2.7, 30, 30);
	glPopMatrix();

	glPopMatrix();

	//planeta urano

	glPushMatrix();
	glRotatef(urano, 0, 1, 0);
	glTranslatef(21.0, 0.0, 0.0);
	glColor3f(0.2, 0.8, 0.9);
	glRotatef(urano, 0, 1, 0);
	glutSolidSphere(1.5, 12, 12);

	//lunas de urano

	glPushMatrix();
	glRotatef(luna_urano1, 0, 1, 0);
	glTranslatef(-2.4, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_urano1, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(luna_urano2, 0, 1, 0);
	glTranslatef(2.5, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_urano2, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPopMatrix();

	//planeta-neptuno

	glPushMatrix();
	glRotatef(urano, 0, 1, 0);
	glTranslatef(25.0, 0.0, 0.0);
	glColor3f(0.2, 0.2, 0.9);

	glutSolidSphere(1.3, 12, 12);

	//lunas de neptuno

	glPushMatrix();
	glRotatef(luna_neptuno1, 0, 1, 0);
	glTranslatef(-1.8, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_neptuno1, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(luna_neptuno2, 0, 1, 0);
	glTranslatef(1.8, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(luna_neptuno2, 0, 1, 0);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{

	dwCurrentTime = GetTickCount();
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 3) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra - 3) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 2) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 2) % 360;
		luna_tierra = (luna_tierra - 3) % 360;
		luna_marte = (luna_marte - 3) % 360;
		luna_jupiter1 = (luna_jupiter1 - 3) % 360;
		luna_jupiter2 = (luna_jupiter2 - 3) % 360;
		luna_saturno1 = (luna_saturno1 - 3) % 360;
		luna_saturno2 = (luna_saturno2 - 3) % 360;
		luna_urano1 = (luna_urano1 - 3) % 360;
		luna_urano2 = (luna_urano2 - 3) % 360;
		luna_neptuno1 = (luna_neptuno1 - 3) % 360;
		luna_neptuno2 = (luna_neptuno2 - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		transZ += 0.5f;
		break;
	case 's':
	case 'S':
		transZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		transX -= 0.5f;
		break;
	case 'd':
	case 'D':
		transX += 0.5f;
		break;

		//Agregar aquí teclas para movimiento de luz
	case 'i':		//Movimientos de Luz
	case 'I':
		spin = (spin - 20) % 360;
		break;
	case 'k':
	case 'K':
		spin = (spin + 20) % 360;
		break;;


	case 'l':   //Activamos/desactivamos luz
	case 'L':
		light = !light;
		break;

	case 'p':   //Activamos/desactivamos luz
	case 'P':
		positional = !positional;
		break;

	case 'c':
		LightAngle += 2.0f;
		printf("Angulo = %f\n", LightAngle);
		break;
	case 'v':
		LightAngle -= 2.0f;
		printf("Angulo = %f\n", LightAngle);
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:

		break;
	case GLUT_KEY_DOWN:

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
