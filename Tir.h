#ifndef TIR_H
#define TIR_H

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int HAUTEUR = 800;
const int LARGEUR = 1300;

const int MIN_HAUTEUR = 0;
const int MIN_LARGEUR = 0;

class Tir
{
    public:
        Tir(string nomTexture);
        virtual ~Tir();
        void creationTir(Texture texture_Tour, const Vector2f posTour, const Vector2f posEnnemi, int vitesse = 1, int zone = 1) throw(string);
        void deplacementTir();
        void afficheTir(RenderWindow window);
        bool collisionEnnemi(Texture ennemi, const Vector2f posEnnemi);
        void verifDepassementEcran();
        Sprite getSprite() const {return m_tir;}
        bool getTirer() const {return m_tirer;}

    protected:
    private:

        Texture m_texture;
        Sprite m_tir;
        float m_vitesse;
        float m_tempsZone;
        float m_valeurDeplacement_X;
        float m_valeurDeplacement_Y;
        float m_valeurRotation;
        bool m_tirer;
        Clock m_clock;
        Clock m_clockZone;
};

#endif // TIR_H
