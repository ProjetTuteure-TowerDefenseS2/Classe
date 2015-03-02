#include "Carte.h"


Carte::Carte(int tailleMap, std::string str)  ///ajouter la position pour faire de l'aléatoire
{

const char* c;
string s = "./maps/" + str;

///lecture du fichier texte
    ifstream fichier(s.c_str(), ios::in);  /// on ouvre le fichier en lecture
    int line; ///pour recup les lignes
    int *mytext = new int[3*TAILLE_MAX_MAP*TAILLE_MAX_MAP]; /// pour récupérer les données du fichier de manière linéaire.


    if(fichier)   /// si l'ouverture a réussi
    {
        /// instructions

        /*for (int i = 0; i < 3; i++)  ///on recup les données ( je suis pas sur que c'est comme ca qu'on fait mais normalement ca marche)
        {
            fichier >> mytext[i];
        }*/

        for (int i=0; i<tailleMap; i++)
        {
            fichier >> line;
            switch(line)
            {
            case 0:
                std::cout << "herbe" << std::endl;
                _tabText[i].loadFromFile("maps/herbe.png") ;
                break;

            case 1:
                std::cout << "sable+rocher" << std::endl;
                _tabText[i].loadFromFile("maps/sable+rocher.png");

                break;

            case 2:
                std::cout << "sable" << std::endl;
                _tabText[i].loadFromFile("maps/sable.png");
                break;

            default :
                cout << "Erreur, mauvaise donnée dans le fichier texte de la map" << std::endl;
                break;
            }
        }

        fichier.close();  /// on ferme le fichier
    }
    else  /// sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

