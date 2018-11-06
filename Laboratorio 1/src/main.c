# include "handler.h"

int main(int argc, char const *argv[])
{
	printf("****START****\n");
	FILE* _file = inDirectory("input.txt");
	knapsack* ks = getKnapsack(_file);
	list* l = getInversions(_file);
	list** o = (list**)malloc(sizeof(list*) * l->size);
	for(int i = 0; i < l->size; i++)
	{
		o[i] = initList();
	}
	//showKnapsack(ks);;
	//showList(l);
	//showKnapsack(ks);;
	//showList(l);
	int opt = 0;
	int idx = 0;
	int solucion = 0;
	bruteForce(ks->capital, ks->capacity, l);
	printf("%i\n", opt);
	showKnapsack(ks);
	printf("*****END*****\n");
	return 0;
}