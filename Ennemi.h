#ifndef ENNEMIS_H_INCLUDED
#define ENNEMIS_H_INCLUDED

#include "string.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#include <iostream>

using namespace std;


///const float VitesseMonstre = 200;


class Ennemi{
public :
    Ennemi(std::string, sf::Sprite, float valVitesse = 150);
    Ennemi();



    void deplacement(sf::Clock & clock);
    void choixZone(sf::Texture texture, sf::RenderWindow & window, sf::Clock & clock, int posX = 0, int posY = 0);

    int supprimerPV(int degats); ///retourne les pv du monstre aprés le coup
    void afficheEnnemi(sf::RenderWindow & window) const;
    void setPos(int posX, int posY);

    bool getMoving(){return m_moving;}
    std::string getNomEn(){ return _nomEnnemi; }
    float getVitesse(){ return _vitesseDeplaEnnemi; }
    const sf::Vector2f getPosition(){return _sprite.getPosition();}
    int getPVRestant(){return _ptsVieActuel;}
    bool getVivant(){return m_vivant;}

private :
    std::string _nomEnnemi;
    int _ptsVieMax = 10;
    int _ptsVieActuel;
    int _armure = 0;
    sf::Sprite _sprite;
    float _vitesseDeplaEnnemi;

    bool m_moving;
    sf::Vector2f m_target;
    sf::Vector2f m_velocity;
    bool m_vivant = true;

};



#endif // ENNEMIS_H_INCLUDED



