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
            {
                out = 1;
            }
            else
            {
                append(aux, opLocal[0]);
                append(aux, opLocal[1]);
            }
             printCurrent(ops[i].containers, opLocal, i, ops[i].consumption);
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
        fprintf(output, "%i-%i ", solution->content[0], solution->content[1]);
        if(solution->size != 2)
            fprintf(output, "%s", "|| ");
        solution = myRemove(0, 1, solution);
    }
    fprintf(output, "\n%s\n", "---");
}


void printCurrent(list* _list, int* opt, int caso, int cons)
{
	#ifdef DEBUG
    printf("\n\n\nEnter para continuar...\n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    printf("╔═══════════════════════════════════════════════════════════════════╗\n");
    printf("║ Caso N°%i                                                          ║\n", caso+1);
    printf("║ El avion consume %2i                                               ║\n", cons);
    if(opt)
        printf("║ Optimo local: %2i y %2i                                             ║\n", opt[0], opt[1]);
    else
        printf("║ No hay mas optimos locales, se cambia de caso                     ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════╝\n");
    printf("┏━━ Queda por consumir: \n");
    showList(_list);
    printf("┗━━\n");
    #endif  
}