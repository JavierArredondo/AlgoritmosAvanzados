# include "../include/list.h"

list* initList()
{
	list* myList = (list*)malloc(sizeof(list));
	myList->size = 0;
	myList->content = NULL;
	return myList;
}

void append(list* _list, int element)
{
	if(_list->size == 0)
	{
		_list->content = (int*)malloc(sizeof(int));
		_list->content[0] = element;
	}
	else
	{
		_list->content = (int*)realloc(_list->content, (_list->size + 1) * sizeof(int));
		_list->content[_list->size] = element;
	}
	_list->size++;
}

int pop(list* _list)
{
	int max = _list->size - 1;
	if(max < 0)
	{
		perror("Element can't be extracted: Negative size.");
		return -1;
	}
	int aux = _list->content[max];
	_list->content = (int*)realloc(_list->content, (max - 1) * sizeof(int));
	_list->size = max;
	return aux;
}

void showList(list* _list)
{
	printf("Cantidad de elementos en la lista: %i\n", _list->size);
	if(_list->size != 0)
	{
		int i;
		for (i = 0; i < _list->size; ++i)
		{
			printf("|%12s%3i: %2i |\n", "Elemento N°", i+1, _list->content[i]);
		}
	}
}

int myRemove(int index, list* _list)
{
	list* aux = initList();
	int number = -1;
	for (int i = 0; i < _list->size; i++)
	{
		if(i != index)
			append(aux, _list->content[i]);
		else
			number = _list->content[i];
	}
	_list = aux;
	return number;
}


