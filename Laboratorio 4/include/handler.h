# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "word.h"
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
void dinamica(FILE* input, FILE* output);

/*
*/
void writeOutput(word solution, FILE* output);

/* Function to debug*/
void printCurrent();

# endif