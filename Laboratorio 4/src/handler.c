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
    word** matrix = (word**)malloc(sizeof(word*) * (a.length+1));
    for (int i = 0; i < (a.length+1); i++)
    {
        matrix[i] = (word*)malloc(sizeof(word) * (b.length+1));
        for (int j = 0; j < (b.length+1); j++)
        {
            if(i == 0 || j == 0)
                matrix[i][j] = initWord("");
        }
    }
    return matrix;
}

void showMatrix(word** M, word a, word b)
{
    printf("%11s", "e");
    for (int i = 0; i < b.length; ++i)
        printf("%10c", b.content[i]);
    printf("\n");
    for (int i = 0; i < a.length+1; ++i)
    {
        if(i == 0)
            printf("%s", "e");
        else
            printf("%c", a.content[i-1]);

        for (int j = 0; j < b.length+1; ++j)
        {
            if(M[i][j].content == NULL || strcmp(M[i][j].content,"") == 0)
                printf("%10s", "-");
            else
                printf("%10s", M[i][j].content);
        }
        printf("\n");
    }
}

int* readQtyWords(FILE* file)
{
    int qty;
    fscanf(file, "%i\n", &qty);
    int* words = (int*)calloc(qty, sizeof(int));
    for (int i = 0; i < qty; i++)
    {
        words[i]++;
        while(1)
        {
            char c = fgetc(file);
            if(c == ' ')
                words[i]++;
            else if(c == '\n' || c == EOF)
                break;
        }
    }
    rewind(file);
    return words;
}

void dinamica(FILE* input, FILE* output)
{
    int* words = readQtyWords(input);
    int qty;
    fscanf(input, "%i", &qty);
    for (int cases = 0; cases < qty; cases++)
    {
        char* w1 = (char*)malloc(sizeof(char) * 100);
        fscanf(input, "%s", w1);
        for (int wi = 1; wi < words[cases]; wi++)
        {
            char* w2 = (char*)malloc(sizeof(char) * 100);
            fscanf(input, "%s", w2);
            word A = initWord(w1);
            word B = initWord(w2);
            word** M = createMatrix(A, B);
            for (int i = 1; i < (A.length+1); i++)
            {
                for (int j = 1; j < (B.length+1); j++)
                {
                    if(A.content[i-1] == B.content[j-1])
                        M[i][j] = myConcat(M[i-1][j-1], A.content[i-1]);
                    else
                        M[i][j] = maxWord(M[i][j-1], M[i-1][j]);
                    printCurrent(M, A, B);
                }
            }
            sprintf(w1, "%s", M[A.length][B.length].content);
            free(w2);
        }
        word C = initWord(w1);
        writeOutput(C, output);
        printf("%s\n", w1);
        free(w1);
    }
    free(words);
    fclose(input);
    fclose(output);
}

void writeOutput(word solution, FILE* output)
{
    if(solution.length == 0)
        fprintf(output, "%i %s\n", 0, "palabra_vacia");
    else
        fprintf(output, "%i %s\n", solution.length, solution.content);
}


void printCurrent(word** M, word A, word B)
{
	#ifdef DEBUG
    printf("\n\n\nEnter para continuar...\n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
    printf("═══════════════════════════════════════════════════════════════════\n");
    printWord(A);
    printWord(B);
    showMatrix(M, A, B);
    printf("═══════════════════════════════════════════════════════════════════\n");
    #endif  
}