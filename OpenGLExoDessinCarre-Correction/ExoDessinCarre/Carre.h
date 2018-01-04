#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE

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
