# include <string.h>
# include <stdio.h>
# include "list.h"
# include "knapsack.h"
# ifndef HANDLER_H
# define HANDLER_H

/* 
For verify if the file exists.
@params name: name of the file
@return: Pointer to file
 */
FILE* inDirectory(char* name);

/*
For get the params of the knapsack, this params are got from the file.
@params _file: pointer to file
@return params of the knapsack.
*/
knapsack* getKnapsack(FILE* _file);

/*
For get the inversions from the file.
@params _file: pointer to file.
@return list of inversions to do.
*/
list* getInversions(FILE* _file);

/*
Verify if all items, can be puts on the knapsack.
@params _knapsack: params of the knapsack
@params _elements: list of items.
@return 0 or 1 (false or true)
*/
int allInKnapsack(knapsack* _knapsack, list* _elements);

/*
Function math.
@params base: base of function
@params exp: esponent
@return pow of the base
*/
int myPow(int base, int exp);

/*
Convert a number into bin
@params number: number to bin
@params longi: max longitude of the number.
@return pointer to int, that represent bin number.
*/
int* toBin(int number, int longi);

/*
Combinatory of all the posibilities to do.
@params posibilities: number of combinatory to do.
@return matrix of int, that represent all the combinations
*/
int** makeCombinatory(int posibilities);

void printCurrent(knapsack* ks, int i);
/*
Brute force for knapsack's algorithm.
@params _capital: init capital.
@params _capacity: capacity of the knapsack.
@params _list: list of elements to put into knapsack.
@return the optimum knapsack.
*/
knapsack* bruteForce(int _capital, int _capacity, list* _list);

void writeOutput();
# endif
