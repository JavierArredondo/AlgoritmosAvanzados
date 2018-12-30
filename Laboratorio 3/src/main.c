# include "handler.h"

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

/* Título del programa*/
void title()
{
	printf("\n");
	printf("  ######  ##        #######  ##     ## ######## ########     \n");
	printf(" ##    ## ##       ##     ## ##     ## ##       ##     ##    \n");
	printf(" ##       ##       ##     ## ##     ## ##       ##     ##    \n");
	printf(" ##       ##       ##     ## ##     ## ######   ########     \n");
	printf(" ##       ##       ##     ##  ##   ##  ##       ##   ##      \n");
	printf(" ##    ## ##       ##     ##   ## ##   ##       ##    ##     \n");
 	printf("  ######  ########  #######     ###    ######## ##     ##    \n\n");
}

/* Instrucciones del programa*/
void instructions()
{
	printf("\t> Se debe tener los archivos de entrada en la carpeta input.\n");
	printf("\t> Se optimiza los valores entregados en el archivo de entrada, se espera que sigan el formato indicado en el enunciado.\n");
	printf("\t> El archivo de salida se creará en la carpeta output, con su respectivo nombre.\n");
	printf(ANSI_COLOR_GREEN"\t> Desarrollado por Javier Arredondo.\n\n"ANSI_COLOR_RESET);
}

/* Main del programa: llamados a funciones de otros archivos...1313*/
int main(int argc, char *argv[])
{
	int show = -1;
	system("clear");
	title();
	instructions();
	if(argv[1] == NULL || argv[2] == NULL)
	{
		printf("Faltan los parametros de entrada.\n");
		return -1;
	}
	FILE* _file = inDirectory(argv[1]);
	option* set = readFile(_file);
	showOptions(set);
	goloso(set);
	printf("\n Saludos desde marte, terricola!\n");
	return 0;
}