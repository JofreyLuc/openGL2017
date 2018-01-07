#include "Shader.h"

// Constructeurs et Destructeur

Shader::Shader() : vertexID(0), fragmentID(0), programID(0), vertexSource(), fragmentSource()
{
}


Shader::Shader(Shader const &shaderACopier)
{
    // Copie des fichiers sources

    vertexSource = shaderACopier.vertexSource;
    fragmentSource = shaderACopier.fragmentSource;


    // Chargement du nouveau shader

    charger();
}


Shader::Shader(string vertexSource, string fragmentSource) : vertexID(0), fragmentID(0), programID(0),
                                                                       vertexSource(vertexSource), fragmentSource(fragmentSource)
{
}


Shader::~Shader()
{
    // Destruction du shader

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
    glDeleteProgram(programID);
}


// Méthodes

Shader& Shader::operator=(Shader const &shaderACopier)
{
    // Copie des fichiers sources

    vertexSource = shaderACopier.vertexSource;
    fragmentSource = shaderACopier.fragmentSource;


    // Chargement du nouveau shader

    charger();


    // Retour du pointeur this

    return *this;
}


bool Shader::charger()
{
    // Destruction d'un éventuel ancien Shader

    if(glIsShader(vertexID) == GL_TRUE)
        glDeleteShader(vertexID);

    if(glIsShader(fragmentID) == GL_TRUE)
        glDeleteShader(fragmentID);

    if(glIsProgram(programID) == GL_TRUE)
        glDeleteProgram(programID);


    // Compilation des shaders

    if(!compilerShader(vertexID, GL_VERTEX_SHADER, vertexSource))
        return false;

    if(!compilerShader(fragmentID, GL_FRAGMENT_SHADER, fragmentSource))
        return false;


    // Création du programme

    programID = glCreateProgram();


    // Association des shaders

    glAttachShader(programID, vertexID);
    glAttachShader(programID, fragmentID);


    // Verrouillage des entrées shader

    glBindAttribLocation(programID, 0, "in_Vertex");
    glBindAttribLocation(programID, 1, "in_Color");
    glBindAttribLocation(programID, 2, "in_TexCoord0");


    // Linkage du programme

    glLinkProgram(programID);


    // Vérification du linkage

    GLint erreurLink(0);
    glGetProgramiv(programID, GL_LINK_STATUS, &erreurLink);


    // S'il y a eu une erreur

    if(erreurLink != GL_TRUE)
    {
        // Récupération de la taille de l'erreur

        GLint tailleErreur(0);
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &tailleErreur);


        // Allocation de mémoire

        char *erreur = new char[tailleErreur + 1];


        // Récupération de l'erreur

        glGetShaderInfoLog(programID, tailleErreur, &tailleErreur, erreur);
        erreur[tailleErreur] = '\0';


        // Affichage de l'erreur

        cout << erreur << endl;


        // Libération de la mémoire et retour du booléen false

        delete[] erreur;
        glDeleteProgram(programID);

        return false;
    }



    // Sinon c'est que tout s'est bien passé

    else
        return true;
}


bool Shader::compilerShader(GLuint &shader, GLenum type, string const &fichierSource)
{
    // Création du shader

    shader = glCreateShader(type);


    // Vérification du shader

    if(shader == 0)
    {
        cout << "Erreur, le type de shader (" << type << ") n'existe pas" << endl;
        return false;
    }


    // Flux de lecture

    ifstream fichier(fichierSource.c_str());


    // Test d'ouverture

    if(!fichier)
    {
        cout << "Erreur le fichier " << fichierSource << " est introuvable" << endl;
        glDeleteShader(shader);

        return false;
    }


    // Strings permettant de lire le code source

    string ligne;
    string codeSource;


    // Lecture

    while(getline(fichier, ligne))
        codeSource += ligne + '\n';


    // Fermeture du fichier

    fichier.close();


    // Récupération de la chaine C du code source

    const GLchar* chaineCodeSource = codeSource.c_str();


    // Envoi du code source au shader

    glShaderSource(shader, 1, &chaineCodeSource, 0);


    // Compilation du shader

    glCompileShader(shader);


    // Vérification de la compilation

    GLint erreurCompilation(0);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &erreurCompilation);


    // S'il y a eu une erreur

    if(erreurCompilation != GL_TRUE)
    {
        // Récupération de la taille de l'erreur

        GLint tailleErreur(0);
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &tailleErreur);


        // Allocation de mémoire

        char *erreur = new char[tailleErreur + 1];


        // Récupération de l'erreur

        glGetShaderInfoLog(shader, tailleErreur, &tailleErreur, erreur);
        erreur[tailleErreur] = '\0';


        // Affichage de l'erreur

        cout << erreur << endl;


        // Libération de la mémoire et retour du booléen false

        delete[] erreur;
        glDeleteShader(shader);

        return false;
    }


    // Sinon c'est que tout s'est bien passé

    else
        return true;
}


// Getter

GLuint Shader::getProgramID() const
{
    return programID;
}
