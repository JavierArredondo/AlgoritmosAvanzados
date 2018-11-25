# include "handler.h"

int main(int argc, char const *argv[])
{
	FILE* file = inDirectory("entrada.in");
	graph* myGraph = readGraph(file);
	showGraph(myGraph);
	route* opt = initRoute();
	route* actual = initRoute();
	add(0, 0, opt);
	printf("\nNodes: %i\n\n", myGraph->qty);
	backTracking(myGraph, opt, actual);
	return 0;
}