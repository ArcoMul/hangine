#include "Vector3.h"

using namespace std;



//*********************************************************
//Constructors
//*********************************************************
//Vector3::Vector3(Vector2, float z);

Vector3::Vector3(){
	X = 0;
	Y = 0;
	Z = 0;
}

Vector3::Vector3(float value){
	X = value;
	Y = value;
	Z = value;
}


Vector3::Vector3(float x, float y, float z){
	X = x;
	Y = y;
	Z = z;
}


//*********************************************************
//Operator Calculates
//*********************************************************
// operator *
Vector3 Vector3::operator*(float scale){
	return Vector3(X * scale, Y * scale, Z * scale);
}

// operator /
Vector3 Vector3::operator/(float scale){
	//We don't want to devide by 0. If it does, return an empty vector object
	if(scale!=0)
		return Vector3(X / scale, Y / scale, Z / scale);
	else
		return Vector3();
}

// operator +
Vector3 Vector3::operator+(const Vector3& vec){
	return Vector3(X + vec.X, Y + vec.Y, Z + vec.X);
}

// operator -
Vector3 Vector3::operator-(const Vector3& vec){
	return Vector3(X - vec.X, Y - vec.Y, Z - vec.X);
}


//Calcate references
Vector3& Vector3::operator*=(float scale){
	X *=scale;
	Y *=scale;
	Z *=scale;
	return *this;	//Return reference of this pointer
}

Vector3& Vector3::operator/=(float scale){
	if(scale!=0){
		X /=scale;
		Y /=scale;
		Z /=scale;
	}
	return *this;	//Return reference of this pointer
}

Vector3& Vector3::operator+=(const Vector3& vec){
	X+=vec.X;
	Y+=vec.Y;
	Z+=vec.Z;
	return *this;	//Return reference of this pointer
}
Vector3& Vector3::operator-=(const Vector3& vec){
	X-=vec.X;
	Y-=vec.Y;
	Z-=vec.Z;
	return *this;	//Return reference of this pointer
}

//for comparing vectors
bool Vector3::operator==(const Vector3 vec){
	return (X==vec.X && Y==vec.Y && Z==vec.Z);
}

bool Vector3::operator!=(const Vector3 vec){
	//this is a reference to the Vector3::operator==(const Vector3 vec).
	return !(*this==vec);
}


//*********************************************************
//Function Calculates
//*********************************************************

//Length
float Vector3::Length(){
	return sqrt(X*X + Y*Y + Z*Z);
}

//Dot
/*float Vector3::DotProduct(const Vector3& vec){
	return (X * vec.X + Y * vec.Y + Z * vec.Z);
}

	
//Normalize
void Vector3::Normalize(){
	float len = Length();
	if(len!=0){
		X/=len;
		Y/=len;
		Z/=len;

	}
}
*/

float Vector3::magnitude() const {
	return sqrt(X * X + Y * Y + Z * Z);
}

float Vector3::magnitudeSquared() const {
	return X * X + Y * Y + Z * Z;
}

Vector3 Vector3::normalize() const {
	float m = sqrt(X * X + Y * Y + Z * Z);
	return Vector3(X / m, Y / m, Z / m);
}

float Vector3::dot(const Vector3 &other) const {
	return X * X + Y * other.Y + Z * other.Z;
}

Vector3 Vector3::cross(const Vector3 &other) const {
	return Vector3(Y * Z - Z * other.Y,
				 Z * X - X * other.Z,
				 Z * other.Y - Y * other.Z);
}

//change X, Y, Z in one function
void Vector3::SetAll(float newX, float newY, float newZ){
	X = newX;
	Y = newY;
	Z = newZ;
}
void Vector3::SetAll(Vector3& vec){
	X = vec.X;
	Y = vec.Y;
	Z = vec.Z;
}
void Vector3::SetAll(Vector3 vec){
	X = vec.X;
	Y = vec.Y;
	Z = vec.Z;
}

void Vector3::SetX(float value){
	X = value;
}
void Vector3::SetY(float value){
	Y = value;
}
void Vector3::SetZ(float value){
	Z = value;
}

//Clamp

//Cross ( not finished yet )
//Vector3 Vector3::CrossProduct(const Vector3& vec){
//	return ...
//}

//Distance between 2 vectors
		

//*********************************************************
//Print the vector (does not work yet)
//*********************************************************
//friend ostream& Vector3::operator<<(ostream& output, cost Vector3& vec){
//	output << vec.X << " " << vec.Y << " " << vec.Z <<endl;
//}






