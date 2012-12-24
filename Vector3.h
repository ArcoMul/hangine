#ifndef VECTOR3_H_INCLUDED
#define VECTOR3_H_INCLUDED

#include <iostream>
#include <cmath>

class Vector3{
	public:
		//*********************************************************
		//Fields
		//*********************************************************
		float X,Y,Z;


		//*********************************************************
		//Constructors
		//*********************************************************
		Vector3();
		Vector3(float value);
		//Vector3(Vector2, float z);
		Vector3(float x, float y, float z);


		//*********************************************************
		//Operator Calculates
		//*********************************************************
		Vector3 operator*(float scale);				
		Vector3 operator/(float scale);			
		Vector3 operator+(const Vector3& vec);		
		Vector3 operator-(const Vector3& vec);		

		//Calcate references
		Vector3& operator*=(float scale);		
		Vector3& operator/=(float scale);		
		Vector3& operator+=(const Vector3& vec);	
		Vector3& operator-=(const Vector3& vec);	

		//for comparing vectors
		bool operator==(const Vector3 vec);
		bool operator!=(const Vector3 vec);


		//*********************************************************
		//Function Calculates
		//*********************************************************
		//Length
		float Length();
		
		//Clamp
		
		//Cross
		/*Vector3 CrossProduct(const Vector3& vec);

		//Distance between 2 vectors
		
		//Dot
		float DotProduct(const Vector3& vec);
		
		//Normalize
		void Normalize();*/

		//Magnitude
		float magnitude() const;
		float magnitudeSquared() const;
		Vector3 normalize() const;
		float dot(const Vector3 &other) const;
		Vector3 cross(const Vector3 &other) const;


		//change X, Y, Z in one function
		void SetAll(float newX, float newY, float newZ);
		void SetAll(Vector3& vec);		//Get Vector3 reference 
		void SetAll(Vector3 vec);		//Get Vector3 object
		void SetX(float value);
		void SetY(float value);
		void SetZ(float value);

		//*********************************************************
		//Directions
		//Examples: Up, down, left etc...
		//*********************************************************


		//*********************************************************
		//Print the vector (does not work yet)
		//*********************************************************
		//friend std::ostream& operator<<(std::ostream& output, cost Vector3& vec);

};


#endif
