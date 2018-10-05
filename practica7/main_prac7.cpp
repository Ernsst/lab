//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************				HERNANDEZ HINOJOSA ERNESTO
			//                  ACTIVIDAD DE de lab PRACTICA 67                 ******//
//*************			SE IMPLEMENTO DESDE VISUAL STUDIO 2017			******//
//la animacion corre sin teclas, para navegar son las teclas que nos proporciono el prof.
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int lunaT = 0;
int marteT = 0;
int marteT2 = 0;
int jupiterT = 0;
int jupiterT2= 0;
int jupiterT3 = 0;
int saturnoT = 0;
int saturnoT2 = 0;
 

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercuryDiffuse[] = { 1.0f, 1.0f, 1.0f, .0f };			// Mercurio
GLfloat MercurySpecular[] = { 2.0, 2.5, 2.5, 1.0 };
GLfloat MercuryShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.97f, 0.95f, 0.7f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 2.0, 2.5, 2.5, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MDiffuse[] = { 0.5f, 0.2f, 0.6f, 1.0f };			
GLfloat MSpecular[] = { 0.3, 0.4, 0.2, 1.0 };
GLfloat MShininess[] = { 50.0 };

GLfloat M2Diffuse[] = { 0.2f, 0.9f, 0.2f, 1.0f };
GLfloat M2Specular[] = { 0.3, 1.0, 1.0, 1.0 };
GLfloat M2Shininess[] = { 70.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.7f, 0.8f, 0.7f, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat Sat1Diffuse[] = { 0.9f, 0.9f, 0.8f, 1.0f };			// Jupiter Sat1
GLfloat Sat1Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Sat1Shininess[] = { 50.0 };

GLfloat Sat2Diffuse[] = { 0.7f, 0.4f, 0.2f, 1.0f };			// Jupiter Sat2
GLfloat Sat2Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Sat2Shininess[] = { 50.0 };

GLfloat Sat3Diffuse[] = { 0.5f, 0.6f, 0.2f, 1.0f };			// Jupiter Sat3
GLfloat Sat3Specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Sat3Shininess[] = { 50.0 };


GLfloat SaturnoDiffuse[] = { 0.9f, 0.9f, 0.55f, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat AnilloDiffuse[] = { 0.9f, 0.5f, 0.2f, 1.0f };			// Saturno Anillo
GLfloat AnilloSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat AnilloShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.4f, 0.0f, 1.0f, 1.0f };			//Urano
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NepDiffuse[] = { 0.25f, 0.8f, 0.7f, 1.0f };			//Neptuno
GLfloat NepSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);

	glLightfv(GL_LIGHT1, GL_SPECULAR, SunDiffuse);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
