//Semestre 2019 - 2
//Laboratorio de computacion grafica
//Grupo:1
//Alumno Galindo Rodriguez Oscar
//PRACTICA 7//
//Fecha: 27 de marzo de 2019//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
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

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values  rgb canal alfa =1
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values  rgb 
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values  rgb 
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position    XYZ 
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position    XYZ 
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			    // Light Position    XYZ  a donde apunta el vector de posicion 
																//componentes del material 
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background   formato RGB y el  canal alfa 
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest





float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.7f, 0.8f, 0.2f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat MercurioDiffuse[] = { 0.8f, 0.2f, 0.2f, 1.0f };			// mercurio
GLfloat MercurioSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
	//glEnable(GL_LIGHT0);

	

	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glLightfv(GL_LIGHT1, GL_POSITION, LightDirection);
	glEnable(GL_LIGHTING);

	
	
	glPushMatrix();//sistema solar
		
		glPushMatrix(); // sol
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glDisable(GL_LIGHTING);
			glutSolidSphere(4.0,12,12);  //Draw Sun (radio,H,V);
			glEnable(GL_LIGHTING); 
		glPopMatrix();

		glPushMatrix();//mercurio
			glRotatef(mercurio, 0, 1, 0); 
			glTranslatef(8.0, 0.0, 0.0);
			glColor3f(1.0, 0.458, 0.078);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR,MercurioDiffuse);
			glRotatef(mercurio, 0, 1, 0);
			glutSolidSphere(0.5, 12, 12); 
		glPopMatrix(); 

	

		glPushMatrix();//venus
			glRotatef(venus, 0, 1, 0); 
			glTranslatef(9.0, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.4);
			glMaterialfv(GL_FRONT, GL_DIFFUSE,VenusDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, VenusDiffuse);
			glRotatef(venus, 0, 1, 0);
			glutSolidSphere(0.8, 12, 12); 
		glPopMatrix(); 

		glPushMatrix();//tierra
			glRotatef(tierra, 0, 1, 0); 
			glTranslatef(10.0, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthDiffuse);
			glRotatef(tierra, 0, 1, 0);
			glutSolidSphere(0.95, 12, 12);

			glPushMatrix();//luna 
				glRotatef(luna_tierra, 0, 1, 0); 
				glTranslatef(1.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_tierra, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 
			
		glPopMatrix();//tierra
		
			
		glPushMatrix();//marte
			glRotatef(marte, 0, 1, 0); 
			glTranslatef(12.0, 0.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glRotatef(marte, 0, 1, 0);
			glutSolidSphere(0.8, 12, 12);

			glPushMatrix();//luna de marte
				glRotatef(luna_marte, 0, 1, 0); 
				glTranslatef(1.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_marte, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 
		glPopMatrix(); 

		glPushMatrix();//jupiter
			glRotatef(jupiter, 0, 1, 0); 
			glTranslatef(12.0, 0.0, 0.0);
			glColor3f(1.0, 0.4, 0.07);
			glRotatef(jupiter, 0, 1, 0);
			glutSolidSphere(2.0, 12, 12);

			glPushMatrix();//luna de jupiter1
				glRotatef(luna_jupiter1, 0, 1, 0); 
				glTranslatef(2.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_jupiter1, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

			glPushMatrix();//luna de jupiter2
				glRotatef(luna_jupiter2, 0, 1, 0); 
				glTranslatef(2.8, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_jupiter2, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

		glPopMatrix(); //jupiter

		glPushMatrix();//saturno
			glRotatef(saturno, 0, 1, 0); 
			glTranslatef(17.0, 0.0, 0.0);
			glColor3f(0.0, 0.8, 0.0);
			glRotatef(saturno, 0, 1, 0);
			glDisable(GL_LIGHTING);
			glutSolidSphere(2.0, 12, 12);
			glEnable(GL_LIGHTING);

			glPushMatrix();//luna de saturno
				glRotatef(luna_saturno1, 0, 1, 0); 
				glTranslatef(2.3, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_saturno1, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

			glPushMatrix();//luna de saturno2
				glRotatef(luna_saturno2, 0, 1, 0); 
				glTranslatef(3.0, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_saturno2, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

			glPushMatrix();//anillo de saturno
				//glRotatef(anillo, 0, 1, 0); 
				glTranslatef(0.0, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				//glRotatef(anillo, 0, 1, 0);
				glRotatef(45, 1, 0, 0);
				glutSolidTorus(0.2,2.3,30, 30); 
				glColor3f(0.4, 0.6, 0.9);
				glutSolidTorus(0.2, 2.7, 30, 30);
			glPopMatrix(); 

		glPopMatrix(); 

		glPushMatrix();//urano
			glRotatef(urano, 0, 1, 0); 
			glTranslatef(21.0, 0.0, 0.0);
			glColor3f(0.2, 0.8, 0.9);
			glRotatef(urano, 0, 1, 0);
			glutSolidSphere(1.5, 12, 12);

			glPushMatrix();//luna de urano1
				glRotatef(luna_urano1, 0, 1, 0); 
				glTranslatef(-2.4, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_urano1, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

			glPushMatrix();//luna de urano2
				glRotatef(luna_urano2, 0, 1, 0); 
				glTranslatef(2.5, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_urano2, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//neptuno
			glRotatef(urano, 0, 1, 0); 
			glTranslatef(25.0, 0.0, 0.0);
			glColor3f(0.2, 0.2, 0.9);
			//glRotatef(urano, 0, 1, 0);
			glutSolidSphere(1.3, 12, 12);

			glPushMatrix();//luna de neptuno1
				glRotatef(luna_neptuno1, 0, 1, 0); 
				glTranslatef(-1.8, 0.0, 0.0);
				glColor3f(0.5, 0.5, 0.5);
				glRotatef(luna_neptuno1, 0, 1, 0);
				glutSolidSphere(0.3, 12, 12);
			glPopMatrix(); 

			glPushMatrix();//luna de neptuno2
				glRotatef(luna_neptuno2, 0, 1, 0); 
				glTranslatef(1.8, 0.0, 0.0);
				glColor3f(0.1, 0.5, 0.0);
				glRotatef(luna_neptuno2, 0, 1, 0);
				glDisable(GL_LIGHTING);
				glutSolidSphere(0.3, 12, 12);
				glEnable(GL_LIGHTING);
			glPopMatrix(); 
		glPopMatrix(); 

	glPopMatrix();

glutSwapBuffers ( );
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
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

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   
		case 'L':
			break;
		case 27:       
			exit ( 0 );  
			break;        
		default:      
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
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


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}