# include <string.h>
# include <stdio.h>
# include "list.h"
# include "knapsack.h"
# ifndef HANDLER_H
# define HANDLER_H

FILE* inDirectory(char* name);
knapsack* getKnapsack(FILE* _file);
list* getInversions(FILE* _file);
void writeOutput();
void bruteForce(knapsack* _knapsack, list* _list);

# endif
