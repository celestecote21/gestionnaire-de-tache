#ifndef ACTION_HEADER
#define ACTION_HEADER
#include <iostream>
#include <string>
#include "Tache.hpp"
#include <map>
#include "Category.hpp"
void delInCat(Category *ptCat);
void strToCat();
std::string getName(std::string strTache);
Date toDate(std::string strDate);
enum Statue {DAY, MONTH, HOUR, MINUTE, END};
int toNbr(int dizaine, int unite);
int strToInt(std::string str);
#endif