#include "cli.hpp"

using namespace std;

void readArg(int argCount, char** argText, Category* ptCat)
{
    if (argCount == 0){
        return;
    }
    char option;
   if (argText[1][0] == '-')
   {
       option = argText[1][1];
   }
   cout << argCount;

   switch (option)
   {
   case 'a':
       addTaskByArg(argCount, argText, ptCat);
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
        /* demander la date */
    }else{
        title = argText[2];
        content = argText[3];
        date = argText[4];
    }

    ptCat->addTache(title, content, date);
    
    
}