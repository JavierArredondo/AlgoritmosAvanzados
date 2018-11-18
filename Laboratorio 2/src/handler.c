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
	if(myRoute->size == myGraph->qty + 1 && myRoute->sequence[0] == 0 && myRoute->sequence[myRoute->size] == 0)
		return 1;
	return 0;
}

int isPosible(route* myRoute, graph* myGraph, int o, int d)
{
	if(myRoute->size == 0)
		add(myRoute, o)
	else if(inRoute(o, myRoute) && !inRoute(d, myRoute))
	{
		add(myRoute, d);
		return 1;
	}
	return 0;
}


route* backTracking(graph* myGraph, route* optRoute, route* auxRoute)
{
	if(isSolution(auxRoute, myGraph))
		return auxRoute;
	for (int origin = 0; origin < myGraph->qty; origin++)
	{
		for (int destiny = 0; destiny < myGraph->qty; destiny++)
		{
			if(isPosible(auxRoute, myGraph, origin, destiny))
			{
				auxRoute = backTracking()
			}
		}
	}
	return NULL;
}



