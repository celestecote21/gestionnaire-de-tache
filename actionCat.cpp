
#include "actionCat.hpp"

using namespace std;

void delInCat(Category *ptCat)
{
    int id;
    cout << ptCat->getTache() << endl;
    cout << "please enter the task's id you want to delete" << endl;
    cin >> id;
    cin.ignore();
    cout << "the task with " << id << " id will be delete" << endl;
    ptCat->delTask(id);
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


