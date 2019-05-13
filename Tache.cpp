#include <iostream>
#include <string>
#include <sstream>
#include "Tache.hpp"

using namespace std;


Tache::Tache(string name, string content)
{
    m_name = name;
    m_content = content;
    cout << "tache cree " << m_name << " " << m_content << endl;
}

Tache::~Tache()
{
}

string Tache::tacheToString(int id)
{
    string str = "";
    ostringstream ost;
    
    ost << "\"id\": " << id;    
    ost << "\"name\": " << m_name;
    ost << " \"content\": " << m_content;
    ost << ost.str();
    return str;
}
