#ifndef CLI_HEADER
#define CLI_HEADER
#include <iostream>
#include <string>
#include "Tache.hpp"

#include "Category.hpp"
void readArg(int argCount, char** argText, Category* ptCat);
void addTaskByArg(int argCount, char** argText, Category* ptCat);
#endif