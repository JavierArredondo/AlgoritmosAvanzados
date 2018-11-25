# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "graph.h"
# include "route.h"
# ifndef HANDLER_H
# define HANDLER_H

/* 
For verify if the file exists.
@params name: name of the file
@return: Pointer to file
 */
FILE* inDirectory(char* filename);
/**/
int isSolution(route* myRoute, graph* myGraph);
/**/
int isPosible(route* myRoute, graph* myGraph, int o, int d);
/**/
route backTracking(graph* myGraph, route* myRoute, route* opt);

# endif