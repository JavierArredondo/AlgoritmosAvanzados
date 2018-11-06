# include "handler.h"

int main(int argc, char const *argv[])
{
	printf("****START****\n");
	FILE* _file = inDirectory("input.txt");
	knapsack* ks = getKnapsack(_file);
	list* l = getInversions(_file);
	showList(l);
	printf("\n");
	ks = bruteForce(ks->capital, ks->capacity, l);
	printf("*****END*****\n");
	return 0;
}