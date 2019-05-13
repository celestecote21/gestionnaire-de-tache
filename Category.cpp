#include <iostream>
#include <string>
#include "Tache.hpp"
#include "Category.hpp"
#include <map>

using namespace std;



Category::Category(/* args */)
{
    TODO: "faire en sorte que ca genere la categorie a partire d'un fichier";
    m_nextId = 0;
    m_nbTache = 0;
   
}

Category::~Category()
{
}

void Category::addTache(string name, string content)
{
    m_listTache[getNextId()] = new Tache(name, content);
    m_nbTache ++;

}

int Category::getNextId()
{
    m_nextId ++;
    return m_nextId;
}

string Category::getTache()
{
    TODO: "mettre une securiter pour pas que l'on essaye d'acceder a une tache pas inscrite";
    string str = "";

    for (int i = 1; i <= m_nbTache; i++)
    {
        str += m_listTache[i]->tacheToString(i);
    }
    
    return str;
}
