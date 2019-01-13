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
	if(a.length >= b.length)
		return a;
	return b;
}

