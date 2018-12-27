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