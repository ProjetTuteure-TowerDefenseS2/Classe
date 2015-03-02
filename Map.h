#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include "ennemis.h"
#include <fstream>
#include <sys/types.h>
#include <stdio.h>


using namespace std;
const int MAX_ENNEMIS = 50;
const int TAILLE_MAX_MAP = 300;
class Carte{

public :
    Carte(int tailleMap, std::string str);
    ///faudra ajouter un setItineraire() et un setZoneInterdite() pour les guider les deplacements dans la map

private :
    int _nbEnnemisTot;
    Ennemi _tabEnnemi[MAX_ENNEMIS];
    /// ajouter un nb pour chaque type de mostre a apparaitre

    std::string _titre;

    int _tabZoneInterdite[]; ///zone de la carte innaccessibles
    int _Iteneraire[]; /// chemin a suivre des ennemis
    sf::Texture _tabText[TAILLE_MAX_MAP];


};

#endif // CARTE_H_INCLUDED
