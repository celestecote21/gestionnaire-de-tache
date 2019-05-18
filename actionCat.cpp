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
    string line;
    int debut, fin;
    istream_iterator<char> itFichier(fichier);
    getline(fichier, line);
    while(line != ""){
    
    cout << line << endl;
    debut = line.find("\"", 2);
    fin = line.find("\"", debut+1);    

    int id = line[debut + 3] - 48;
    cout << id <<endl;

    debut = fin;
    debut = line.find(":", debut);
    fin = line.find("\"", debut+1);
    string name;
    for(int i = debut + 2; i <= fin - 1; i++)
    {
        name += line[i];
    }
    cout << name << endl;

    debut = fin;
    debut = line.find(":", debut);
    fin = line.find("\"", debut+1);
    string content;
    for(int i = debut + 2; i <= fin - 1; i++)
    {
        content += line[i];
    }
    cout << content << endl;
    debut = fin;
    debut = line.find(":", debut);
    fin = line.find("\"", debut+1);
    string date;
    for(int i = debut + 2; i <= fin - 1; i++)
    {
        date += line[i];
    }
    cout << date << endl;
    cout << endl;
    getline(fichier, line);
    }  
    
}