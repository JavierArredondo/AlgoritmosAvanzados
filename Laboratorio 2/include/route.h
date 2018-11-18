# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef ROUTE_H
# define ROUTE_H

typedef struct route
{
	int size;
	int* sequence;
} route;

route* initRoute();

void add(int node, route* myRoute);

int pop(route* myRoute);

void showRoute(route* myRoute);

# endif