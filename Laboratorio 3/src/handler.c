# include "../include/handler.h"
# define DEBUG
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

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

option* readFile(FILE* file)
{
    int qty;
    fscanf(file, "%i", &qty);
    option* options = (option*)malloc(sizeof(option) * qty);
    for (int i = 0; i < qty; i++)
    {
        option o;
        fscanf(file, "%i %i", &o.barrels, &o.consumption);
        o.containers = initList();
        o.qty = qty;
        for (int j = 0; j < o.barrels; j++)
        {
            int aux;
            fscanf(file, "%i", &aux);
            append(o.containers, aux);
        }
        bubbleSort(o.containers);
        options[i] = o;
    }
    fclose(file);
    return options;
}

int* getOptimalLocal(list* _list, int goal)
{
    int* local = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < _list->size; i++)
    {
        for (int j = 1; j < _list->size; j++)
        {
            if(_list->content[i]+_list->content[j] >= goal)
            {
                local[0] = _list->content[i];
                local[1] = _list->content[j];
                _list = myRemove(i, j, _list);
                return local;
            }
        }
    }
    return NULL;
}

void goloso(option* ops)
{
    int qty = ops[0].qty;
    for (int i = 0; i < qty; i++)
    {
        printf("Caso %i\n", i+1);
        int out = 0;
        while(out == 0)     
        {
            showList(ops[i].containers);
            int* opLocal = getOptimalLocal(ops[i].containers, ops[i].consumption);
            printf("%i %i\n", opLocal[0], opLocal[1]);
            showList(ops[i].containers);
            out = 1;

        }
    }
}


/*void printCurrent(route* myRoute, int o, int d, int w, int p)
{
	#ifdef DEBUG
    printf("\n\n\nEnter para continuar...\n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    int n = getCurrent(myRoute);
    printf("╔═══════════════════════════════════════════════════════════════════╗\n");
    printf("║ Nodo actual: %2i        Nodo destino: %2i          Costo: %2i        ║\n", o, d, w);
    if(p)
    printf(ANSI_COLOR_GREEN"║ Es posible el viaje a este destino!                               ║\n"ANSI_COLOR_RESET);
    else
    	printf(ANSI_COLOR_RED"║ Es imposible el viaje a este destino!                             ║\n"ANSI_COLOR_RESET);
    printf("╚═══════════════════════════════════════════════════════════════════╝\n");
    printf("┏━━ Recorriendo: \n");
    showRoute(myRoute);
    printf("┗━━\n");
    printf("┏━━ Óptimo parcial: \n");
    showRoute(optRoute);
    printf("┗━━\n");
    #endif  
}*/