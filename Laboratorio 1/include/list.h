# include <stdlib.h>
# include <stdio.h>
# include "box.h"
# ifndef LIST_H
# define LIST_H

typedef struct list /* Structure used to store inversions.*/
{
	int size; /* Current size of list.*/
	box* content; /* Current content of the list. */
} list;

list* initList(); /* Function to create the list.*/
void append(list* _list, box element); /* Procedure to add a element at list.*/
box pop(list* _list); /* Function to get the last element and delete this from de list.*/
void showList(list* _list);

# endif
