# include "handler.h"

int main(int argc, char const *argv[])
{
	FILE* file = inDirectory("entrada.in");
	graph* myGraph = readGraph(file);
	showGraph(myGraph);
	return 0;
}