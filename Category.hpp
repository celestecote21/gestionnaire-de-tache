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
    int getNextId();
    std::string getTache();

};