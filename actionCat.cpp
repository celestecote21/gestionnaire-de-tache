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


void strToCat()
{
    ifstream fichier("task");
    string temp;
    istream_iterator<char> itFichier(fichier);
    
    char ch;

    while (ch != '\"'){
        ch = *itFichier;
        temp += ch;
        ++ itFichier;
    }
    /// id //
    int id;
    for (int i = 0; i < 4; i++)
    {
        ++ itFichier;
    }
    int i  = *itFichier - 48;
    ++ itFichier;
    int a = *itFichier - 48;
    if(a >= 0 && a <= 9)
    {
        id = i * 10 + a;
    }
    else
    {
        id = i;
    }
    /// go to the name
    
     while (ch != ':'){
        ch = *itFichier;
        temp += ch;
        ++ itFichier;
    }
    string name("");
    while (*itFichier != '\"')
    {
        name += *itFichier;
        ++ itFichier;
    }

    // collect the contente:

    while (*itFichier != ':'){
        ++ itFichier;
    }
    ++ itFichier;
    cout << *itFichier;

    string content;
    while (*itFichier != '\"')
    {
        content += *itFichier;
        ++ itFichier;
    }
    cout << id << " " << name << " " << content << endl;
    
}