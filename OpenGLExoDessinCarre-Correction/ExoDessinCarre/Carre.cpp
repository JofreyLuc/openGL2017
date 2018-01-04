#include "Carre.h"

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
	// Envoi des vertices

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, sommets);
	glEnableVertexAttribArray(0);

	// On affiche le Carre

	glDrawArrays(GL_TRIANGLES, 0, 6);


	// Désactivation des tableaux
	glDisableVertexAttribArray(0);
}

