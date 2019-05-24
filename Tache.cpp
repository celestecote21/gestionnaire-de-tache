
#include "Tache.hpp"
#include "actionCat.hpp"

using namespace std;


Tache::Tache(string name, string content)
{
    m_name = name;
    m_content = content;
    cout << "tache cree " << m_name << " " << m_content << endl;
}

Tache::Tache(string name, string content, string date)
{
    m_name = name;
    m_content = content;
    m_date = date;
    m_date_t = toDate(m_date);
    cout << "tache cree " << m_name << " " << m_content << endl;
}

Tache::Tache(int id, string name, string content, string date)
{
    m_id = id;
    m_name = name;
    m_content = content;
    m_date = date;
    m_date_t = toDate(m_date);
    
}

Tache::~Tache()
{
}

string Tache::tacheToString(int id)
{
    string str = "";
    ostringstream ost;
    
    ost << "\"id\": " <<  char(id + 48);    
    ost << " \"name\": " << m_name;
    ost << " \"content\": " << m_content;
    if (m_date != "")
        ost << " \"date\": " << m_date << "\"";
     
    return ost.str();
}
