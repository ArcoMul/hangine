#include <iostream>
#include <glut.h>
#include "Vector3.h"
#include "Terrain.h"

using namespace std;

Terrain::Terrain(){
	cout << "Hello" << endl;

	width = 128;
	length = 128;

	heightData = new float*[1];
	for(int i = 0; i < 1; i++)
		heightData[i] = new float[width];
	
	normals = new Vector3*[1];
	for(int i = 0; i < 1; i++)
		normals[i] = new Vector3[width];
	
	
	computedNormals = false;
}

Terrain::Terrain(int w, int l){
	width = w;
	length = l;

	heightData = new float*[width];
	//normals = new Vector3*[width];
	computedNormals = false;

}

//Destructor
Terrain::~Terrain(){
	for(int i = 0; i < 1; i++)
		delete[] heightData[i];
	
	delete[] heightData;

	for(int i = 0; i < 1; i++)
		delete[] normals[i];

	delete[] normals;
}


//Width & Length
int Terrain::Width(){
	return width;
}
int Terrain::Length(){
	return length;
}
		
//Terrain set and get height
void Terrain::SetHeight(int x, float y, int z){		//Sets the height at x and z to y
	heightData[z][x] = y;
	computedNormals = false;
}


float Terrain::GetHeight(int x, int z){				//Returns the height at x and z
		return heightData[z][x];
}

//Computes the normals (only ones)
		//Computes the normals, if they haven't been computed yet
		void Terrain::ComputeNormals() {
			int l = 128;
			int w = 128;
			
			if (computedNormals) {
				return;
			}
			
			//Compute the rough version of the normals
			Vector3** normals2 = new Vector3*[l];
			for(int i = 0; i < l; i++) {
				normals2[i] = new Vector3[w];
			}
			
			for(int z = 0; z < l; z++) {
				for(int x = 0; x < w; x++) {
					Vector3 sum(0.0f, 0.0f, 0.0f);
					
					Vector3 out;
					if (z > 0) {
						out = Vector3(0.0f, heightData[z - 1][x] - heightData[z][x], -1.0f);
					}
					Vector3 in;
					if (z < l - 1) {
						in = Vector3(0.0f, heightData[z + 1][x] - heightData[z][x], 1.0f);
					}
					Vector3 left;
					if (x > 0) {
						left = Vector3(-1.0f, heightData[z][x - 1] - heightData[z][x], 0.0f);
					}
					Vector3 right;
					if (x < w - 1) {
						right = Vector3(1.0f, heightData[z][x + 1] - heightData[z][x], 0.0f);
					}
					
					if (x > 0 && z > 0) {
						sum += out.cross(left).normalize();
					}
					if (x > 0 && z < l - 1) {
						sum += left.cross(in).normalize();
					}
					if (x < w - 1 && z < l - 1) {
						sum += in.cross(right).normalize();
					}
					if (x < w - 1 && z > 0) {
						sum += right.cross(out).normalize();
					}
					
					normals2[z][x] = sum;
				
			}
			
			//Smooth out the normals
			const float FALLOUT_RATIO = 0.5f;
			for(int z = 0; z < l; z++) {
				for(int x = 0; x < w; x++) {
					Vector3 sum = normals2[z][x];
					
					if (x > 0) {
						sum += normals2[z][x - 1] * FALLOUT_RATIO;
					}
					if (x < w - 1) {
						sum += normals2[z][x + 1] * FALLOUT_RATIO;
					}
					if (z > 0) {
						sum += normals2[z - 1][x] * FALLOUT_RATIO;
					}
					if (z < l - 1) {
						sum += normals2[z + 1][x] * FALLOUT_RATIO;
					}
					
					if (sum.magnitude() == 0) {
						sum = Vector3(0.0f, 1.0f, 0.0f);
					}
					normals[z][x] = sum;
				}}
			}
			
			for(int i = 0; i < l; i++) {
				delete[] normals2[i];
			}
			delete[] normals2;
			
			computedNormals = true;
		}

//Gets the just made normal at position X and Z
Vector3 Terrain::GetNormals(int x, int z){
	if(!computedNormals)
		ComputeNormals();
	
	return normals[z][x];
}


void Terrain::Draw(){
	glColor3f(0.3f, 0.9f, 0.0f);
	for(int z = 0; z < length -1 ; z++){
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < width; x++){
			Vector3 normal = GetNormals(x,z);
			glNormal3f(normal.X, normal.Y, normal.Z);
			glVertex3f(x, GetHeight(x, z), z);
			normal = GetNormals(x,z + 1);
			glNormal3f(normal.X, normal.Y, normal.Z);
			glVertex3f(x, GetHeight(x, z + 1), z + 1);
		}
		glEnd();
	}
}