#include "Cube.h"

Cube::Cube(float taille, string const vertexShader, string const fragmentShader) : shader(vertexShader, fragmentShader)

{

	// Chargement du shader
	shader.charger();

	// Division de la taille
	taille /= 2;

	// Vertices temporaires
	float verticesTmp[] = { -taille, -taille, -taille, taille, -taille, -taille, taille, taille, -taille,     // Face 1
							-taille, -taille, -taille, -taille, taille, -taille, taille, taille, -taille,     // Face 1

							taille, -taille, taille, taille, -taille, -taille, taille, taille, -taille,       // Face 2
							taille, -taille, taille, taille, taille, taille, taille, taille, -taille,         // Face 2

							-taille, -taille, taille, taille, -taille, taille, taille, -taille, -taille,      // Face 3
							-taille, -taille, taille, -taille, -taille, -taille, taille, -taille, -taille,    // Face 3

							-taille, -taille, taille, taille, -taille, taille, taille, taille, taille,        // Face 4
							-taille, -taille, taille, -taille, taille, taille, taille, taille, taille,        // Face 4

							-taille, -taille, -taille, -taille, -taille, taille, -taille, taille, taille,     // Face 5
							-taille, -taille, -taille, -taille, taille, -taille, -taille, taille, taille,     // Face 5

							-taille, taille, taille, taille, taille, taille, taille, taille, -taille,         // Face 6
							-taille, taille, taille, -taille, taille, -taille, taille, taille, -taille };     // Face 6

	// Couleurs temporaires
	float couleursTmp[] = { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1
							1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1

							0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 2
							0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 2

							0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 3
							0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 3

							1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 4
							1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 4

							0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 5
							0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 5

							0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 6
							0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };          // Face 6

	// Copie des valeurs dans les tableaux finaux
	for (int i(0); i < 108; i++)
	{
		vertices[i] = verticesTmp[i];
		couleurs[i] = couleursTmp[i];
	}

}

Cube::~Cube()
{}

void Cube::afficher(glm::mat4 &projection, glm::mat4 &modelview)
{
	// Activation du shader
	glUseProgram(shader.getProgramID());

		// Envoi des vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		// Envoi de la couleur
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
		glEnableVertexAttribArray(1);

		// Envoi des matrices
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

		// Rendu
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// D�sactivation des tableaux
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);

	// D�sactivation du shader
	glUseProgram(0);

}