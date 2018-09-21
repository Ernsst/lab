//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************						HERNANDEZ HINOJOSA ERNESTO
            //                  ACTIVIDAD DE CLASE PRACTICA 5                  ******//
////*************			SE IMPLEMENTO DESDE VISUAL STUDIO 2017	
//             MOVER DEDOS "X"  "Y"//
/*	          rotar mano  "h"y "j"   					******/
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angBrazo = 0.0;
float angDG = 0.0;
float angD = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí. (0,0,0,0)

glPushMatrix();//dibuja brazo
	glTranslatef(-2.5, 1.25, 0); // muevo mis cordenandas ya no es el 0.0 -2.5,1.25
    glRotatef(angHombro, 0, 0, 1); //pivote

		glPushMatrix(); //dibuja hombro
			glTranslatef(2.5, -1.25, 0);  //regrso alcentro
			glScalef(5, 2.5, 5);
			prisma();
		glPopMatrix();
	
			glPushMatrix();//pivote2
				glTranslatef(5,-1.25, 0);
				glRotatef(angBrazo, 0, 1, 0); //pivote ///brzo
					glPushMatrix();
						glTranslatef(3,0, 0);
						glScalef(6, 2.5, 3);
						prisma();
                    glPopMatrix();

            glPushMatrix();//pivote3   muñeca
				glTranslatef(6, 0, 0);
             glPushMatrix();
					glTranslatef(1, 0, 0);
					glScalef(2, 2.5, 2);
					prisma();

					//glPopMatrix();
		

			///////////////////////dedos
					glPushMatrix();//pivote4
						glTranslatef(0.6, 0.4,0.4);
						glRotatef(angDG , 0, 0, 1);
						glPushMatrix();
							glTranslatef(0.0,0, 0);
							glScalef(0.20, 0.20, 0.20);
						prisma();
						//glPopMatrix();
							glTranslatef(1, 0, 0);
			
							prisma();

							glTranslatef(1, 0, 0);

							prisma();
							
							////////////////////
							glTranslatef(1.3, 0, -1.3);
							glScalef(1.5, 1.0, 1.0);
                            prisma();

							glTranslatef(-1, 0, 0);
							prisma();

							glTranslatef(-1, 0, 0);
							prisma();

							///////////////////////////////////7
							glTranslatef(0.1, 0, -1.3);
							glScalef(1.3, 1.0, 1.0);
							prisma();

							glTranslatef(1, 0, 0);
							prisma();

							glTranslatef(1, 0, 0);
							prisma();
							/////////////////////////////////////////

							glTranslatef(-0.5, 0, -1.3);
							glScalef(0.8, 1.0, 1.0);
							prisma();

							glTranslatef(-1, 0, 0);
							prisma();

							glTranslatef(-1, 0, 0);
							prisma();

							
                           glPopMatrix();
///////////////////////////////////////////gordo
						 
						   glTranslatef(8.2, 0, -0.8);
						  glRotatef(angD, 0, 1, 0);
						   glPushMatrix();
						  
                           glScalef(0.5, 0.5, 0.5);
						   prisma();

	

						
						   glTranslatef(1, 0, 0);


						   prisma();

						 

				
						   glPopMatrix();
						   glPopMatrix();
						   
						   
						
glPopMatrix();


								//glPushMatrix();//pivote5 de do2
								//glTranslatef(1, 0, 0);

								//glPushMatrix();
								//glTranslatef(1, 0.625, 0);
								//glScalef(0.25, 0.25, 0.25);
								//prisma();

								//glPopMatrix();




		
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
			transX -= 0.2f;
			break;
		case 'A':
			transX +=0.2f;
			break;
		case 'H':
			if (angBrazo < -90); {
				angBrazo += 0.5f;

			}
			break;
		case 'h':
			if (angBrazo < -90); {
				angBrazo -= 0.5f;

			}

			break;

		case 'J':
			if (angHombro < -90); {
				angHombro += 0.5f;

			}
			break;
		case 'j':
			if (angHombro < -90  ); {
				angHombro -= 0.5f;
				
			}
			
			break;


		case 'X':
			if (angDG <=-180); {
				angDG -= 0.5f;

			}

			break;
		case 'x':
			if (angDG >= 180); {
				angDG -= 0.5f;

			}

			break;


		case 'T':
			if ( 0 > angD  ); {

				angD -= 0.5f;

			}

			break;

		case 't':
			if (90 > angD); {

				angD -= 0.5f;

			}

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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



