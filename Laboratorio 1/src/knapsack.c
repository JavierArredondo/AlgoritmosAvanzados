# include "../include/knapsack.h"

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

knapsack* initMyKnapsack(int _capital, int _capacity)
{
	knapsack* ks = (knapsack*)malloc(sizeof(knapsack));
	ks->capital = _capital;
	ks->capacity = _capacity;
	ks->size = 0;
	ks->benefits = 0;
	ks->boxes = NULL;
	return ks;
}

knapsack** initVeryKnapsack(int _capital, int _capacity, int size)
{
	knapsack** ks = (knapsack**)malloc(sizeof(knapsack*) * size);
	for (int i = 0; i < size; i++)
		ks[i] = initMyKnapsack(_capital, _capacity);
	return ks;
}

void add(knapsack* _ks, box element)
{
	if(_ks->size == 0)
	{
		_ks->boxes = (box*)malloc(sizeof(box));
		_ks->boxes[0] = element;
	}
	else
	{
		_ks->boxes = (box*)realloc(_ks->boxes, (_ks->size + 1) * sizeof(box));
		_ks->boxes[_ks->size] = element;
	}
	_ks->benefits = _ks->benefits + element.benefit;
	_ks->capital = _ks->capital - element.inversion;
	_ks->capacity--;
	_ks->size++;
}

void showKnapsack(knapsack* _knapsack)
{
	printf("|――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――|\n");
	printf("| > Capital:            %10i                               |\n", _knapsack->capital);
	printf("| > Capacidad restante: %10i                               |\n", _knapsack->capacity);
	printf("| > Beneficio total:    %10i                               |\n", _knapsack->benefits);
	if(_knapsack->boxes)
	{
		int i;
		printf("|―contenido――――――――――――――――――――――――――――――――――――――――――――――――――――――|\n");
		for (i = 0; i < _knapsack->size; ++i)
		{
			printf("|%12s: %3i |", "Elemento n°", i+1);
			printf("%12s: %7i |", "Inversion" , _knapsack->boxes[i].inversion);
			printf("%12s: %7i  |\n", "Beneficio", _knapsack->boxes[i].benefit);
			//printf("Elemento %i | Inversion: %i | Beneficio: %i\n", i+1, _knapsack->boxes[i].inversion, _knapsack->boxes[i].benefit);
		}
	}
	else
		printf("| > Conjunto vacio                                               |\n");
	if(_knapsack->capacity >= 0 && _knapsack->capital >= 0)
		printf(ANSI_COLOR_GREEN"| > Cumple con los requisitos basicos!                           |\n"ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED"| > Fallo, no cumple con los requisitos                          |\n"ANSI_COLOR_RESET);
	printf(" ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― \n");
}