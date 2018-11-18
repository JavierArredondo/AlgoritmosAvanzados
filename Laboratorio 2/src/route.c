# include "../include/route.h"

route* initRoute()
{
	route* newRoute = (route*)malloc(sizeof(route));
	newRoute->size = 0;
	newRoute->sequence = NULL;
	return	newRoute;
}

void add(int node, route* myRoute)
{
	if(myRoute->size == 0)
	{
		myRoute->sequence = (int*)malloc(sizeof(int));
		myRoute->sequence[0] = node;
	}
	else
	{
		myRoute->sequence = (int*)realloc(myRoute->sequence, (myRoute->size + 1) * sizeof(int));
		myRoute->sequence[myRoute->size] = node;
	}
	myRoute->size++;
}

int pop(route* myRoute)
{
	int max = myRoute->size - 1;
	if(max < 0)
	{
		perror("Element can't be extracted: Negative size.");
		return -1;
	}
	int aux = myRoute->sequence[max];
	myRoute->sequence = (int*)realloc(myRoute->sequence, (max - 1) * sizeof(int));
	myRoute->size = max;
	return aux;
}
void showRoute(route* myRoute)
{
	if(myRoute->size != 0)
	{
		for (int i = 0; i < myRoute->size; i++)
			printf("%i ", myRoute->sequence[i]);
	}
}