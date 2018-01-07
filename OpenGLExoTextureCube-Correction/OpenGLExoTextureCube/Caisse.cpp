#include "Caisse.h"


// Permet d'éviter la ré-écriture du namespace glm::

using namespace glm;


// Constructeur et Destructeur

Caisse::Caisse(string const vertexShader, string const fragmentShader, string const text) : Cube(vertexShader, fragmentShader),
                                                                                                                            texture(text)
{
    // Chargement de la texture

    texture.charger();


    // Coordonnées de texture temporaires

    float coordTextureTmp[] = {0, 0,   1, 0,   1, 1,     // Face 1
                               0, 0,   0, 1,   1, 1,     // Face 1

                               0, 0,   1, 0,   1, 1,     // Face 2
                               0, 0,   0, 1,   1, 1,     // Face 2

                               0, 0,   1, 0,   1, 1,     // Face 3
                               0, 0,   0, 1,   1, 1,     // Face 3

                               0, 0,   1, 0,   1, 1,     // Face 4
                               0, 0,   0, 1,   1, 1,     // Face 4

                               0, 0,   1, 0,   1, 1,     // Face 5
                               0, 0,   0, 1,   1, 1,     // Face 5

                               0, 0,   1, 0,   1, 1,     // Face 6
                               0, 0,   0, 1,   1, 1};    // Face 6


    // Copie des valeurs dans le tableau final

    for(int i (0); i < 72; i++)
        coordTexture[i] = coordTextureTmp[i];
}


Caisse::~Caisse()
{

}


// Méthodes

void Caisse::afficher(mat4 &projection, mat4 &modelview)
{
    // Activation du shader

    glUseProgram(shader.getProgramID());


        // Envoi des vertices

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, sommets);
        glEnableVertexAttribArray(0);


        // Envoi des coordonnées de texture

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, coordTexture);
        glEnableVertexAttribArray(2);


        // Envoi des matrices

        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));


        // Verrouillage de la texture

        glBindTexture(GL_TEXTURE_2D, texture.getID());


        // Rendu

        glDrawArrays(GL_TRIANGLES, 0, 36);


        // Déverrouillage de la texture

        glBindTexture(GL_TEXTURE_2D, 0);


        // Désactivation des tableaux

        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(0);


    // Désactivation du shader

    glUseProgram(0);
}
