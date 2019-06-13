#include <iostream>
#include <fstream>
#include <string>
#include "Tache.hpp"
#include "Category.hpp"
#include "actionCat.hpp"
#include "cli.hpp"
#include <map>

using namespace std;



Category::Category(/* args */)
{
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

void Category::addTache(int id, string name, string content, string date)
{
    id = getNextId();
    m_listTache[id] = new Tache(id, name, content, date);
    m_nbTache ++;
}

void Category::addTache(string name, string content, string date)
{
    
    m_listTache[getNextId()] = new Tache( name, content, date);
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

    string date(askTime());
    if (date != "nope")
    {
        m_listTache[getNextId()] = new Tache(name, content, date);
    }
    else{
        m_listTache[getNextId()] = new Tache(name, content);
    }
     m_nbTache ++;

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
        str += "\n";
    }
    
    return str;
}

void Category::delTask(int id)
{
    if (id > m_nbTache){
        cout << "the asked task does't already exist" << endl;
        TODO: "faire en sorte que l'on puisse ajouter une tache a partire d'ici pk pas";
        return;
    }else if(id == -3){
        delAll();
    }else{
        m_listTache[id] = NULL;
        for (int i = id; i < m_nbTache; i++)
        {
            m_listTache[i] = m_listTache[i + 1];
        }
        m_listTache[m_nbTache] = NULL;
        m_nbTache --;
        m_nextId --;       
    }
}

int Category::save()
{
    ofstream fichier("./task");
    if(fichier){
        fichier.clear();
        fichier << getTache();
        fichier << "\n";
        return 1;
    }else{
        cout << "sauvegarde impossible" << endl;
        return -1;
    }
    
}

void Category::load()
{
    ifstream fichier("task");
    string line;
    string temp;
    int debut, fin;

    getline(fichier, line);

    bool nope(false);

    while(line != ""){
    
        
        // cout << line << endl;
        debut = line.find("\"", 2);
        fin = line.find("\"", debut+1);    

        int id = line[debut + 3] - 48;
        TODO: "if faut que l'id puisse etre un nombre a deux chiffre";

        debut = fin;
        debut = line.find(":", debut);
        fin = line.find("\"", debut+1);
        string name;
        for(int i = debut + 2; i <= fin - 2; i++)
        {
            name += line[i];
        }
        
        for (int i = 1; i <= m_nbTache; i++)
        {
            temp = m_listTache[i]->tacheToString(i);            
            if(name == getName(temp))
                nope = true;    
        }
        
        if (nope){
            getline(fichier, line);
            nope = false;
            continue;
        }
        
        debut = fin;
        debut = line.find(":", debut);
        fin = line.find("\"", debut+1);
        string content;
        for(int i = debut + 2; i <= fin - 2; i++)
        {
            content += line[i];
        }

        debut = fin;
        debut = line.find(":", debut);
        fin = line.find("\"", debut+1);
        string date;
        for(int i = debut + 2; i <= fin - 1; i++)
        {
            date += line[i];
        }
        addTache(id, name, content, date);
        getline(fichier, line);
    }  

    
}

void Category::delAll()
{
    int nbTask = m_nbTache;
    for(int i = 0; i < nbTask; i++)
    {
        delTask(1);
    }
}

void Category::done(int id)
{
    m_listTache[id]->isDone();
}