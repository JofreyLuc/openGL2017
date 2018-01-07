#include <SDL.h>
#include <iostream>

// SceneOpenGL.cpp : Contient notre première scène openGL

int main(int argc, char* argv[])
{

	// Notre fenêtre

	SDL_Window* fenetre(0);
	SDL_GLContext contexteOpenGL(0);

	SDL_Event evenements;
	bool terminer(false);


	// Initialisation de la SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}


	// Version d'OpenGL

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);


	// Double Buffer

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// Création de la fenêtre

	/**
	Initialisation de la fenêtre à ajouter ici
	**/

	if (fenetre == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}


	// Création du contexte OpenGL

	/**
	Initialisation du contexte OpenGL à ajouter ici
	**/

	if (contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(fenetre);
		SDL_Quit();

		return -1;
	}


	// Boucle principale

	while (!terminer)
	{
		SDL_WaitEvent(&evenements);

		if (evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = true;
	}


	// On quitte la SDL

	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();

	return 0;

}