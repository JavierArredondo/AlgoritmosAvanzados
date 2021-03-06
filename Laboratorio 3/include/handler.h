# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "option.h"
# include "list.h"
# ifndef HANDLER_H
# define HANDLER_H


/* 
For verify if the file exists.
@params name: name of the file
@return: Pointer to file
 */
FILE* inDirectory(char* filename);

/*
*/
FILE* openOutput(char* name);

/*
*/
option* readFile(FILE* file);

/*
*/
int* getOptimalLocal(list* _list, int goal);

/*
*/
void goloso(option* ops, FILE* output);

/*
Function that write the output file.
@params myRoute: route that will be write.
	    filename: name of the file
*/
void writeOutput(list* solution, FILE* output);

/* Function to debug*/
void printCurrent();

# endif