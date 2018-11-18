# include "../include/graph.h"

graph* initGraph(int q)
{
	graph* myGraph = (graph*)malloc(sizeof(graph));
	myGraph->qty = q;
	myGraph->ady = (int**)malloc(sizeof(int*) * q);
	for (int i = 0; i < q; i++)
		myGraph->ady[i] = (int*)calloc(q, sizeof(int));
	return myGraph;
}


void putNode(graph* myGraph, int origin, int destinity, int weight)
{
	myGraph->ady[origin][destinity] = weight;
	myGraph->ady[destinity][origin] = weight;
	myGraph->ady[origin][0] = 1;
	myGraph->ady[0][origin] = 1;
	myGraph->ady[0][destinity] = 1;
	myGraph->ady[destinity][0] = 1;
}


graph* readGraph(FILE* file)
{
	int aux;
	fscanf(file, "%i", &aux);
	graph* myGraph = initGraph(aux+1);
	int o, d, p;
	while(!feof(file))
	{
		fscanf(file, "%i %i %i", &o, &d, &p);
		putNode(myGraph, o, d, p);
	}
	fclose(file);
	return myGraph;
}

void showGraph(graph* myGraph)
{
	printf("          ");
	for (int i = 0; i < myGraph->qty; i++)
		printf("%3i ", i);
	printf("\n");
	printf("          ");
	for (int i = 0; i < myGraph->qty; i++)
		printf("%3s ", "|");
	printf("\n");
	for (int i = 0; i < myGraph->qty; i++)
	{
		printf("Nodo %3i: ", i);
		for (int j = 0; j < myGraph->qty; j++)
		{
			printf("%3i ", myGraph->ady[i][j]);
		}
		printf("\n");
	}
}