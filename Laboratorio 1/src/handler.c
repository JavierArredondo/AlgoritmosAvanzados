# include "../include/handler.h"
/* Función que verifica si un archivo existe en el directorio. 
   name: Nombre del arrchivo (con extensión) que se quiere buscar en el directorio. 
   return: Puntero al archivo.. */
FILE* inDirectory(char* name)
{
	char* route = (char*)calloc(60, sizeof(char));
	strcat(route, "./input/");
	strcat(route, name);
	FILE* myFile = NULL;
	myFile = fopen(route, "r");
	if(!myFile)
		return NULL;
	return myFile;
}

knapsack* getKnapsack(FILE* _file)
{
	knapsack* ks = initMyKnapsack(0, 0);
	fscanf(_file, "%i", &ks->capital);
	fscanf(_file, "%i", &ks->capacity);
	return ks;
}

list* getInversions(FILE* _file)
{
	list* _list = initList();
	while(!feof(_file))
	{
		box _box = initBox(0, 0);
		fscanf(_file, "%i", &_box.size);
		fscanf(_file, "%i", &_box.value);
		append(_list, _box);

	}
	fclose(_file);
	return _list;
}

void bruteForce(knapsack* _knapsack, list* _list)
{
	printf("brute force\n");
	int n = _list->size;
	int w = _knapsack->capacity;
	int *mm = calloc((w + 1 ) * (n + 1), sizeof(int)); /*Combinaciones posibles*/
	int **m = malloc((n + 1) * sizeof(int*));
	m[0] = mm;
	int i, j, a, b;
	for(i = 1; i <= n; i++)
	{
		m[i] = &mm[i * (w + 1)];
		for (j = 0; j <= w; j++)
		{
			if(_list->content[i - 1].size > j)
				m[i][j] = m[i - 1][j];
			else
			{
				a = m[i - 1][j];
                b = m[i - 1][j - _list->content[i - 1].size] + _list->content[i - 1].value;
                m[i][j] = a > b ? a : b;
			}
		}
	}
	int *s = calloc(n, sizeof (int));
    for (i = n, j = w; i > 0; i--) {
        if (m[i][j] > m[i - 1][j]) {
            s[i - 1] = 1;
            j -= _list->content[i - 1].size;
        }
    }
    int tw = 0, tv = 0;
    for (i = 0; i < n; i++) {
        if (s[i]) {
            printf("%5d %5d\n", _list->content[i].size, _list->content[i].value);
            tw += _list->content[i].size;
            tv += _list->content[i].value;
        }
    }
    printf("%-22s %5d %5d\n", "totals:", tw, tv);
}

/*
int *knapsack (item_t *items, int n, int w) {
    int i, j, a, b, *mm, **m, *s;
    mm = calloc((n + 1) * (w + 1), sizeof (int));
    m = malloc((n + 1) * sizeof (int *));
    m[0] = mm;
    for (i = 1; i <= n; i++) {
        m[i] = &mm[i * (w + 1)];
        for (j = 0; j <= w; j++) {
            if (items[i - 1].weight > j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                a = m[i - 1][j];
                b = m[i - 1][j - items[i - 1].weight] + items[i - 1].value;
                m[i][j] = a > b ? a : b;
            }
        }
    }
    s = calloc(n, sizeof (int));
    for (i = n, j = w; i > 0; i--) {
        if (m[i][j] > m[i - 1][j]) {
            s[i - 1] = 1;
            j -= items[i - 1].weight;
        }
    }
    free(mm);
    free(m);
    return s;
}
 
int main () {
    int i, n, tw = 0, tv = 0, *s;
    n = sizeof (items) / sizeof (item_t);
    s = knapsack(items, n, 400);
    for (i = 0; i < n; i++) {
        if (s[i]) {
            printf("%-22s %5d %5d\n", items[i].name, items[i].weight, items[i].value);
            tw += items[i].weight;
            tv += items[i].value;
        }
    }
    printf("%-22s %5d %5d\n", "totals:", tw, tv);
    return 0;
}
*/