#ifndef TACHE_HEADER
#define TACHE_HEADER
#include <iostream>
#include <string>
#include <sstream>
#include "define.hpp"

struct Date
{
    int hours;
    int minutes;
    int day;
    int month;
};

class Tache
{
    private:
        std::string m_name;
        std::string m_content;
        std::string m_date;
        Date m_date_t;
        bool m_ifDate;
        bool m_done;
        int m_id;
        //int time;
    public:
        Tache(std::string name, std::string content);
        Tache(std::string name, std::string content, std::string date);
        Tache(int id, std::string name, std::string content, std::string date, bool okai);
        ~Tache();
        int execTask();
        std::string tacheToString(int id);
        void isDone();
        
};

#endif