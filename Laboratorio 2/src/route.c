# include "../include/route.h"

route* initRoute()
{
	route* newRoute = (route*)malloc(sizeof(route));
	newRoute->size = 0;
	newRoute->cost = 0;
	newRoute->sequence = NULL;
	return	newRoute;
}

void add(int node, int w, route* myRoute)
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
		myRoute->cost = myRoute->cost + w;
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
	printf("Costo: %i\n", myRoute->cost);
	if(myRoute->size != 0)
	{
		for (int i = 0; i < myRoute->size; i++)
			printf("%i->", myRoute->sequence[i]);
	}
	printf("\n");
}

int inRoute(int n, route* myRoute)
{
	printf("\n%i\n", myRoute->size);
	if(myRoute->size == 0)
		return 0;
	for (int i = 0; i < myRoute->size; i++)
		if(n == myRoute->sequence[i])
			return 1;
	return 0;
}

int getCurrent(route* myRoute)
{
	if(myRoute->size == 0)
		return -1;
	return myRoute->sequence[myRoute->size - 1];
}

int getSize(route* myRoute)
{
	return myRoute->size;
}

route* makeCopy(route* myRoute)
{
	route* r = initRoute();
	for (int i = 0; i < myRoute->size; i++)
		add(myRoute->sequence[i], 0, r);
	r->cost = myRoute->cost;
	return r;
}