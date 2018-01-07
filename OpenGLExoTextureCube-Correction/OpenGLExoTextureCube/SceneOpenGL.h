#ifndef DEF_SCENEOPENGL
#define DEF_SCENEOPENGL

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL.h>
#include <iostream>
#include <string>
#include "Shader.h"
#include "Cube.h"
#include "Input.h"
#include "Texture.h"
#include "Caisse.h"
#include "Camera.h"


// Classe

class SceneOpenGL
{
    public:

    SceneOpenGL(string titreFenetre, int largeurFenetre, int hauteurFenetre);
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

