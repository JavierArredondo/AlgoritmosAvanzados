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

FILE* openOutput(char* name)
{
    char* route = (char*)calloc(70, sizeof(char));
    strcat(route, "./output/");
    strcat(route, name);
    FILE* myFile = NULL;
    myFile = fopen(route, "w");
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
        for (int j = i+1; j < _list->size; j++)
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

void goloso(option* ops, FILE* output)
{
    int qty = ops[0].qty;
    for (int i = 0; i < qty; i++)
    {
        list* aux = initList();
        int out = 0;
        while(out == 0)     
        {
            int* opLocal = getOptimalLocal(ops[i].containers, ops[i].consumption);
            if(!opLocal)
                out = 1;
            else
            {
                append(aux, opLocal[0]);
                append(aux, opLocal[1]);
            }
        }
        writeOutput(aux, output);
    }
    fclose(output);
}

void writeOutput(list* solution, FILE* output)
{
    int solutions = solution->size/2;
    fprintf(output, "%i\n", solutions);
    while(solution->size != 0)
    {
        showList(solution);
        fprintf(output, "%i-%i ", solution->content[0], solution->content[1]);
        if(solution->size != 2)
            fprintf(output, "%s", "|| ");
        solution = myRemove(0, 1, solution);
    }
    fprintf(output, "%s\n", "---");
}


void printCurrent(route* myRoute, int o, int d, int w, int p)
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
}