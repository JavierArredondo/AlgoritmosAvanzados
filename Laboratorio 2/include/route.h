# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef ROUTE_H
# define ROUTE_H

typedef struct route
{
	int size;
	int cost;
	int* sequence;
} route;

route* initRoute();

void add(int node, int w, route* myRoute);

int pop(route* myRoute);

void showRoute(route* myRoute);

int inRoute(int n, route* myRoute);

int getCurrent(route* myRoute);

int getSize(route* myRoute);

route* makeCopy(route* myRoute);
# endif