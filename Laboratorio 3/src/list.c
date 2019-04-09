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
	if(_list->size != 0)
	{
		int i;
		for (i = 0; i < _list->size; ++i)
		{
			printf("%2i ", _list->content[i]);
		}
		printf("\n");
	}
}

list* myRemove(int index, int index2, list* _list)
{
	list* aux = initList();
	for (int i = 0; i < _list->size; i++)
	{
		if(i != index && i != index2)
			append(aux, _list->content[i]);
	}
	_list->content = aux->content;
	_list->size = aux->size;
	return aux;
}

void bubbleSort(list* _list)
{
	for (int i = 1; i < _list->size; ++i)
	{
		for (int j = 0; j < _list->size-1; ++j)
		{
			if(_list->content[j] > _list->content[j+1])
			{
				int aux = _list->content[j];
				_list->content[j] = _list->content[j+1];
				_list->content[j+1] = aux;
			}
		}
	}
}
