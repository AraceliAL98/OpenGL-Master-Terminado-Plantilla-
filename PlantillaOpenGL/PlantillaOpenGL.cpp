// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
/*#include <conio.h>*/

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

void dibujar()
{
	glBegin(GL_TRIANGLES);
	
		glColor3f(1, 0, 0.2);
		glVertex3f(0, 1, 0);
		glVertex3f(-1, -1, 0);
		glVertex3f(1, -1, 0);
	
	glEnd();


}

void actualizar()
{



}

int main()
{
	/*Crear un contexto 

	°Un contexto es una ventana de un sistema operativo
	°OpenGL no gestiona el iso de ventanas*/

	//Declaramos un aputador de ventana.

	GLFWwindow *window;
	// Si no se pudo iniciar glfw terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	window =
		glfwCreateWindow(1024, 728, "Ventana", NULL, NULL);
	if (!window) {
		glfwTerminate();
			exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK)
	{
		cout << 
			glewGetErrorString(errorGlew);

	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL:"
		<< versionGL;
	
	//ciclo de dibujo(draw loop)

	while (!glfwWindowShouldClose(window)) {
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(1, 0.6, 0.4, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar Buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();

	
		
	}

		glfwDestroyWindow(window);
		glfwTerminate();
	
	
	return 0;
}

