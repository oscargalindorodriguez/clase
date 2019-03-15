
//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): GALINDO RODRIGUEZ OSCAR
//*************LABORATORIO DE COMPUTACION GRAFICA	******//
//*************		GRUPO:01		******//
//************************************************************//
#include "Main.h"

int screenW = 0.0;
int screenH = 0.0;

float transZ = -5.0f;
float transX = 0.0f;
float transY = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angP = 0.0f;		
float angP2 = 0.0f;		
float angInd = 0.0f;	
float angInd2 = 0.0f;	
float angInd3 = 0.0f;
float angMe = 0.0f;	
float angMe2 = 0.0f;	
float angMe3 = 0.0f;	
float angAnu = 0.0f;	
float angAnu2 = 0.0f;	
float angAnu3 = 0.0f;	
float angMen = 0.0f;		
float angMen2 = 0.0f;	
float angMen3 = 0.0f;	


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };		

void InitGL(void)    
{

	glShadeModel(GL_SMOOTH);						
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	
	glClearDepth(1.0f);									
	glEnable(GL_DEPTH_TEST);						


	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    
				{-0.5 ,-0.5, 0.5},    
				{-0.5 ,-0.5, -0.5},    
				{0.5 ,-0.5, -0.5},    
				{0.5 ,0.5, 0.5},   
				{0.5 ,0.5, -0.5},    
				{-0.5 ,0.5, -0.5},    
				{-0.5 ,0.5, 0.5},   
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)  
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);

	//Poner Código Aquí.

//Brazo 
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(0.0, -3.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glRotatef(angCodo, 0.0, 0.0, 1.0);
	prisma();

//antebrazo
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(1.5, 0.0f, 0.0);
	glScalef(2.0, 1.0, 1.0);
	prisma();
	glPopMatrix();

//Muñeca 
	glPushMatrix();
	glColor3f(1.0, 0.7, 1.0);
	glTranslatef(3.0, 0.0f, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glRotatef(angMu, 0.0, 1.0, 0.0);
	prisma();
	
	//Pulgar 
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.375, 0.25);
	glRotatef(angP, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.375, 0.0);
	glScalef(0.2, 0.5, 0.2);
	glRotatef(angP, 1.0, 0.0, 0.0);
	prisma();

	//extension del dedo pulgar
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.5, 0.0);
	glRotatef(angP2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.5, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();
	glPopMatrix();

	//Indice 
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.375, 0.35, 0.25);
	glRotatef(angInd, 0.0, 1.0, 0.0);
	glTranslatef(0.375, 0.0, 0.0);
	glScalef(0.5, 0.2, 0.2);
	prisma();

	//extension del indice parte 2
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angInd2, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();

	//extension del indice parte 3
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angInd3, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Medio 
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.5);
	glTranslatef(0.375, 0.12, 0.25);
	glRotatef(angMe, 0.0, 1.0, 0.0);
	glTranslatef(0.375, 0.0, 0.0);
	glScalef(0.5, 0.2, 0.2);
	prisma();

	//Medio extension parte 2
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angMe2, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();

	//Medio extension parte 3
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angMe3, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Anular 
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.3);
	glTranslatef(0.375, -0.12, 0.25);
	glRotatef(angAnu, 0.0, 1.0, 0.0);
	glTranslatef(0.375, 0.0, 0.0);
	glScalef(0.5, 0.2, 0.2);
	prisma();

	//Anular extesion 2
	glPushMatrix();
	glColor3f(0.3, 0.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angAnu2, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();

	//Anular extension 3

	glPushMatrix();
	glColor3f(0.0, 0.3, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angAnu3, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	//Meñique 
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.375, -0.35, 0.25);
	glRotatef(angMen, 0.0, 1.0, 0.0);
	glTranslatef(0.375, 0.0, 0.0);
	glScalef(0.5, 0.2, 0.2);
	prisma();

	//Meñique extension 2
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angMen2, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();

	//Meñique extension 3
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(angMen3, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();





	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
		

		//pulgar
	case '7':
		if (angP <= 60.0)
			angP += 1.0f;
		break;
	case '8':
		if (angP >= 2.0)
			angP -= 1.0f;
		break;
	case '9':
		if (angP2 <= 89.0)
			angP2 += 1.0f;
		break;
	case '0':
		if (angP2 >= 2.0)
			angP2 -= 1.0f;
		break;

		//indice

	case 'r':
	case 'R':
		if (angInd <= 7.0)
			angInd += 1.0f;
		break;
	case 't':
	case 'T':
		if (angInd >= -89.0)
			angInd -= 1.0f;
		break;
	case 'y':
	case 'Y':
		if (angInd2 <= -2.0)
			angInd2 += 1.0f;
		break;
	case 'u':
	case 'U':
		if (angInd2 >= -89.0)
			angInd2 -= 1.0f;
		break;

	case 'i':
	case 'I':
		if (angInd3 <= -2.0)
			angInd3 += 1.0f;
		break;
	case 'o':
	case 'O':
		if (angInd3 >= -89.0)
			angInd3 -= 1.0f;
		break;

		//medio
	case 'f':
	case 'F':
		if (angMe <= 7.0)
			angMe += 1.0f;
		break;
	case 'g':
	case 'G':
		if (angMe >= -89.0)
			angMe -= 1.0f;
		break;

	case 'h':
	case 'H':
		if (angMe2 <= -2.0)
			angMe2 += 1.0f;
		break;
	case 'j':
	case 'J':
		if (angMe2 >= -89.0)
			angMe2 -= 1.0f;
		break;

	case 'k':
	case 'K':
		if (angMe3 <= -2.0)
			angMe3 += 1.0f;
		break;
	case 'l':
	case 'L':
		if (angMe3 >= -89.0)
			angMe3 -= 1.0f;
		break;

		//anular  
	case 'x':
		if (angAnu <= 7.0)
			angAnu += 2.0f;
		break;
	case 'X':
		if (angAnu >= -89.0)
			angAnu -= 2.0f;
		break;
	case 'c':
		if (angAnu2 <= -2.0)
			angAnu2 += 2.0f;
		break;
	case 'C':
		if (angAnu2 >= -89.0)
			angAnu2 -= 2.0f;
		break;
	case 'v':
		if (angAnu3 <= 2.0)
			angAnu3 += 2.0f;
		break;
	case 'V':
		if (angAnu3 >= -89.0)
			angAnu3 -= 2.0f;
		break;

		//meñique  
	case 'b':
		if (angMen <= 7.0)
			angMen += 2.0f;
		break;
	case 'B':
		if (angMen >= -89.0)
			angMen -= 2.0f;
		break;
	case 'n':
		if (angMen2 <= -2.0)
			angMen2 += 2.0f;
		break;
	case 'N':
		if (angMen2 >= -89.0)
			angMen2 -= 2.0f;
		break;
	case 'm':
		if (angMen3 <= -2.0)
			angMen3 += 2.0f;
		break;
	case 'M':
		if (angMen3 >= -89.0)
			angMen3 -= 2.0f;
		break;

		//las de cajon
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		
		break;
	case 27:       
		exit(0);   
		break;
	default:        
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // choque de manos
{
	switch (a_keys) {
	
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}


