# ifndef BOX_H
# define BOX_H
typedef struct box /* Structure used to store inversions.*/
{
	int size; 
	int value;
} box;

box initBox(int _size, int _value);
# endif