#include "SceneOpenGL.h"
#include "Carre.h"

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

	// Création de la fenêtre
	this->fenetre = SDL_CreateWindow(this->titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->largeurFenetre, this->hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (this->fenetre == 0)
	{
		cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	// Création du contexte OpenGL
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

		// Si l'initialisation a échoué :
		if (initialisationGLEW != GLEW_OK)
		{
			// On affiche l'erreur grâce à la fonction : glewGetErrorString(GLenum code)
			cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << endl;

			// On quitte la SDL
			SDL_GL_DeleteContext(this->contexteOpenGL);
			SDL_DestroyWindow(this->fenetre);
			SDL_Quit();
			return false;
		}

	#endif

	// Tout s'est bien passé, on retourne true
	return true;
}


//--------------------------------ZONE DE MODIFICATION A PARTIR D'ICI------------------------------
void SceneOpenGL::bouclePrincipale()
{
	// Variables
	bool terminer(false);

	//Création du triangle
	Carre carre = Carre();

	// Boucle principale
	while (!terminer)
	{
		// Gestion des évènements
		SDL_WaitEvent(&(this->evenements));
		if (this->evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;

		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT);

		//Affichage du triangle
		carre.afficher();

		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(this->fenetre);
	}
}
//-------------------------------FIN DE LA ZONE DE MODIFICATIONS----------------------------------