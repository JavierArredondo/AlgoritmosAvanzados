# include "../include/route.h"

route* initRoute()
{
	route* newRoute = (route*)malloc(sizeof(route));
	newRoute->size = 0;
	newRoute->cost = 0;
	newRoute->sequence = NULL;
	newRoute->weights = NULL;
	return	newRoute;
}

void add(int node, int w, route* myRoute)
{
	if(myRoute->size == 0)
	{
		myRoute->sequence = (int*)malloc(sizeof(int));
		myRoute->sequence[0] = node;
		myRoute->weights = (int*)malloc(sizeof(int));
	}
	else
	{
		myRoute->sequence = (int*)realloc(myRoute->sequence, (myRoute->size + 1) * sizeof(int));
		myRoute->sequence[myRoute->size] = node;
		myRoute->weights = (int*)realloc(myRoute->weights, myRoute->size * sizeof(int));
		myRoute->weights[myRoute->size-1] = w; 
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
	myRoute->cost = myRoute->cost - myRoute->weights[max - 1]; 
	myRoute->sequence = (int*)realloc(myRoute->sequence, (max) * sizeof(int));
	myRoute->size = max;
	return aux;
}
void showRoute(route* myRoute)
{
	if(myRoute == NULL)
	{
		printf("NULL\n");
	}
	printf("Costo: %i\n", myRoute->cost);
	if(myRoute->size != 0)
	{
		for (int i = 0; i < myRoute->size; i++)
			printf("%i->", myRoute->sequence[i]);
		printf("\n");
		for (int i = 0; i < myRoute->size - 1; i++)
			printf("  %i", myRoute->weights[i]);

	}
	printf("\n");
}

int inRoute(int n, route* myRoute)
{
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
	for (int i = 0; i < myRoute->size - 1; i++)
		r->weights[i] = myRoute->weights[i];

	r->cost = myRoute->cost;
	return r;
}
