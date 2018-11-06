# include "../include/knapsack.h"
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
	printf("Capital: %i\n", _knapsack->capital);
	printf("Capacity: %i\n", _knapsack->capacity);
	printf("Benefits: %i\n", _knapsack->benefits);
	if(_knapsack->boxes)
	{
		int i;
		printf("Content:\n");
		for (i = 0; i < _knapsack->size; ++i)
		{
			printf("Elemento %i | Inversion: %i | Beneficio: %i\n", i+1, _knapsack->boxes[i].inversion, _knapsack->boxes[i].benefit);
		}
	}
	else
		printf("Knapsack empty!\n");
	if(_knapsack->capacity >= 0 && _knapsack->capital >= 0)
		printf("Success!\n");
	else
		printf("Failed, this combination doesn't satisfy the conditions\n");
}
