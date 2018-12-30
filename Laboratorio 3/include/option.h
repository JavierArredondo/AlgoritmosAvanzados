# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "list.h"
# ifndef CASE_H
# define CASE_H

typedef struct option
{
	int barrels; /* Qty of barrels.*/
	int consumption; /* Consumption of the plane.*/
	list* containers; /* List of containers. */
	int qty;
} option;

/*
*/
void showOptions(option* ops);

# endif