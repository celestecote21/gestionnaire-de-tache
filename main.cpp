#include <iostream>
#include <string>
#include "Tache.hpp"
#include <map>
#include "cli.hpp"
#include "Category.hpp"
#include "actionCat.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Category biblio1 = Category();
    bool cont(true);
    int choix;
    string strChoix;
    biblio1.load();
    if (argc > 1)
        readArg(argc, argv, &biblio1);

    do
    {  
        
        cout << "bienvenue dans le meilleur des gestionnaires des taches,\n voici les options qui sont possible" << endl;
        cout << "\t 1. ajouter une tache" << endl;
        cout << "\t 2. Voir les taches a faire" << endl;
        cout << "\t 3. supprimer une tache" << endl;
        cout << "\t 4. sauvegarder les taches" << endl;
        cout << "\t 5. charger les taches" << endl;
        cout << "\t 6. finir une tache" << endl;
        
        cout << "\t 9. exit" << endl;

        TODO: "manque a finir la sauvegarder et a faire le chargement";

        getline(cin, strChoix);

        choix = strToInt(strChoix);
        //cin.ignore();

        switch (choix)
        {
        case 1:
        
            biblio1.addTache();
            break;
        case 2:
            cout << biblio1.getTache() << endl;
            break;
        case 3:
            delInCat(&biblio1);
            break;
        case 4:
            biblio1.save();
            break;
        case 5:
            biblio1.load();
            break;
        case 6:
            markDone(&biblio1);
            break;
        case 9:
            cont = false;
        default:
            break;
        }

    } while (cont);
}