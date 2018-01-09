#include "Carre.h"
#include "Shader.h"
// Constructeur et Destructeur

Carre::Carre()
{
	float sommetsTemp[] = { -0.5, 0.5, 0.5, 0.5, 0.5, -0.5, //Triangle 1
							0.5, -0.5, -0.5, -0.5, -0.5, 0.5 //Triangle 2
						  };
	for (int i = 0; i < 12; i++)
	{
		sommets[i] = sommetsTemp[i];
	}
}

Carre::~Carre()
{

}

// Méthodes

void Carre::afficher()
{
	//Ici on définit le tableau de couleurs
	
    //Initialisation de shaderCouleur
	
	//Chargement de shaderCouleur


	glUseProgram(/*Mettre ici le program_id du shader*/);


	// Envoi des vertices

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, sommets);
	glEnableVertexAttribArray(0);


	// Envoi des couleurs

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
	glEnableVertexAttribArray(1);


	// On affiche le Carre

	glDrawArrays(GL_TRIANGLES, 0, 6);


	// Désactivation des tableaux
	glDisableVertexAttribArray(0);
	/* Désactiver le tableau des couleurs ici*/

}

