# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef GRAPH_H
# define GRAPH_H

typedef struct graph
{
	int** ady; // Matrix of ady
	int qty;   // Total nodes
} graph;

graph* initGraph(int q);

graph* readGraph(FILE* file);

void showGraph(graph* g);

int getWeight(int x, int y, graph* g);

# endif