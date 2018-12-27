# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef HANDLER_H
# define HANDLER_H


/* 
For verify if the file exists.
@params name: name of the file
@return: Pointer to file
 */
FILE* inDirectory(char* filename);

/*
Function that write the output file.
@params myRoute: route that will be write.
	    filename: name of the file
*/
void writeOutput();

/* Function to debug*/
void printCurrent();

# endif