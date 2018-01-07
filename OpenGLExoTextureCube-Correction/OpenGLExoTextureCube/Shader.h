#ifndef DEF_SHADER
#define DEF_SHADER

#include <GL/glew.h>

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Classe Shader

class Shader
{
    public:

    Shader();
    Shader(Shader const &shaderACopier);
    Shader(string vertexSource, string fragmentSource);
    ~Shader();

    Shader& operator=(Shader const &shaderACopier);

    bool charger();
    bool compilerShader(GLuint &shader, GLenum type, string const &fichierSource);
    GLuint getProgramID() const;


    private:

    GLuint vertexID;
    GLuint fragmentID;
    GLuint programID;

    string vertexSource;
    string fragmentSource;
};

#endif
