# include "../include/handler.h"


FILE* inDirectory(char* name)
{
	char* route = (char*)calloc(60, sizeof(char));
	strcat(route, "./input/");
	strcat(route, name);
	FILE* myFile = NULL;
	myFile = fopen(route, "r");
	if(!myFile)
		return NULL;
	return myFile;
}

int isSolution(route* myRoute, graph* myGraph)
{
	if(!myRoute)
		return 0;
	if(myRoute->size == myGraph->qty+1)
		return 1;
	return 0;
}

int isPosible(route* myRoute, graph* myGraph, int o, int d)
{
	if(o != d && inRoute(o, myRoute) && !inRoute(d, myRoute))
		return 1;
	else if(myGraph->qty == myRoute->size && d == 0)
		return 1;
	return 0;
}

route* backTracking(graph* myGraph, route* myRoute)
{
	if(isSolution(myRoute, myGraph) == 1)
	{
		if(myRoute->cost < optRoute->cost || optRoute->cost == 0)
			optRoute = makeCopy(myRoute);

	}
	else if(optRoute->cost == 0 || myRoute->cost < optRoute->cost)
	{
		int origin = getCurrent(myRoute);
		int destiny;
		for (destiny = 0; destiny < myGraph->qty; destiny++)
		{
			int weight = getWeight(origin, destiny, myGraph);
			if(isPosible(myRoute, myGraph, origin, destiny))
			{
				add(destiny, weight, myRoute);
				backTracking(myGraph, myRoute);
			}
		}
	}
	pop(myRoute);
	return myRoute;
}



