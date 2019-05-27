
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
    m_ifDate = true;
    cout << "tache cree " << m_name << " " << m_content << endl;
}

Tache::Tache(int id, string name, string content, string date)
{
    m_id = id;
    m_name = name;
    m_content = content;
    m_date = date;
    m_date_t = toDate(m_date);
    m_ifDate = true;
    
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


 int Tache::execTask()
{
    /*
    if the task has a date create a file with the base. 
    write at the end of the file the instruction
    and finelly copie this to the pathe for at 

    do this here or on actionCat file? 
    */ 

   /*
   firtsly i gonna use system commande to do this
   but i thing there is better way to do this
   */
  string taskFile("test.task");

  string cpCommande("cp ");
  cpCommande += PATH_BASE;
  cpCommande += taskFile;  // here we must put an unique name at the task

  system(cpCommande.c_str());

  string echoCommande("echo ");

  echoCommande += "touch ~/yoloooo.txt";  // la c'est la grosse partie
  echoCommande += " >> ";
  echoCommande += taskFile;

  system(echoCommande.c_str());

  /* reste a savoir ou c'est pour mettre la date*/
    
}