glPushMatrix();

			
				glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje pivote traslasuci

					glPushMatrix(); //general

						glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
						glDisable(GL_LIGHTING);
						glutSolidSphere(1.9, 50, 50);  //Draw Sun (radio,H,V);
						glEnable(GL_LIGHTING);
					 glPopMatrix();

			glPushMatrix(); //mercurio
				glRotatef(sol, 0, 1, 0); //traslación
				glTranslatef(3.2,0,0);   //distancia del sol
				//pivote para que rote 
				glRotatef(mercurio, 0, 1,0); //Rotacion
				glColor3f(0.2,1.0,0.4);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MercuryDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MercurySpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MercuryShininess);
				glutSolidSphere(0.3,50,50);
			glPopMatrix();

			glPushMatrix(); //venus
				glRotatef(sol, 0, 1, 0); //traslación
				glTranslatef(5.0, 0, 0);   //distancia del sol
									   //pivote para que rote 
				glRotatef(mercurio, 0, 1, 0); //Rotacion
				glColor3f(1.0, 0.2, 0.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
				glutSolidSphere(0.5, 50, 50);
			glPopMatrix();


			glPushMatrix(); //tierra
				glRotatef(sol, 0, 1, 0); //traslación
				glTranslatef(8.2, 0, 0);   //distancia del sol
											//pivote para que rote 
				glRotatef(lunaT, 0, 1, 0); //Rotacion
				glColor3f(0.0, 0.0, 1.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
				glutSolidSphere(0.7, 50, 50);

				glRotatef(45, 1, 0, 0); //luna acomodado a 45 
				glColor3f(1.0, 1.0, 1.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
				glTranslatef(1.5, 0, 0);
				glutSolidSphere(0.3, 50, 50 );
glPopMatrix();


		glPushMatrix(); //marte

				glRotatef(sol, 0, 1, 0); //traslación
				glTranslatef(14.2, 0, 0);   //distancia del sol
											//pivote para que rote 
				glRotatef(marteT, 0, 1, 0); //Rotacion
				glColor3f(0.5, 0.07, 0.3);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
				glutSolidSphere(0.4, 50, 50);

				glPushMatrix();
					glRotatef(marteT2, 1, 0, 0); //luna acomodado a 45 
					glColor3f(0.3, 1.0, 1.0);
					glTranslatef(1.5, 0, 0);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, MDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, MSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, MShininess);
					glutSolidSphere(0.2, 50, 50);
				
				glPushMatrix();
					glRotatef(45, 1, 0, 0); //luna2 acomodado a 45 
					glColor3f(1.0, 0.5, 1.0);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, M2Diffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, M2Specular);
					glMaterialfv(GL_FRONT, GL_SHININESS, M2Shininess);
					glTranslatef(1.5, 0, 0);
					glutSolidSphere(0.2, 50, 50);

					glPopMatrix();
				glPopMatrix();


			glPopMatrix();

			glPushMatrix(); //jupiter

				glRotatef(sol, 0, 1, 0); //traslación
				glTranslatef(22.2, 0, 0);   //distancia del sol
											//pivote para que rote 
				glRotatef(jupiterT, 0, 1, 0); //Rotacion
				glColor3f(1.0, 0.5019, 0.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
				glutSolidSphere(1, 50, 50);
					glPushMatrix();
						glRotatef(45, 1, 0, 0); //luna acomodado a 45 
						glColor3f(0.6, 0.0, 0.0);
						glTranslatef(1.5, 0, 0);
						glutSolidSphere(0.3, 50, 50);
			

				glPushMatrix();
					glRotatef(-jupiterT2, 1, 0, 0); //luna2 acomodado a 45 
					glColor3f(1.0, 0.4, 0.4);
					glTranslatef(1.5, 0, 0);
					glutSolidSphere(0.3, 50, 50);

					glPushMatrix();
						glRotatef(-jupiterT3, 1, 0, 0); //luna3 acomodado a 45 
						glColor3f(0.2, 1.0, 1.0);
						glTranslatef(1.5, 0, 0);
						glutSolidSphere(0.3, 50, 50);


			glPopMatrix();
				glPopMatrix();
					glPopMatrix();
						glPopMatrix();





			glPushMatrix(); //saturno

			glRotatef(sol, 0, 1, 0); //traslación
			glTranslatef(30.2, 0, 0);   //distancia del sol
										//pivote para que rote 
			glRotatef(saturnoT, 0, 1, 0); //Rotacion
			glColor3f(0.5, 0.5, 0.5);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Sat1Diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Sat1Specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, Sat1Shininess);
			glutSolidSphere(0.8, 50, 50);

			glRotatef(45, 1, 0, 0); //toroide acomodado a 45 
			glColor3f(1.0, 1.0, 1.0);
			glutSolidTorus(0.2, 0.7, 15, 15);

			glRotatef(-45, 1, 0, 0); //toroide acomodado a 45 
			glColor3f(1.0, 0, 1.0);
			glutSolidTorus(0.2, 0.7, 15, 15);
			



			glPopMatrix();



			glPushMatrix(); //saturno

					glRotatef(sol, 0, 1, 0); //traslación
					glTranslatef(35.2, 0, 0);   //distancia del sol
											//pivote para que rote 
					//glRotatef(mercurio, 0, 1, 0); //Rotacion
					glColor3f(0.2, 1.0, 0.2);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, AnilloDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, AnilloSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, AnilloShininess);
					glutSolidSphere(0.9, 50, 50);

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
		sol = (sol  - 1) % 360;
	mercurio = (mercurio - 5) % 360;

		lunaT = (lunaT - 5) % 360;
		marteT = (marteT - 5) % 360;
		marteT2 = (marteT2 +2) % 360;
	jupiterT = (jupiterT - 4) % 360;
	   jupiterT2 = (jupiterT + 3) % 360;
	  jupiterT3 = (jupiterT2 - 4) % 360;
		saturnoT = (saturnoT - 2) % 360;
		saturnoT2 = (saturnoT - 2) % 360;
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

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
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
  glutIdleFunc		  ( animacion ); //por cada frame de dibujo
  glutMainLoop        ( );          // 

  return 0;
}