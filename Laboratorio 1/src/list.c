# include "../include/list.h"

list* initList()
{
	list* myList = (list*)malloc(sizeof(list));
	myList->size = 0;
	myList->content = NULL;
	return myList;
}

void append(list* _list, box element)
{
	if(_list->size == 0)
	{
		_list->content = (box*)malloc(sizeof(box));
		_list->content[0] = element;
	}
	else
	{
		_list->content = (box*)realloc(_list->content, (_list->size + 1) * sizeof(box));
		_list->content[_list->size] = element;
	}
	_list->size++;
}

box pop(list* _list)
{
	int max = _list->size - 1;
	if(max < 0)
	{
		perror("Element can't be extracted: Negative size.");
		return initBox(-1, -1);;
	}
	box aux = _list->content[max];
	_list->content = (box*)realloc(_list->content, (max - 1) * sizeof(box));
	_list->size = max;
	return aux;
}

void showList(list* _list)
{
	printf(" _______________________________________________________________\n");
	printf("|Cantidad de elementos en la lista: %i                           |\n", _list->size);
	if(_list->size != 0)
	{
		int i;
		for (i = 0; i < _list->size; ++i)
		{
			printf("|%12s: %3i |", "Elemento N°", i+1);
			printf("%12s: %7i |", "Inversion" , _list->content[i].inversion);
			printf("%12s: %7i |\n", "Beneficio", _list->content[i].benefit);
		}
	}
	printf(" ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――\n");
}


