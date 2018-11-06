# ifndef BOX_H
# define BOX_H
typedef struct box /* Structure used to store inversions.*/
{
	int inversion; 
	int benefit;
} box;

box initBox(int _size, int _value);
# endif