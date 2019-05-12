#include <iostream>
#include <string>
#include "Tache.hpp"
#include "Category.hpp"
#include <map>

using namespace std;



Category::Category(/* args */)
{
    TODO: "faire en sorte que ca genere la categorie a partire d'un fichier";
   
}

Category::~Category()
{
}

void Category::addTache(string name, string content)
{
    m_listTache[getNextId()] = new Tache(name, content);

}

int Category::getNextId()
{
    m_nextId ++;
    return m_nextId;
}
