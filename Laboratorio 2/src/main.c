# include "handler.h"
route* optRoute;


int main(int argc, char const *argv[])
{
	FILE* file = inDirectory("entrada.in");
	graph* myGraph = readGraph(file);
	showGraph(myGraph);
	route* r = initRoute();
	optRoute = initRoute();
	add(0, 0, r);
	printf("\nNodes: %i\n\n", myGraph->qty);
	backTracking(myGraph, r);

	showRoute(optRoute);
	return 0;
}