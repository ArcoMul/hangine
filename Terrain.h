#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "Vector3.h"
#include <glut.h>

class Terrain{
	private:
		int width;
		int length;
		float** heightData;
		Vector3** normals;
		bool computedNormals;
	public:
		//Constructor
		Terrain();
		Terrain(int w, int l);
		//Destructor
		~Terrain();
		//Width & Length
		int Width();
		int Length();
		
		//Terrain set and get height
		void SetHeight(int x, float y, int z);		//Sets the height at x and z to y
		float GetHeight(int x, int z);				//Returns the height at x and z
		
		//Computes the normals (only ones)
		void ComputeNormals();
		//Gets the just made normal at position X and Z
		Vector3 GetNormals(int x, int z);
		
		//Delete the terrain
		void CleanUp();

		void Draw();
		
};

#endif