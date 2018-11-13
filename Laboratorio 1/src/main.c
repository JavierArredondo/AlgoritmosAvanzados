# include "box.c"
# include "list.c"
# include "knapsack.c"
# include "handler.c"


# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

void title()
{
	printf("\n");
	printf("  ######  ##        #######  ##     ## ######## ########     #### ##    ## ##     ## ######## ########   ######  ####  #######  ##    ##  ######  \n");
	printf(" ##    ## ##       ##     ## ##     ## ##       ##     ##     ##  ###   ## ##     ## ##       ##     ## ##    ##  ##  ##     ## ###   ## ##    ## \n");
	printf(" ##       ##       ##     ## ##     ## ##       ##     ##     ##  ####  ## ##     ## ##       ##     ## ##        ##  ##     ## ####  ## ##       \n");
	printf(" ##       ##       ##     ## ##     ## ######   ########      ##  ## ## ## ##     ## ######   ########   ######   ##  ##     ## ## ## ##  ######  \n");
	printf(" ##       ##       ##     ##  ##   ##  ##       ##   ##       ##  ##  ####  ##   ##  ##       ##   ##         ##  ##  ##     ## ##  ####       ## \n");
	printf(" ##    ## ##       ##     ##   ## ##   ##       ##    ##      ##  ##   ###   ## ##   ##       ##    ##  ##    ##  ##  ##     ## ##   ### ##    ## \n");
 	printf("  ######  ########  #######     ###    ######## ##     ##    #### ##    ##    ###    ######## ##     ##  ######  ####  #######  ##    ##  ######  \n\n");
}

void instructions()
{
	printf("\t> Se debe tener los archivos de entrada en la carpeta input.\n");
	printf("\t> Se optimiza los valores entregados en el archivo de entrada, se espera que sigan el formato indicado en el enunciado.\n");
	printf("\t> El archivo de salida se creará en la carpeta output, con su respectivo nombre.\n");
	printf(ANSI_COLOR_GREEN"\t> Desarrollado por Javier Arredondo.\n\n"ANSI_COLOR_RESET);
}


int main(int argc, char const *argv[])
{
	char inputFilename[40];
	char outputFilename[40];
	int option = 0;
	do
	{
		system("clear");
		title();
		instructions();

		printf(" A continuación debera ingresar el nombre del archivo que posee el capital inicial, el número de inversiones disponibles y el listado de inversiones.\n");
		printf(" Nombre del archivo (con extension): ");
		scanf("%s", inputFilename);
		FILE* _file = inDirectory(inputFilename);
		while(!_file)
		{
			printf(ANSI_COLOR_YELLOW"\n Archivo %s no esta en el directorio input.\n"ANSI_COLOR_RESET, inputFilename);
			printf(" Nombre del archivo (con extension): ");
			scanf("%s", inputFilename);
			_file = inDirectory(inputFilename);
		}

		knapsack* ks = getKnapsack(_file);
		list* l = getInversions(_file);
		printf(" > Archivo de entrada:\n\n");
		showList(l);
		printf("\n");
		ks = bruteForce(ks->capital, ks->capacity, l);
		printf("\n");
		printf(" > ¿Con que nombre quieres guardar el archivo de salida (sin extension)?: \n");
		scanf("%s", outputFilename);
		writeOutput(ks, outputFilename);
		printf("\n\n\n ¿Deseas procesar otra lista de inversiones? Ingresa \"1\" para procesar otra lista, otro numero para salir: ");
		scanf("%i", &option);
	}
	while(option==1);
	printf("\n Saludos desde marte!\n");
	return 0;
}