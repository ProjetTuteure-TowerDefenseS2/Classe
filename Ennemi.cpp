#include "ennemis.h"

// ###############################################################
// remarque générale : Vérifie tes param : doivent-ils etre const? doivent-ils etre en ref  ?


// #Martin# OMG une variable d'une lettre
float length(sf::Vector2f v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

Ennemi::Ennemi()
{

}

// #Martin# OMG "str" le nom le plus parlant au monde
Ennemi::Ennemi(std::string str, sf::Sprite sp, float valVitesse)
{

///coordonées d'apparition du monstre

///attribution du nom du monstre avec celui passé en parametre
    _nomEnnemi = str;

///attribution du sprite pour l'interface graphique
    _sprite = sp;

///A completer : attribution des point de vie max, de l'armure et de la vitesse en fonction du type de monstre symboliser par son nom (ici str)

    m_moving = false;
    _ptsVieActuel = _ptsVieMax;
    _vitesseDeplaEnnemi = valVitesse;
}


int Ennemi::supprimerPV(int degats)
{

    if(_armure ==0)
    {
        _ptsVieActuel -= degats;
    }

    else
    {
        degats /= _armure;
        _ptsVieActuel -= degats; ///pts de vie actuel est un float dont les virgules sont pris en compte
    }

    if(_ptsVieActuel <= 0)
    {
        _sprite.setPosition(-100, - 100);
        m_vivant = false;
        _ptsVieActuel = 0;
        cout << "le monstre a ete tue !\n";
        ///this.~Ennemi();
    }

    return _ptsVieActuel;
}




void Ennemi::deplacement(sf::Clock & clock)
{
    if (m_moving && m_vivant)
    {
        // #Martin# Es tu vraiment sur de ça ? tu passes le clock en reference, que ce passe t'il si tu gere plusieurs monstre ?
        // je dis pas que c'est faux, je dis que c'est suspect
        sf::Time elapsed = clock.restart();
        _sprite.move(m_velocity * elapsed.asSeconds());

        if (length(m_target - _sprite.getPosition()) < 5)
            m_moving = false;
    }
}

void Ennemi::choixZone(sf::Texture texture, sf::RenderWindow & window, sf::Clock & clock, int posX, int posY)
{
    sf::Vector2i cursor(posX - (texture.getSize().x / 2), posY - (texture.getSize().y / 2));
    m_target = window.mapPixelToCoords(cursor);
    m_velocity = m_target - _sprite.getPosition();
    m_velocity = m_velocity / length(m_velocity) * _vitesseDeplaEnnemi;


    m_moving = true;
    clock.restart();
}


void Ennemi::afficheEnnemi(sf::RenderWindow & window ) const
{
    if(m_vivant)
    {
        window.draw(_sprite);
    }
}

void Ennemi::setPos(int posX, int posY)
{
    _sprite.setPosition(posX, posY);
}



