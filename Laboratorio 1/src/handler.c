# include "../include/handler.h"
# define DEBUG
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
		fscanf(_file, "%i", &_box.inversion);
		fscanf(_file, "%i", &_box.benefit);
		append(_list, _box);
	}
	fclose(_file);
	return _list;
}

int allInKnapsack(knapsack* ks, list* elements)
{
    int total = 0;
    for (int i = 0; i < elements->size; i++)
        total = total + elements->content[i].inversion;
    if(total <= ks->capacity)
        return 1;
    return 0;
}

int myPow(int base, int exp)
{
    int res = 1;
    for (int i = 0; i < exp; i++)
        res = res * base;
    return res;
}

int* toBin(int number, int longi)
{
    int* aux = (int*)calloc(longi, sizeof(int));
    for (int i = 0; i < longi; i++)
    {
        aux[i] =  number % 2;;
        number = number/2; 
    }
    return aux;
}

int** makeCombinatory(int size)
{
    int posibles = myPow(2, size); /* Combinaciones posibles.*/
    int** matrix = (int**)malloc(sizeof(int*) * posibles);
    for (int i = 0; i < posibles; i++)
        matrix[i] = toBin(i, size);
    return matrix;
}

void printCurrent(knapsack* ks, int i)
{
    #ifdef DEBUG
    printf("\nEnter para continuar...\n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    printf(" ________________________________________________________________\n");
    printf("|Analizando combinacion %4i                                     |\n", i+1);
    showKnapsack(ks);
    #endif   
}

knapsack* bruteForce(int capital, int capacity, list* elements)
{
    int optimum = 0;
    int indexOpt = 0;
    int posibles = myPow(2, elements->size);
    int** matrix = makeCombinatory(elements->size);
    knapsack** kss = initVeryKnapsack(capital, capacity, posibles);
    for (int i = 0; i < posibles; i++)
    {
        for (int j = 0; j < elements->size; j++)
        {
            if(matrix[i][j])
                add(kss[i], elements->content[j]);
        }
        if(kss[i]->capacity >= 0 && kss[i]->capital >= 0 && kss[i]->benefits > optimum)
        {
            optimum = kss[i]->benefits;
            indexOpt = i;
            printf(ANSI_COLOR_CYAN" ^ Es el nuevo optimo ^\n"ANSI_COLOR_RESET);
        }
        printCurrent(kss[i], i);
    }
    printf("\nLa combinacion que se adecua a los criterios de optimizacion es la combinacion %i\n", indexOpt);
    showKnapsack(kss[indexOpt]);
    return kss[indexOpt];
}

void writeOutput(knapsack* ks, char* filename)
{
    char* route = (char*)calloc(70, sizeof(char));
    strcat(route, "./output/");
    strcat(route, filename);
    strcat(route, ".out");
    FILE* myFile = NULL;
    myFile = fopen(route, "w");
    int k0 = 0;
    for (int i = 0; i < ks->size; i++)
        k0 = k0 + ks->boxes[i].inversion;
    fprintf(myFile, "%i %i\n", k0, ks->benefits);
    for (int i = 0; i < ks->size; i++)
        fprintf(myFile, "%i\n", ks->boxes[i].inversion);
    fclose(myFile);
    printf(" > Archivo guardado con exito en la carpeta output.\n");
}