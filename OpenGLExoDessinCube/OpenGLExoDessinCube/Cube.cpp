#include "Cube.h"

Cube::Cube(string const vertexShader, string const fragmentShader) : shader(vertexShader, fragmentShader)

{

	// Chargement du shader
	shader.charger();

	// Vertices temporaires
	float verticesTmp[] = { -1, -1, -1,  1, -1, -1,  1, -1, -1,     // Face 1
							-1, -1, -1,  -1, 1, -1,  1, 1, -1,     // Face 1
							
							       // Face 2
							       // Face 2

							      // Face 3
							      // Face 3

							        // Face 4
							        // Face 4

							     // Face 5
							     // Face 5

							         // Face 6
							 };     // Face 6

	// Couleurs temporaires
	float couleursTmp[] = { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1
							1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1
							
							           // Face 2
							           // Face 2

							           // Face 3
							           // Face 3

							           // Face 4
							           // Face 4

							           // Face 5
							           // Face 5

							           // Face 6
							 };        // Face 6



	// Copie des valeurs dans les tableaux finaux
	for (int i(0); i < 108; i++)
	{
		vertices[i] = verticesTmp[i];
		couleurs[i] = couleursTmp[i];
	}

}

Cube::~Cube()
{}

void Cube::afficher(mat4 &projection, mat4 &modelview)
{
	//Ajouter le code d'affichage du cube
}