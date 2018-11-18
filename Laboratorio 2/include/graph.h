# include <string.h>
# include <stdio.h>
# ifndef GRAPH_H
# define GRAPH_H

typedef struct graph
{
	int** ady; 
	int* nodes;
	int qty;
} graph;

graph* initGraph(int q);

graph* readGraph(FILE* file);

void showGraph(graph* g);

# endif