# include "handler.h"
int main(int argc, char const *argv[])
{
	printf("****START****\n");
	FILE* _file = inDirectory("input.txt");
	knapsack* ks = getKnapsack(_file);
	list* l = getInversions(_file);
	showKnapsack(ks);;
	showList(l);
	bruteForce(ks, l);
	showKnapsack(ks);;
	showList(l);
	bruteForce(ks, l);
	printf("*****END*****\n");
	return 0;
}