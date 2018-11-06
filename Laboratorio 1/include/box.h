# ifndef BOX_H
# define BOX_H
/* 
Structure used to store inversions.
inversion: prize of the inversion.
benefit: benefit of the inversion.
*/
typedef struct box
{
	int inversion; 
	int benefit;
} box;
/*
For create a new inversion, called box.
@params _inversion: inversion of the box.
@params _benefit: benefit of the box.
@return new box initialized. 
*/
box initBox(int _inversion, int _benefit);
# endif