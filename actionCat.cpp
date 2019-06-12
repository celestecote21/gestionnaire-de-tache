
#include "actionCat.hpp"

using namespace std;

void delInCat(Category *ptCat)
{
    string str;
    int id;
    cout << ptCat->getTache() << endl;
    cout << "please enter the task's id you want to delete" << endl;
    getline(cin, str);
    //cin.ignore();
    id = strToInt(str);
    switch (id)
    {
    case -3:
        cout << "all the task will be delete" << endl;
        ptCat->delTask(id);
        break;
    case -2:
        cout << "please enter a number" << endl;
        break;
    case -1:
        cout << "there is an errors please enter a good number" << endl;
        break;
    default:
        cout << "the task with " << id << " id will be delete" << endl;
        ptCat->delTask(id);
        break;
    }
    
}

string getName(string strTache)
{
    string name;
    int debut, fin;

    debut = 8;
    debut = strTache.find(":", debut);
    fin = strTache.find("\"", debut+1);
    for(int i = debut + 2; i <= fin - 2; i++)
    {
        name += strTache[i];
    }
    return name;
}

Date toDate(string strDate)
{
    Date date;
    Statue statut = DAY; 
    int i(0), untite, dizaine, nbr;

    while (i <= strDate.length())
    {
        dizaine = int(strDate[i]) - 48;
        i ++;
        untite = int(strDate[i]) - 48;
        nbr = toNbr(dizaine, untite);
        i += 2;

        switch (statut)
        {
            case DAY:
                date.day = nbr;
                statut = MONTH;
                break;
            case MONTH:
                date.month = nbr;
                statut = HOUR;
                break;
            case HOUR:
                date.hours = nbr;
                statut = MINUTE;
                break;
            case MINUTE:
                date.minutes = nbr;
                statut = END;
                break;
            
            default:
                break;
        }
    }   
    //cout << date.day << " " << date.month << endl;
    return date;
}

int toNbr(int dizaine, int unite)
 {
    int nbr;
    nbr = dizaine * 10;
    nbr += unite;
    return nbr;
 }


int strToInt(string str)
{
    int id;
    int dizaine;
    int uniter;

    if (int(str[0]) >= 48 && int(str[0]) <= 57)
    {
        if( str.length() > 2){
            return -1;
        }else if (str.length() == 2){
            dizaine = int(str[0]) - 48;
            uniter = int(str[1]) - 48;
            id = toNbr(dizaine, uniter);
        }else if (str.length() == 1){
            id = int(str[0]) - 48;
        }
        return id;
    }else if(str == "all"){
        return -3;
    }else{
        return -2;
    }
    
    
}


bool checkTime(string strDate)
{
    Date date(toDate(strDate));
    if (date.day >= 1 && date.day <= 31){
        if (date.month >= 1 && date.month <= 12){
            if (date.hours >= 0 && date.hours <= 24){
                if (date.minutes >= 0 && date.minutes <= 60){
                    return true;
                }
            }
        }
    }
    return false;
}
