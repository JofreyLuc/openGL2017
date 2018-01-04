#ifndef DEF_CARRE
#define DEF_CARRE

#include <GL/glew.h>
#include <string>

using namespace std;

// Classe Carre

class Carre
{

public:

	Carre();
	~Carre();

	void afficher();

	float sommets[12];

};

#endif
