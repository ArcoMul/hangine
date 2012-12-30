#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED
#include "Vector3.h"
class cube{
	public:
		Vector3 size;
		Vector3 position;
	
		//Constructors
		cube();
		cube(Vector3 _size, Vector3 _position);
		void Draw();
		void Update();

};

#endif