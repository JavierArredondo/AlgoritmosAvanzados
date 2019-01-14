# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef WORD_H
# define WORD_H

typedef struct word
{
	int length; 
	char* content;
} word;

word initWord(char* input);
word maxWord(word a, word b);
word myConcat(word a, char b);
void printWord(word a);

# endif