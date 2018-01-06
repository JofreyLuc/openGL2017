#include "Camera.h"


// Permet d'�viter la r�-�criture du namespace glm::

using namespace glm;


// Constructeurs et Destructeur

Camera::Camera() : m_phi(0.0), m_theta(0.0), m_orientation(), m_axeVertical(0, 0, 1), m_deplacementLateral(), m_position(), m_pointCible(), m_sensibilite(0.0), m_vitesse(0.0)
{

}


Camera::Camera(glm::vec3 position, glm::vec3 pointCible, glm::vec3 axeVertical, float sensibilite, float vitesse) : m_phi(0.0), m_theta(0.0), m_orientation(),
                                                                                                                    m_axeVertical(axeVertical), m_deplacementLateral(),
                                                                                                                    m_position(position), m_pointCible(pointCible),
                                                                                                                    m_sensibilite(sensibilite), m_vitesse(vitesse)
{
    // Actualisation du point cibl�

    setPointcible(pointCible);
}


Camera::~Camera()
{

}


// M�thodes

void Camera::orienter(int xRel, int yRel)
{
    // R�cup�ration des angles

    m_phi += -yRel * m_sensibilite;
    m_theta += -xRel * m_sensibilite;


    // Limitation de l'angle phi

    if(m_phi > 89.0)
        m_phi = 89.0;

    else if(m_phi < -89.0)
        m_phi = -89.0;


    // Conversion des angles en radian

    float phiRadian = m_phi * M_PI / 180;
    float thetaRadian = m_theta * M_PI / 180;


    // Si l'axe vertical est l'axe X

    if(m_axeVertical.x == 1.0)
    {
        // Calcul des coordonn�es sph�riques

        m_orientation.x = sin(phiRadian);
        m_orientation.y = cos(phiRadian) * cos(thetaRadian);
        m_orientation.z = cos(phiRadian) * sin(thetaRadian);
    }


    // Si c'est l'axe Y

    else if(m_axeVertical.y == 1.0)
    {
        // Calcul des coordonn�es sph�riques

        m_orientation.x = cos(phiRadian) * sin(thetaRadian);
        m_orientation.y = sin(phiRadian);
        m_orientation.z = cos(phiRadian) * cos(thetaRadian);
    }


    // Sinon c'est l'axe Z

    else
    {
        // Calcul des coordonn�es sph�riques

        m_orientation.x = cos(phiRadian) * cos(thetaRadian);
        m_orientation.y = cos(phiRadian) * sin(thetaRadian);
        m_orientation.z = sin(phiRadian);
    }


    // Calcul de la normale

    m_deplacementLateral = cross(m_axeVertical, m_orientation);
    m_deplacementLateral = normalize(m_deplacementLateral);


    // Calcul du point cibl� pour OpenGL

    m_pointCible = m_position + m_orientation;
}


void Camera::deplacer(Input const &input)
{
    //===========================================
	// Ici votre code
	//La camera est orient� par la souris et d�plac� par des touches du claviers

}


void Camera::lookAt(glm::mat4 &modelview)
{
    // Actualisation de la vue dans la matrice

    modelview = glm::lookAt(m_position, m_pointCible, m_axeVertical);
}


// Getters et Setters

void Camera::setPointcible(glm::vec3 pointCible)
{
    // Calcul du vecteur orientation

    m_orientation = m_pointCible - m_position;
    m_orientation = normalize(m_orientation);


    // Si l'axe vertical est l'axe X

    if(m_axeVertical.x == 1.0)
    {
        // Calcul des angles

        m_phi = asin(m_orientation.x);
        m_theta = acos(m_orientation.y / cos(m_phi));

        if(m_orientation.y < 0)
            m_theta *= -1;
    }


    // Si c'est l'axe Y

    else if(m_axeVertical.y == 1.0)
    {
        // Calcul des angles

        m_phi = asin(m_orientation.y);
        m_theta = acos(m_orientation.z / cos(m_phi));

        if(m_orientation.z < 0)
            m_theta *= -1;
    }


    // Sinon c'est l'axe Z

    else
    {
        // Calcul des angles

        m_phi = asin(m_orientation.x);
        m_theta = acos(m_orientation.z / cos(m_phi));

        if(m_orientation.z < 0)
            m_theta *= -1;
    }


    // Conversion en degr�s

    m_phi = m_phi * 180 / M_PI;
    m_theta = m_theta * 180 / M_PI;
}


void Camera::setPosition(glm::vec3 position)
{
    // Mise � jour de la position

    m_position = position;


    // Actualisation du point cibl�

    m_pointCible = m_position + m_orientation;
}


float Camera::getSensibilite() const
{
    return m_vitesse;
}


float Camera::getVitesse() const
{
    return m_vitesse;
}


void Camera::setSensibilite(float sensibilite)
{
    m_sensibilite = sensibilite;
}


void Camera::setVitesse(float vitesse)
{
    m_vitesse = vitesse;
}
