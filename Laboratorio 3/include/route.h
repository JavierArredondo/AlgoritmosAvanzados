# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef ROUTE_H
# define ROUTE_H

typedef struct route
{
	int size;       // Size of the route
	int cost;       // Total cost of the route
	int* sequence;  // Secquence of step to optimus route
	int* weights;   // Cost of each step
} route;

/*Funtion that create a new route*/
route* initRoute();

/* Procedure that add a node to route
@params node: element to add
        w: weight of the step
        myRoute: route
@return
*/
void add(int node, int w, route* myRoute);

/* Procedure that withdraw the last element
@params myRoute: route
@return the last element*/
int pop(route* myRoute);

/* For print the route*/
void showRoute(route* myRoute);

/* For verify if a element in route*/
int inRoute(int n, route* myRoute);

/* For get the current node to analize*/
int getCurrent(route* myRoute);

/* Get size of the route*/
int getSize(route* myRoute);

/* For make a copy from myRoute to the global variable optRoute*/
route* makeCopy(route* myRoute);
# endif