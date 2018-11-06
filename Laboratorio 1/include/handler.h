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
int allInKnapsack(knapsack* ks, list* elements);
void bruteForce(int _capital, int _capacity, list* _list);
int myPow(int base, int exp);
int** makeCombinatory(int n);

# endif
