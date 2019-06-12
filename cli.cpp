#include "cli.hpp"

using namespace std;

void readArg(int argCount, char** argText, Category* ptCat)
{
    
    char option;
   if (argText[1][0] == '-')
   {
       option = argText[1][1];
   }
   //cout << argCount;

   switch (option)
   {
   case 'a':
       addTaskByArg(argCount, argText, ptCat);
       //ptCat->save();
       break;
    case 'l':
        cout << ptCat->getTache() << endl;
        break;
   
   default:
       break;
   }
    //for (int i = 0; argText[1][i] != "")
}

void addTaskByArg(int argCount, char** argText, Category* ptCat)
{
    string title;
    string content;
    string date;

    if (argCount < 4){
        return;
    }else if (argCount == 4)
    {
        date = askTime();
        title = argText[2];
        content = argText[3];
        if (date == "nope")
        {
            ptCat->addTache(title, content);
            return;
        }

    }else{
        title = argText[2];
        content = argText[3];
        date = argText[4];
        if (!checkTime(date))
        {
            cout << "the date is wrong" << endl;
            date = askTime();
            if (date == "nope"){
                ptCat->addTache(title, content);
                return;
            }
        }
        
    }

    ptCat->addTache(title, content, date);
    
    
}


string askTime()
{
    cout << "do you what add a time? (y/n)" << endl;
    string answer;
    string date;
    
    bool okai(false);
    do
    {
        getline(cin, answer);
        okai = false;
        if (answer == "y" || answer == "Y")  
        {
            bool good(true);
            while (good){
                cout << "please enter the date in this format \"dd/mm hh/min\"" << endl; 
                
                getline(cin, date);
                if (date == "quit")
                    return "nope"; // si jamais en fin de compte il ne veut pas mettre de date ca quitte
                if (!checkTime(date)) // to be sure the time is correct
                    date = "nope";
                else
                    good = false;
                
                 
            }
                
        }else if (answer == "n" || answer == "N")
        {
            date = "nope";
        }else{
            cout << "please type y or n" << endl;
            okai = true;
        }     
    } while (okai);
    return date;
    
}