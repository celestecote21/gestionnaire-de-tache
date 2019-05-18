
class Tache
{
private:
    std::string m_name;
    std::string m_content;
    std::string m_date;
    int m_id;
    int time;
public:
    Tache(std::string name, std::string content);
    Tache(std::string name, std::string content, std::string date);
    Tache(int id, std::string name, std::string content, std::string date);
    ~Tache();
    std::string tacheToString(int id);
};
