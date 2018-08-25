//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}
/*void dcx(float inicio, float fin, float posy,float var)
{

	for (float i = inicio; i <fin; i+=var)
	{
		glVertex3f(i, posy, -1.0f);
	}

}

void dcy(float inicio, float fin, float posx,float var)
{

	for (float i = inicio; i <fin; i +=var)
	{
		glVertex3f(posx,i, -1.0f);
	}

}*/
void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	
	//C
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(9.0f, 0.0f, -1.0f);
	glVertex3f(9.0f, 3.0f, -1.0f);
	glVertex3f(3.0f, 3.0f, -1.0f);
    

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f, 12.0f, -1.0f);
	glVertex3f(9.0f, 12.0f, -1.0f);
	glVertex3f(9.0f, 15.0f, -1.0f);
	glVertex3f(0.0f, 15.0f, -1.0f);
	

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f, 3.0f, -1.0f);
	glVertex3f(3.0f, 12.0f, -1.0f);
	glVertex3f(0.0f, 15.0f, -1.0f);
	glEnd();


	//G
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, -1.0f);
	glVertex3f(19.0f, 0.0f, -1.0f);
	glVertex3f(19.0f, 3.0f, -1.0f);
	glVertex3f(13.0f, 3.0f, -1.0f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.3f);
	glVertex3f(15.0f, 3.0f, -1.0f);
	glVertex3f(20.0f, 3.0f, -1.0f);
	glVertex3f(20.0f, 6.0f, -1.0f);
	glVertex3f(15.0f, 6.0f, -1.0f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.0f, 0.0f, -1.0f);
	glVertex3f(21.0f, 0.0f, -1.0f);
	glVertex3f(21.0f, 6.0f, -1.0f);
	glVertex3f(18.0f, 6.0f, -1.0f);

	//arriba
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(13.0f, 12.0f, -1.0f);
	glVertex3f(19.0f, 12.0f, -1.0f);
	glVertex3f(19.0f, 15.0f, -1.0f);
	glVertex3f(10.0f, 15.0f, -1.0f);

	//en medio 
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, -1.0f);
	glVertex3f(13.0f, 3.0f, -1.0f);
	glVertex3f(13.0f, 12.0f, -1.0f);
	glVertex3f(10.0f, 15.0f, -1.0f);
	glEnd();



	//e
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.96f, 0.0f);
	glVertex3f(22.0f, 0.0f, -1.0f);
	glVertex3f(29.0f, 0.0f, -1.0f);
	glVertex3f(29.0f, 3.0f, -1.0f);
	glVertex3f(22.0f, 3.0f, -1.0f);
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.96f, 0.0f);
	glVertex3f(22.0f, 3.0f, -1.0f);
	glVertex3f(25.0f, 3.0f, -1.0f);
	glVertex3f(25.0f, 12.0f, -1.0f);
	glVertex3f(22.0f, 12.0f, -1.0f);
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.96f, 0.0f);
	glVertex3f(22.0f, 12.0f, -1.0f);
	glVertex3f(29.0f, 12.0f, -1.0f);
	glVertex3f(29.0f, 15.0f, -1.0f);
	glVertex3f(22.0f, 15.0f, -1.0f);
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.96f, 0.0f);
	glVertex3f(25.0f, 6.0f, -1.0f);
	glVertex3f(29.0f, 6.0f, -1.0f);
	glVertex3f(29.0f, 9.0f, -1.0f);
	glVertex3f(25.0f, 9.0f, -1.0f);
	glEnd();


	//H
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(31.0f, 0.0f, -1.0f);
	glVertex3f(35.0f, 0.0f, -1.0f);
	glVertex3f(35.0f, 15.0f, -1.0f);
	glVertex3f(31.0f, 15.0f, -1.0f);
	

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(35.0f, 6.0f, -1.0f);
	glVertex3f(39.0f, 6.0f, -1.0f);
	glVertex3f(39.0f, 9.0f, -1.0f);
	glVertex3f(35.0f, 9.0f, -1.0f);
	
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(39.0f, 0.0f, -1.0f);
	glVertex3f(42.0f, 0.0f, -1.0f);
	glVertex3f(42.0f, 15.0f, -1.0f);
	glVertex3f(39.0f, 15.0f, -1.0f);
	glEnd();
	

	

	glFlush();

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

	// Ortogonal
	//glOrtho(-10,10,-10,10,0.1,2);
	glOrtho(0, 50, 0,50, 0.1, 2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}


// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (400, 400);	// Tamaño de la Ventana
  glutInitWindowPosition (200,200);	//Posicion de la Ventana
  glutCreateWindow    ("reporte practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

