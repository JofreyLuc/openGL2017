#ifndef SCENEOPENGL_H
#define SCENEOPENGL_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <GL\glew.h>

using namespace std;

class SceneOpenGL
{
public:
	SceneOpenGL(string titre, int largeur, int hauteur);
	~SceneOpenGL();

	bool initialiserFenetre();
	bool initGL();
	void bouclePrincipale();


private:
	string titreFenetre;
	int largeurFenetre;
	int hauteurFenetre;

	SDL_Window* fenetre;
	SDL_GLContext contexteOpenGL;
	SDL_Event evenements;
};

#endif