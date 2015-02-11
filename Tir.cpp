#include "Tir.h"

Tir::Tir(string nomTexture)
{
    string erreur = "Tir.cpp : Impossible de charger : ";
    erreur += nomTexture;
    if (!m_texture.loadFromFile(nomTexture)){cout << erreur << endl;}

    m_tir.setTexture(m_texture);

    m_valeurRotation = 0;

    m_tirer = false;
}

Tir::~Tir()
{
    //dtor
}

void Tir::creationTir(Texture texture_Tour, const Vector2f posTour, const Vector2f posEnnemi, int vitesse) throw(string)
{
    if(posTour.x < MIN_LARGEUR){throw(string("Tir.cpp : Position X de la tour < minimum"));}
    if(posTour.x > LARGEUR){throw(string("Tir.cpp : Position X de la tour > maximum"));}

    if(posTour.y < MIN_HAUTEUR){throw(string("Tir.cpp : Position Y de la tour < minimum"));}
    if(posTour.y > HAUTEUR){throw(string("Tir.cpp : Position Y de la tour > maximum"));}

    if(posEnnemi.x < MIN_LARGEUR){throw(string("Tir.cpp : Position X de l'ennemi < minimum"));}
    if(posEnnemi.x > LARGEUR){throw(string("Tir.cpp : Position X de l'ennemi > maximum"));}

    if(posEnnemi.y < MIN_HAUTEUR){throw(string("Tir.cpp : Position Y de l'ennemi < minimum"));}
    if(posEnnemi.y > HAUTEUR){throw(string("Tir.cpp : Position Y de l'ennemi > maximum"));}

    if(vitesse < 1 || vitesse > 3){throw (string("Tir.cpp : Vitesse non correct"));}

    if(m_tirer){throw(string("Tir.cpp : Tir deja tire"));}


    m_tir.rotate(-m_valeurRotation);

    switch(vitesse)
    {
    case 1:
        m_vitesse = 0.005;
        break;
    case 2:
        m_vitesse = 0.003;
        break;
    case 3:
        m_vitesse = 0.001;
        break;
    }

    int posX = posTour.x + (texture_Tour.getSize().x / 2);
    int posY = posTour.y + (texture_Tour.getSize().y / 2);

    float valX = posEnnemi.x - posX;
    float valY = posEnnemi.y - posY;

    if(valX > valY)
    {
        if(valX > 0)
        {
            valY /= valX;
            valX /= valX;
        }
        else if(valX < 0)
        {
            valY /= -valX;
            valX /= -valX;
        }
    }
    else
    {
        if(valY > 0)
        {
            valX /= valY;
            valY /= valY;
        }
        else if(valY < 0)
        {
            valX /= -valY;
            valY /= -valY;
        }
    }

    m_valeurRotation = (pow(valX, 2) + pow(valY, 2));

    if(m_valeurRotation != 0)
    {
        m_valeurRotation = valX / sqrt(m_valeurRotation);

        m_valeurRotation = acos(m_valeurRotation);


        if(valY < 0)
        {
            m_valeurRotation = (m_valeurRotation * (360 / (2*M_PI))) + 90;
            m_valeurRotation = -m_valeurRotation;
        }
        else
        {
            m_valeurRotation = (m_valeurRotation * (360 / (2*M_PI))) - 90;
        }
        m_tir.rotate(m_valeurRotation);

        m_tirer = true;

        m_tir.setPosition(posX, posY);

        if(valX < -1)
        {
            valY /= -valX;
            valX /= -valX;
        }
        else if (valY < -1)
        {
            valX /= -valY;
            valY /= -valY;
        }
        m_valeurDeplacement_X = valX;
        m_valeurDeplacement_Y = valY;
    }
    m_clock.restart();
}

void Tir::deplacementTir()
{
    if(m_tirer)
    {
        m_temps = m_clock.getElapsedTime();
        if(m_temps.asSeconds() >= m_vitesse)
        {
            m_tir.move(m_valeurDeplacement_X, m_valeurDeplacement_Y);
            m_clock.restart();
        }
    }
}

void Tir::afficheTir(RenderWindow window)
{
    if(m_tirer)
    {
        window.draw(m_tir);
    }
}

bool Tir::collisionEnnemi(Texture ennemi, const Vector2f posEnnemi) const
{
    return (((posEnnemi.x < (m_tir.getPosition().x + m_texture.getSize().x)) && ((posEnnemi.x + ennemi.getSize().x) > m_tir.getPosition().x)) &&
            ((posEnnemi.y < (m_tir.getPosition().y + m_texture.getSize().y)) && ((posEnnemi.y + ennemi.getSize().y) > m_tir.getPosition().y)));
}

void Tir::verifDepassementEcran()
{
    if(m_tir.getPosition().x > LARGEUR || m_tir.getPosition().x < MIN_LARGEUR || m_tir.getPosition().y < MIN_HAUTEUR || m_tir.getPosition().y > HAUTEUR)
    {
        m_tirer = false;
    }
}


