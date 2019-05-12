#include <iostream>
#include <string>
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
