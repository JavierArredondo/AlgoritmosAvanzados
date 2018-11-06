# include "../include/list.h"
/*	Función que inicializa una List. Esta funciona igual que una lista.
	return: Puntero a List
*/ 
list* initList()
{
	list* myList = (list*)malloc(sizeof(list));
	myList->size = 0;
	myList->content = NULL;
	return myList;
}

/*	Procedimiento que agrega un elemento a la lista List. Agrega el elemento al final de la lista. */
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
/*	Procedimiento que saca el útimo valor de la lista.
	return: Último elemento de la lista,
*/
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
	printf("Size of list: %i\n", _list->size);
	if(_list->size != 0)
	{
		int i;
		for (i = 0; i < _list->size; ++i)
		{
			printf("Elemento %i | Inversion: %i | Beneficio: %i\n", i+1, _list->content[i].inversion, _list->content[i].benefit);
		}
	}
}


