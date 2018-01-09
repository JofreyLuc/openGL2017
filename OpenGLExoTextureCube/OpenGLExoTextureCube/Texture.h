#ifndef DEF_TEXTURE
#define DEF_TEXTURE

#include <GL/glew.h>
#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include <string>

using namespace std;
// Classe Textures

class Texture
{
    public:

    Texture();
    Texture(Texture const &textureACopier);
    Texture(string fichierImage);
    ~Texture();

    Texture& operator=(Texture const &textureACopier);
    bool charger();
    SDL_Surface* inverserPixels(SDL_Surface *imageSource) const;

    GLuint getID() const;
    void setFichierImage(const string &fichierImage);


    private:

    GLuint id;
    string fichierImage;
};

#endif
