# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "graph.h"
# include "route.h"
# ifndef HANDLER_H
# define HANDLER_H

/*
Es la variable global que contendrá la ruta óptima.
*/
extern route* optRoute;


/* 
For verify if the file exists.
@params name: name of the file
@return: Pointer to file
 */
FILE* inDirectory(char* filename);

/*
For verify if a route is solution.
@params: myRoute is the route to verify
		 myGraph is the graph where the route is verified.
@return: int that represent a boolean value
*/
int isSolution(route* myRoute, graph* myGraph);

/*
For verify if a "origin" to "destiny" is posible.
@params: myRoute is the route to verify
		 myGraph is the graph where the route is verified.
		 o is the origin
		 d is the destiny
@return: int that represent a boolean value
*/
int isPosible(route* myRoute, graph* myGraph, int o, int d);

/* 
Procedure that make backTracking in the graph
@params myGraph: Es el grafo en el que se encuentra el mapa de la ciudad.
		myRoute: Es la ruta auxiliar en la cual se trabajará la recursión.
*/
route* backTracking(graph* myGraph, route* myRoute);

/*
Function that write the output file.
@params myRoute: route that will be write.
	    filename: name of the file
*/
void writeOutput(route* myRoute, char* filename);

/* Function to debug*/
void printCurrent(route* myRoute, int o, int d, int w, int p);

# endif