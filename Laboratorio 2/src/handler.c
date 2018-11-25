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
	if(myRoute->size == myGraph->qty)
	{
		printf("Solo falta volver:\n");
		return 1;
	}
	return 0;
}

int isPosible(route* myRoute, graph* myGraph, int o, int d)
{
	if(o != d && inRoute(o, myRoute) && !inRoute(d, myRoute))
	{
		int w = getWeight(o, d, myGraph);
		printf("Ruta con: %i -> %i con %i\n", o, d, w);
		add(d, w, myRoute);
		return 1;
	}
	else
		printf("Imposible %i -> %i\n", o, d);
	return 0;
}


route* backTracking(graph* myGraph, route* myRoute, route* opt)
{
	/*if(isSolution(auxRoute, myGraph))
		return auxRoute;
	int origin, destiny;
	for (origin = 0; origin < myGraph->qty; origin++)
	{
		for (destiny = 0; destiny < myGraph->qty; destiny++)
		{
			if(isPosible(auxRoute, myGraph, origin, destiny))
			{
				auxRoute = backTracking(myGraph, optRoute, auxRoute);
				if(auxRoute != NULL)
					return auxRoute;
			}
		}
	}*/
	if(isSolution(myRoute, myGraph) == 1)
	{
		opt = makeCopy(myRoute);
		return opt;
	}

	int origin, destiny;
	for (origin = getCurrent(myRoute); origin < myGraph->qty; origin++)
	{
		for (destiny = 0; destiny < myGraph->qty; destiny++)
		{
			printf("%i__________%i\n", origin, destiny);
			if(isPosible(myRoute, myGraph, origin, destiny))
			{
				showRoute(myRoute);
				myRoute = backTracking(myGraph, myRoute, opt);
				//if(myRoute != NULL)
				//	return myRoute;
			}
		}	
	}
	return NULL;
}



