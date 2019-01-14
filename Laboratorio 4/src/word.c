# include "../include/word.h"

word initWord(char* input)
{
	word response;
	response.length = 0;
	response.content = input;
	for (int i = 0; input[i] != '\0'; i++)
		response.length++;
	return response;
}

word maxWord(word a, word b)
{
	if(a.length > b.length)
		return a;
	return b;
}

word myConcat(word a, char b)
{
	char* response = (char*)malloc(sizeof(char) * (a.length+1));
	sprintf(response, "%s", a.content);
	response[a.length] = b;
	word c = initWord(response);
	return c;
}

void printWord(word a)
{
	printf("%s: %i\n", a.content, a.length);
}