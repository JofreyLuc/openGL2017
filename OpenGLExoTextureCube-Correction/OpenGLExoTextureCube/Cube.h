#ifndef DEF_CUBE
#define DEF_CUBE

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"


using namespace std;
using namespace glm;

// Classe Cube

class Cube
{
    public:

    Cube(string const vertexShader, string const fragmentShader);
    ~Cube();

    void afficher(mat4 &projection, mat4 &modelview);


    protected:

    Shader shader;
    float sommets[108];
    float couleurs[108];
};

#endif
