# include "../include/handler.h"
# define DEBUG
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

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

route* backTracking(graph* myGraph, route* myRoute, int show)
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
			/*if(!isPosible(myRoute, myGraph, origin, destiny) && show)
			{
				printCurrent(myRoute, origin, destiny, weight, 0);
			}*/
			if(isPosible(myRoute, myGraph, origin, destiny))
			{
				add(destiny, weight, myRoute);
				if(show)
					printCurrent(myRoute, origin, destiny, weight, 1);
				backTracking(myGraph, myRoute, show);
			}
			else if(show)
				printCurrent(myRoute, origin, destiny, weight, 0);
		}
	}
	pop(myRoute);
	return myRoute;
}

void writeOutput(route* myRoute, char* filename)
{
    char* route = (char*)calloc(70, sizeof(char));
    strcat(route, "./output/");
    strcat(route, filename);
    strcat(route, ".out");
    FILE* myFile = NULL;
    myFile = fopen(route, "w");
    fprintf(myFile, "%i\n", myRoute->cost);
    for (int i = 0; i < myRoute->size; i++)
    {
    	fprintf(myFile, "%i", myRoute->sequence[i]);
    	if(i != myRoute->size - 1)
    		fprintf(myFile, " %s ", "-");
    }
    fclose(myFile);
    printf(" > Archivo guardado con exito en la carpeta output.\n");
}

void printCurrent(route* myRoute, int o, int d, int w, int p)
{
	#ifdef DEBUG
    printf("\n\n\nEnter para continuar...\n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    int n = getCurrent(myRoute);
    printf("╔═══════════════════════════════════════════════════════════════════╗\n");
    printf("║ Nodo actual: %2i        Nodo destino: %2i          Costo: %2i        ║\n", o, d, w);
    if(p)
    printf(ANSI_COLOR_GREEN"║ Es posible el viaje a este destino!                               ║\n"ANSI_COLOR_RESET);
    else
    	printf(ANSI_COLOR_RED"║ Es imposible el viaje a este destino!                             ║\n"ANSI_COLOR_RESET);
    printf("╚═══════════════════════════════════════════════════════════════════╝\n");
    printf("┏━━ Recorriendo: \n");
    showRoute(myRoute);
    printf("┗━━\n");
    printf("┏━━ Óptimo parcial: \n");
    showRoute(optRoute);
    printf("┗━━\n");
    #endif  
}