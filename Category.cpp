#include <iostream>
#include <fstream>
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

void Category::addTache(int id, string name, string content, string date)
{
    id = getNextId();
    m_listTache[id] = new Tache(id, name, content, date);
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
        TODO: "manque beacoup de truc il faut verifier que l'on sauvegarde pas deux fois ma meme chose et pas les meme id";


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
    
    for (int i = 1; i <= m_nbTache; i++)
    {
        temp = m_listTache[i]->tacheToString(i);
        if(temp.compare(1, 10,line,1,10) == 0){
            cout << "et ben non";
            nope = true;
        }
        
    }
    if (nope){
        getline(fichier, line);
        continue;
    }
        
        // cout << line << endl;
        debut = line.find("\"", 2);
        fin = line.find("\"", debut+1);    

        int id = line[debut + 3] - 48;


        debut = fin;
        debut = line.find(":", debut);
        fin = line.find("\"", debut+1);
        string name;
        for(int i = debut + 2; i <= fin - 1; i++)
        {
            name += line[i];
        }


        debut = fin;
        debut = line.find(":", debut);
        fin = line.find("\"", debut+1);
        string content;
        for(int i = debut + 2; i <= fin - 1; i++)
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

