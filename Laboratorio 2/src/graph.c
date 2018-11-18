# include "../include/graph.h"

graph* initGraph(int q)
{
	graph* myGraph = (graph*)malloc(sizeof(graph));
	myGraph->qty = q;
	q++;
	myGraph->ady = (int**)malloc(sizeof(int*) * q);
	for (int i = 0; i < q; i++)
		myGraph->ady[i] = (int*)calloc(q, sizeof(int));
	return myGraph;
}


void putNode(graph* myGraph, int origin, int destinity, int weight)
{
	myGraph->ady[origin][destinity] = weight;
	myGraph->ady[destinity][origin] = weight;
}


graph* readGraph(FILE* file)
{
	int aux;
	fscanf(file, "%i", &aux);
	graph* myGraph = initGraph(aux);
	int o, d, p;
	while(!feof(file))
	{
		fscanf(file, "%i %i %i", &o, &d, &p);
		putNode(myGraph, o, d, p);
	}
	return myGraph;
}