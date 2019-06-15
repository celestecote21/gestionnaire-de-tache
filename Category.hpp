#ifndef CATEGORY_HEADER
#define CATEGORY_HEADER
#include <map>

class Category
{
private:
    std::map<int, Tache*> m_listTache ; // c'est de pointeur vers des taches
    int m_nbTache;
    int m_nextId;
    
public:
    Category(/* args */);
    ~Category();
    void addTache(std::string name, std::string content);
    void addTache(int id, std::string name, std::string content, std::string date);
    void addTache(int id, std::string name, std::string content, std::string date, bool isDone);
    void addTache(std::string name, std::string content, std::string date);
    void addTache();
    void delTask(int id);
    void delAll();
    int getNextId();
    int save();
    std::string getTache();
    void load();
    void done(int id);

    //TODO: "fonction == pour tester si on peut charcher pour ne pas avoir la meme";


};

#endif