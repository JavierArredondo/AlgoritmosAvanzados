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
route* backTracking(graph* myGraph, route* optRoute, route* auxRoute);

# endif