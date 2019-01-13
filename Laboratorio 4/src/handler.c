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

word** createMatrix(word a, word b)
{
    word** matrix = (word**)malloc(sizeof(word*) * a.length);
    for (int i = 0; i < a.length; i++)
    {
        matrix[i] = (word*)malloc(sizeof(word) * b.length);
        for (int j = 0; j < b.length; j++)
        {
            if(i == 0 | j == 0)
                matrix[i][j] = initWord("");
        }
    }
    return matrix;
}

void dinamica(FILE* input, FILE* output)
{
    int qty;
    fscanf(input, "%i", &qty);
    for (int cases = 0; cases < qty; cases++)
    {
        char* w1 = (char*)malloc(sizeof(char) * 100);
        char* w2 = (char*)malloc(sizeof(char) * 100);
        fscanf(input, "%s", w1);
        fscanf(input, "%s", w2);
        word A = initWord(w1);
        word B = initWord(w2);



        free(w1);
        free(w2);
    }
}

void writeOutput(word solution, FILE* output)
{

}


void printCurrent()
{
	#ifdef DEBUG
    printf("\n\n\nEnter para continuar...\n");
    #endif  
}