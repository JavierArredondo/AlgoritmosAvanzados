# include "../include/option.h"

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ANSI_COLOR_CYAN "\x1b[36m"

void showOptions(option* ops)
{
	for (int i = 0; i < ops[0].qty; i++)
	{
		printf("Caso %2i\n", i+1);
		printf("Barriles: %i\n", ops[i].barrels);
		printf("Consumo avion: %i\n", ops[i].consumption);
		printf("Contenedores:");
		showList(ops[i].containers);
		printf("\n");
	}
}