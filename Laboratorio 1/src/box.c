# include "../include/box.h"
box initBox(int _inversion, int _benfit){
	box _box;
	_box.inversion = _inversion;   // inversion
	_box.benefit = _benfit; // beneficio
	return _box;
}