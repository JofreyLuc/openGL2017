#ifndef DEF_CAISSE
#define DEF_CAISSE
// Includes

#include "Cube.h"
#include "Texture.h"
#include <string>


// Classe Caisse

class Caisse : public Cube
{
    public:

    Caisse(string const vertexShader, string const fragmentShader, string const texture);
    ~Caisse();

    void afficher(mat4 &projection, mat4 &modelview);


    private:

    Texture texture;
    float coordTexture[72];
};

#endif
