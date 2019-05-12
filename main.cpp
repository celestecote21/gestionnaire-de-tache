#include <iostream>
#include <string>
#include "Tache.hpp"
#include <map>
#include "Category.hpp"

using namespace std;

int main()
{
    Category biblio1 = Category();
    cout << "bienvenue dans le meilleur des gestionnaires des taches,\n voici les options qui sont possible" << endl;
    cout << "\t 1. ajouter une tache" << endl;
    cout << "\t 2. Voir les taches a faire" << endl;
    cout << "\t 3. supprimer une tache" << endl;

    int choix;
    cin >> choix;

    switch (choix)
    {
    case 1:
        biblio1.addTache("coucou", "dire bonjour");
        break;
    
    default:
        break;
    }

    cout << choix;
}