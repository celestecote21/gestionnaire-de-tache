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

void Category::addTache()
{
    string name;
    string content;
    cout << "please type the name of this task" << endl;
    getline(cin, name);
    cout << "okai so waht's the content of the " << name << " task" << endl;
    getline(cin, content);
    cout << "do you what add a time? (y/n)" << endl;
    string answer;
    
    bool okai(false);
    do
    {
        getline(cin, answer);
        okai = false;
        if (answer == "y" || answer == "Y")  
        {
            cout << "please enter the date in this format \"dd/mm hh/min\"" << endl; 
            string date;
            getline(cin, date);
            m_listTache[getNextId()] = new Tache(name, content, date);
            m_nbTache ++;
            
        }else if (answer == "n" || answer == "N")
        {
            m_listTache[getNextId()] = new Tache(name, content);
            m_nbTache ++;
        }else{
            cout << "please type y or n" << endl;
            okai = true;
        }     
    } while (okai);
    


    

}

int Category::getNextId()
{
    m_nextId ++;
    return m_nextId;
}

string Category::getTache()
{
    
    string str = "";

    for (int i = 1; i <= m_nbTache; i++)
    {
        str += m_listTache[i]->tacheToString(i);
        str += "\n"
    }
    
    return str;
}
