#ifndef DEF_SHADER
#define DEF_SHADER

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>


// Classe Shader

using namespace std;

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

    GLuint m_vertexID;
    GLuint m_fragmentID;
    GLuint m_programID;

    string m_vertexSource;
    string m_fragmentSource;
};

#endif
