# include "../include/knapsack.h"
knapsack* initMyKnapsack(int _capital, int _capacity)
{
	knapsack* ks = (knapsack*)malloc(sizeof(knapsack));
	ks->capital = _capital;
	ks->capacity = _capacity;
	ks->size = 0;
	ks->boxes = NULL;
	return ks;
}

void add(knapsack* _ks, box element)
{
	if(_ks->capacity == 0)
	{
		_ks->boxes = (box*)malloc(sizeof(box));
		_ks->boxes[0] = element;
	}
	else
	{
		_ks->boxes = (box*)realloc(_ks->boxes, (_ks->capacity + 1) * sizeof(box));
		_ks->boxes[_ks->capacity] = element;
	}
	_ks->capacity++;
}

void showKnapsack(knapsack* _knapsack)
{
	printf("Capital: %i\n", _knapsack->capital);
	printf("Capacity: %i\n", _knapsack->capacity);
	if(_knapsack->boxes)
	{
		int i;
		printf("Content:\n");
		for (i = 0; i < _knapsack->size; ++i)
		{
			printf("Elemento %i | Inversion: %i | Beneficio: %i\n", i+1, _knapsack->boxes[i].size, _knapsack->boxes[i].value);
		}
	}
}
