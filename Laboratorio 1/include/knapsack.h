# include <stdlib.h>
# include <stdio.h>
# include "box.h"
# ifndef KNAPSACK_H
# define KNAPSACK_H
typedef struct knapsack /* Structure used to store inversions.*/
{
	int capital;
	int capacity;
	int size;
	box* boxes; 
} knapsack;

knapsack* initMyKnapsack(int _capital, int _capacity);
void add(knapsack* _knapsack, box _box);
void showKnapsack(knapsack* _knapsack);

# endif