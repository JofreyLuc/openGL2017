#include "SceneOpenGL.h"
#include "Carre.h"
#include "Shader.h"
// Includes OpenGL

// Includes GLM

#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>


// Autres includes

#include <SDL.h>
#include <iostream>
#include <string>
#include "Shader.h"


SceneOpenGL::SceneOpenGL(string titre, int largeur, int hauteur)
{
	titreFenetre = titre;
	largeurFenetre = largeur;
	hauteurFenetre = hauteur;
	fenetre = 0;
	contexteOpenGL = 0;
}

SceneOpenGL::~SceneOpenGL()
{
	SDL_GL_DeleteContext(this->contexteOpenGL);
	SDL_DestroyWindow(this->fenetre);
	SDL_Quit();
}

bool SceneOpenGL::initialiserFenetre()
{
	// Initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Cr�ation de la fen�tre
	this->fenetre = SDL_CreateWindow(this->titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->largeurFenetre, this->hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (this->fenetre == 0)
	{
		cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	// Cr�ation du contexte OpenGL
	this->contexteOpenGL = SDL_GL_CreateContext(this->fenetre);
	if (this->contexteOpenGL == 0)
	{
		cout << SDL_GetError() << endl;
		SDL_DestroyWindow(this->fenetre);
		SDL_Quit();
		return false;
	}
	return true;
}

bool SceneOpenGL::initGL()

{
	#ifdef WIN32

		// On initialise GLEW
		GLenum initialisationGLEW(glewInit());

		// Si l'initialisation a �chou� :
		if (initialisationGLEW != GLEW_OK)
		{
			// On affiche l'erreur gr�ce � la fonction : glewGetErrorString(GLenum code)
			cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << endl;

			// On quitte la SDL
			SDL_GL_DeleteContext(this->contexteOpenGL);
			SDL_DestroyWindow(this->fenetre);
			SDL_Quit();
			return false;
		}

	#endif

	// Tout s'est bien pass�, on retourne true
	return true;
}

void SceneOpenGL::bouclePrincipale()
{

	// Variables
	bool terminer(false);

	//Cr�ation du carre
	Carre carre = Carre();

	// Boucle principale
	while (!terminer)
	{
		// Gestion des �v�nements
		SDL_WaitEvent(&(this->evenements));
		if (this->evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;

		// Nettoyage de l'�cran
		glClear(GL_COLOR_BUFFER_BIT);

		//Affichage du carre
		carre.afficher();

		// Actualisation de la fen�tre
		SDL_GL_SwapWindow(this->fenetre);
	}
}