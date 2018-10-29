# include "../include/box.h"
box initBox(int _size, int _value){
	box _box;
	_box.size = _size;   // inversion
	_box.value = _value; // beneficio
	return _box;
}