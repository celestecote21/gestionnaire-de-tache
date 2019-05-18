#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include "Tache.hpp"
#include <map>
#include "Category.hpp"
#include "actionCat.hpp"

using namespace std;

void delInCat(Category *ptCat)
{
    int id;
    cout << ptCat->getTache() << endl;
    cout << "please enter the task's id you want to delete" << endl;
    cin >> id;
    cin.ignore();
    cout << "the task with " << id << " id will be delete" << endl;
    ptCat->delTask(id);
}

string getName(string strTache)
{
    string name;
    int debut, fin;

    debut = strTache.find("\"", 2);
    fin = strTache.find("\"", debut+1);    

    int id = strTache[debut + 3] - 48;


    debut = fin;
    debut = strTache.find(":", debut);
    fin = strTache.find("\"", debut+1);
    for(int i = debut + 2; i <= fin - 2; i++)
        {
            name += strTache[i];
        }
    cout << name << endl;
    return name;
}


