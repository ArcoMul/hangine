#include <iostream>
#include "cube.h"
#include <glut.h>

cube::cube(){
	position = Vector3(0,0,0);
	size = Vector3(1,1,1);
}

cube::cube(Vector3 _size, Vector3 _position){
	position = _position;
	size = _size;
}

void cube::Draw(){
	glBegin(GL_QUADS);
	
	//Set the color (grey) for al the quads
	glColor3f(0.92f, 0.92f,0.92f);


	//glNormal3d.. is for setting the normal of every quad. For lighting!

	//Top face
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	
	//Bottom face
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));

	//Left face
	glNormal3f(0.0f, 1.0f, 1.0f);
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	
	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));
	
		//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (size.Z / 2));
	
	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glVertex3f(position.X + (-size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (-size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (size.Y / 2), position.Z + (-size.Z / 2));
	glVertex3f(position.X + (size.X / 2), position.Y + (-size.Y / 2), position.Z + (-size.Z / 2));

	glEnd();
}


void cube::Update(){

}