
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;


namespace MathLibrary {
	
	struct Vector3 {

		float x, y, z;


		Vector3() {

			x = 0;
			y = 0;
			z = 0;

		}

		Vector3(float XX, float YY, float ZZ) {
		
			x = XX;
			y = YY;
			z = ZZ;
		
		}

		Vector3(const Vector3& Copy) {

			x = Copy.x;
			y = Copy.y;
			z = Copy.z;

		}


		Vector3 operator+(const Vector3& op) {

			Vector3 temp;
			temp.x = x + op.x;
			temp.y = y + op.y;
			temp.z = z + op.z;

			return temp;
		}

		Vector3 operator-(const Vector3& op) {

			Vector3 temp;
			temp.x = x - op.x;
			temp.y = y - op.y;
			temp.z = z - op.z;

			return temp;
		}

		Vector3 operator*(const Vector3& op) {

			Vector3 temp;
			temp.x = x * op.x;
			temp.y = y * op.y;
			temp.z = z * op.z;

			return temp;
		}

		Vector3 operator*(const float& op) {

			Vector3 temp;
			temp.x = x * op;
			temp.y = y * op;
			temp.z = z * op;

			return temp;
		}

		Vector3 operator/(const float& op) {

			Vector3 temp;
			temp.x = x / op;
			temp.y = y / op;
			temp.z = z / op;

			return temp;
		}

		Vector3 operator=(const Vector3& op) {

			x = op.x;
			y = op.y;
			z = op.z;

			return *this;
		}

		Vector3 operator+=(const Vector3& op) {

			x += op.x;
			y += op.y;
			z += op.z;

			return *this;
		}

		Vector3 operator-=(const Vector3& op) {

			x -= op.x;
			y -= op.y;
			z -= op.z;

			return *this;
		}

		Vector3 operator*=(const Vector3& op) {

			x *= op.x;
			y *= op.y;
			z *= op.z;

			return *this;
		}

		Vector3 operator*=(const float& op) {

			x *= op;
			y *= op;
			z *= op;

			return *this;
		}

		Vector3 operator/=(const float& op) {

			x /= op;
			y /= op;
			z /= op;

			return *this;
		}

		Vector3 operator-() {

			x *= -1;
			y *= -1;
			z *= -1;

			return *this;
		}

		bool operator==(const Vector3& op) {
			return (x == op.x && y == op.y && z == op.z);
		}

		bool operator!=(const Vector3& op) {
			return (x != op.x || y != op.y || z != op.z);
		}
		
		bool operator<(const Vector3& op) {

			Vector3 temp1 = *this;
			temp1 *= temp1;
			float mag1 = (temp1.x + temp1.y + temp1.z);        // Gets the XYZ values squared and added. The two magnitudes don't need to be
															   // square-rooted back down because they are BOTH squared, their relationship
			Vector3 temp2 = op;                                // to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= temp2;
			float mag2 = (temp2.x + temp2.y + temp2.z);

			return (mag1 < mag2);
		}

		float operator[](int i) {          // Originally i used switch cases but this felt more efficient, i make a temporary vector of the
										   // current Vector3's XYZ values, then just use the input int to return the float at that index.
			
			float XYZ[3] {x,y,z};
			
			return XYZ[i];

		}


		float Dot(const Vector3& op) {
			
			return x*op.x + y*op.y + z*op.z;

		}

		Vector3 Cross(const Vector3& op) {

		return {y * op.z - z * op.y, z * op.x - x * op.z, x * op.y - y * op.x};
		
		}
		
		float Magnitude() {
		
		return sqrt(x * x + y * y + z * z);
		
		}
		
		void Normalise() {								// Not sure what the difference will be between this function
														// and the one below, i'll hopefully find out as i go.
			*this / Magnitude();
			
			return;
		
		}
		
		Vector3 Normalised() {				// These don't need an input because unlike regular functions, as members of structs they technically
											// always have the object they are from fed into/accessible from within the function by default.
			Vector3 temp = *this;
			
			return temp / Magnitude();
		
		}
		
		bool IsApproximatelyEqual(const Vector3& op, float E) {				
																	// By subtracting one from the other, if they are very similar the magnitude of
			return (*this - op).Magnitude() < E;					// the resulting vector3 should be close to 0. I worry about how this would work
																	// for vector4s as quaternions though, as any given rotation can be represented
		}															// by two different sets of values, like 1 0 0 0 and -1 0 0 0, for example.
		
		float AngleBetween(Vector3& op) {
		
			return acos(Normalised().Dot(op.Normalised()));
		
		}
		
		float Distance(const Vector3& op) {
		
			return (*this - op).Magnitude();
		
		}
		
		float Angle2D() {									// Assessment had confusing wording for this part, said it wants the angle around
															// XY from 1,0 but early on it mentions that for 2D stuff x=forward and y=right.
			float XYroot = sqrt(x * x + y * y);				// Also i had to include <math.h> to get proper PI here, hopefully that's allowed.
			
			return atan2(y / XYroot, x / XYroot) * (180 / M_PI);		
		
		}

	};

	struct Vector4 {

		float x, y, z, w;


		Vector4() {

			x = 0;
			y = 0;
			z = 0;
			w = 0;

		}

		Vector4(float XX, float YY, float ZZ, float WW) {

			x = XX;
			y = YY;
			z = ZZ;
			w = WW;

		}

		Vector4(const Vector4& Copy) {

			x = Copy.x;
			y = Copy.y;
			z = Copy.z;
			w = Copy.w;

		}


		Vector4 operator+(const Vector4& op) {

			Vector4 temp;
			temp.x = x + op.x;
			temp.y = y + op.y;
			temp.z = z + op.z;
			temp.w = w + op.w;

			return temp;
		}

		Vector4 operator-(const Vector4& op) {

			Vector4 temp;
			temp.x = x - op.x;
			temp.y = y - op.y;
			temp.z = z - op.z;
			temp.w = w + op.w;

			return temp;
		}

		Vector4 operator*(const Vector4& op) {

			Vector4 temp;
			temp.x = x * op.x;
			temp.y = y * op.y;
			temp.z = z * op.z;
			temp.w = w + op.w;

			return temp;
		}

		Vector4 operator*(const float& op) {

			Vector4 temp;
			temp.x = x * op;
			temp.y = y * op;
			temp.z = z * op;

			return temp;
		}

		Vector4 operator/(const float& op) {

			Vector4 temp;
			temp.x = x / op;
			temp.y = y / op;
			temp.z = z / op;

			return temp;
		}

		Vector4 operator=(const Vector4& op) {

			x = op.x;
			y = op.y;
			z = op.z;
			w = op.w;

			return *this;
		}

		Vector4 operator+=(const Vector4& op) {

			x += op.x;
			y += op.y;
			z += op.z;
			w += op.w;

			return *this;
		}

		Vector4 operator-=(const Vector4& op) {

			x -= op.x;
			y -= op.y;
			z -= op.z;
			w += op.w;

			return *this;
		}

		Vector4 operator*=(const Vector4& op) {

			x *= op.x;
			y *= op.y;
			z *= op.z;
			w += op.w;

			return *this;
		}

		Vector4 operator*=(const float& op) {

			x *= op;
			y *= op;
			z *= op;

			return *this;
		}

		Vector4 operator/=(const float& op) {

			x /= op;
			y /= op;
			z /= op;

			return *this;
		}

		Vector4 operator-() {

			x *= -1;
			y *= -1;
			z *= -1;

			return *this;
		}

		bool operator==(const Vector4& op) {
			return (x == op.x && y == op.y && z == op.z && w == op.w);
		}

		bool operator!=(const Vector4& op) {
			return (x != op.x || y != op.y || z != op.z || w != op.w);
		}

		bool operator<(const Vector4& op) {

			Vector4 temp1 = *this;
			temp1 *= *this;
			float mag1 = (temp1.x + temp1.y + temp1.z);				// Gets the XYZ values squared and added. The two magnitudes don't need to be
																	// square-rooted back down because they are BOTH squared, their relationship
			Vector4 temp2 = op;										// to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= op;
			float mag2 = (temp2.x + temp2.y + temp2.z);

			return (mag1 < mag2);
		}

		float operator[](int i) {          // Originally i used switch cases but this felt more efficient, i make a temporary vector of the
										   // current Vector4's XYZ values, then just use the input int to return the float at that index.
			float XYZW[4] {x,y,z,w};

			return XYZW[i];

		}


		float Dot(const Vector4& op) {

			return x*op.x + y*op.y + z*op.z;

		}

		Vector4 Cross(const Vector4& op) {

			return {y * op.z - z * op.y, z * op.x - x * op.z, x * op.y - y * op.x, w + op.w};

		}

		float Magnitude() {

			return sqrt(x * x + y * y + z * z);

		}

		void Normalise() {								// Not sure what the difference will be between this function
														// and the one below, i'll hopefully find out as i go.
			*this / Magnitude();

			return;

		}

		Vector4 Normalised() {				// These don't need an input because unlike regular functions, as members of structs they technically
											// always have the object they are from fed into/accessible from within the function by default.
			Vector4 temp = *this;

			return temp / Magnitude();

		}

		bool IsApproximatelyEqual(const Vector4& op, float E) {				
																	// By subtracting one from the other, if they are very similar the magnitude of
			return (*this - op).Magnitude() < E;					// the resulting vector3 should be close to 0. I worry about how this would work
																	// for vector4s as quaternions though, as any given rotation can be represented
		}															// by two different sets of values, like 1 0 0 0 and -1 0 0 0, for example.

		float AngleBetween(Vector4& op) {

			return acos(Normalised().Dot(op.Normalised()));

		}

		float Distance(const Vector4& op) {

			return (*this - op).Magnitude();

		}


	};

	struct Matrix3 {

		union {
			struct {
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;					// I'm using this union so i can read these 9 floats in any format i want while
			};																// still technically satisfying what the assessment wants from me, wholly separate
			float arr[9];													// variables are super tedious to write code for, often for loops make the code
			float grid[3][3];												// waayyy more compact and pleasant to read.
		};


		Matrix3() {

			for (int i = 0; i < 9; i++) {

				if (i % 4 == 0) {
					arr[i] = 1;
				}
				else {
					arr[i] = 0;
				}

			}

		}

		Matrix3(float ALL) {

			for (int i = 0; i < 9; i++) {		// This constructor takes a Matrix declaration with just 1 float
												// and assumes the user wants to build the Matrix3 with all stored
				arr[i] = ALL;					// floats being the same. Mostly just useful for   Matrix3.arr = 0;

			}

		}

		Matrix3(initializer_list<float> m) {
			
			int i = 0;							// This constructor allows the user to specifically declare the value
			for (float m : m) {					// of each stored float on construction without having to be written as
				arr[i] = m;						// m1,m2,m3,m4,etc. Still learning how initializer_lists work,
				i++;
			}

		}

		Matrix3(const Matrix3& Copy) {

			for (int i = 0; i < 9; i++) {

				arr[i] = Copy.arr[i];

			}

		}


		Matrix3 operator=(const Matrix3& op) {

			for (int i = 0; i < 9; i++) {

				arr[i] = op.arr[i];

			}

			return *this;

		}

		Vector3 operator*(const Vector3& op) {

			Vector3 temp;

			temp.x = grid[0][0] * op.x + grid[0][1] * op.y + grid[0][2] * op.z;			// Still wrapping my head around this, so the vector's X must be multiplied
			temp.y = grid[1][0] * op.x + grid[1][1] * op.y + grid[1][2] * op.z;			// by one of Matr's full vectors, M0x * Vx + M0y * Vx + M0z * Vx ? I'm not
			temp.z = grid[2][0] * op.x + grid[2][1] * op.y + grid[2][2] * op.z;			// sure what this is for and need to look into it more.

		return temp;
		
		}
		
		Matrix3 operator*(const Matrix3& op) {
		
			Matrix3 temp = 0;

			for (int A = 0; A < 3; A++) {
				for (int B = 0; B < 3; B++) {
					for (int C = 0; C < 3; C++) {
						temp.grid[A][B] += grid[A][C] * op.grid[C][B];
					}
				}
			}

			return temp;
		
		}
		
		Matrix3 operator*=(const Matrix3& op) {
		
			*this = *this * op;
			
			return *this;
		
		}
		
		bool operator==(const Matrix3& op) {

			for (int i = 0; i < 9; i++) {
				if (arr[i] != op.arr[i]) {
					return false;
				}
			}

			return true;
		
		}
		
		bool operator!=(const Matrix3& op) {
		
			for (int i = 0; i < 9; i++) {
				if (arr[i] != op.arr[i]) {
					return true;
				}
			}

			return false;
		
		}
		
		float operator[](int i) {
		
			return arr[i];
		
		}


		//Matrix3 MakeRotate(float op) {
		//
		//	return;
		//
		//}
		//
		//Matrix3 MakeScale(const Vector3& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix3 MakeTransform(const Vector3& op) {
		//
		//	return;
		//
		//}
		//
		//Vector3 GetRight() {
		//
		//	return;
		//
		//}
		//
		//Vector3 GetForward() {
		//
		//	return;
		//
		//}
		//
		//Vector3 GetTranslate() {
		//
		//	return;
		//
		//}
		//
		//bool IsApproximatelyEqual(const Matrix3& op, float E) {
		//
		//	return;
		//
		//}

	};

	struct Matrix4 {

		union {
			struct {
				float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
			};
			float arr[16];
			float grid[4][4];
		};


		Matrix4() {

			for (int i = 0; i < 16; i++) {

				if (i % 5 == 0) {
					arr[i] = 1;
				}
				else {
					arr[i] = 0;
				}

			}

		}

		Matrix4(float ALL) {

			for (int i = 0; i < 16; i++) {		// This constructor takes a Matrix declaration with just 1 float
												// and assumes the user wants to build the Matrix4 with all stored
				arr[i] = ALL;					// floats being the same. Mostly just useful for   Matrix4.arr = 0;

			}

		}

		Matrix4(initializer_list<float> m) {

			int i = 0;							// This constructor allows the user to specifically declare the value
			for (float m : m) {					// of each stored float on construction without having to be written as
				arr[i] = m;						// m1,m2,m3,m4,etc. Still learning how initializer_lists work,
				i++;
			}

		}

		Matrix4(const Matrix4& Copy) {

			for (int i = 0; i < 16; i++) {

				arr[i] = Copy.arr[i];

			}

		}


		Matrix4 operator=(const Matrix4& op) {

			for (int i = 0; i < 16; i++) {

				arr[i] = op.arr[i];

			}

			return *this;

		}

		Vector4 operator*(const Vector4& op) {

			Vector4 temp;

			temp.x = grid[0][0] * op.x + grid[0][1] * op.y + grid[0][2] * op.z + grid[0][3] * op.w;			// Still wrapping my head around this, so the vector's X must be multiplied
			temp.y = grid[1][0] * op.x + grid[1][1] * op.y + grid[1][2] * op.z + grid[1][3] * op.w;			// by one of Matr's full vectors, M0x * Vx + M0y * Vx + M0z * Vx ? I'm not
			temp.z = grid[2][0] * op.x + grid[2][1] * op.y + grid[2][2] * op.z + grid[2][3] * op.w;			// sure what this is for and need to look into it more.
			temp.w = grid[3][0] * op.x + grid[3][1] * op.y + grid[3][2] * op.z + grid[3][3] * op.w;

			return temp;

		}

		Matrix4 operator*(const Matrix4& op) {

			Matrix4 temp = 0;

			for (int A = 0; A < 4; A++) {
				for (int B = 0; B < 4; B++) {
					for (int C = 0; C < 4; C++) {
						temp.grid[A][B] += grid[A][C] * op.grid[C][B];
					}
				}
			}

			return temp;

		}

		Matrix4 operator*=(const Matrix4& op) {

			*this = *this * op;

			return *this;

		}

		bool operator==(const Matrix4& op) {

			for (int i = 0; i < 16; i++) {
				if (arr[i] != op.arr[i]) {
					return false;
				}
			}

			return true;

		}

		bool operator!=(const Matrix4& op) {

			for (int i = 0; i < 16; i++) {
				if (arr[i] != op.arr[i]) {
					return true;
				}
			}

			return false;

		}

		float operator[](int i) {

			return arr[i];

		}


		//Matrix4 MakeRotateX(float op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeRotateY(float op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeRotateZ(float op) {
		//
		//	return;
		//
		//}
		//
		//
		//Matrix4 MakeScale(const Vector4& op) {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetRight() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetUp() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetForward() {
		//
		//	return;
		//
		//}
		//
		//Vector4 GetPosition() {
		//
		//	return;
		//
		//}
		//
		//
		//bool IsApproximatelyEqual(const Matrix4& op, float E) {
		//
		//	return;
		//
		//}
		//
		//void SetTranslate(const Vector4& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix4 MakeTranslate(const Vector4& op) {
		//
		//	return;
		//
		//}

	};

	struct Color {

	//	unsigned int rgba;

	//	Color() {

	//		rgba 0;

	//	}

	//	Color(float RR, float GG, float BB, float AA) {

	//		r = RR;
	//		g = GG;
	//		b = BB;
	//		a = AA;

	//	}
	//	
	//	Color(const Color& Copy) {

	//		r = Copy.r;
	//		g = Copy.g;
	//		b = Copy.b;
	//		a = Copy.a;

	//	}




	//	unsigned char getRed();
	//	void setRed(unsigned char redValue);
	//	unsigned char getGreen();
	//	void setGreen (unsigned char greenValue);
	//	unsigned char getBlue();
	//	void setBlue(unsigned char blueValue);
	//	unsigned char getAlpha();
	//	void setAlpha(unsigned char alphaValue);

	};

}


string ReadArray(float Array[], size_t Size) {

	int Root = sqrt(Size);

	string Build = to_string(Array[0]);
	Build.erase(Build.find_last_not_of("0") + 1, string::npos);				 // Read about this on Stack Overflow, it gets the position of the last digit that
	Build.erase(Build.find_last_not_of(".") + 1, string::npos);				 // isn't a 0, then removes everything from the next digit onwards. It does it again
																			 // for the period in case the result would be a whole number, to avoid ints looking
	for (int i = 1; i < Size; i++) {										 // like 1. instead of just 1which is more comfortable to read.
		Build += " " + to_string(Array[i]);
		Build.erase(Build.find_last_not_of("0") + 1, string::npos);
		Build.erase(Build.find_last_not_of(".") + 1, string::npos);

		if (i % Root == 3 && i != Size - 1) {
			Build += " |";
		}

	}

	return Build;
}


int main()
{
	

	float test = 1234.23456789;
	cout << fixed << setprecision(4) << test << endl << endl;

	// Vector3 tests
	{

		MathLibrary::Vector3 Pos1 {1,2,3};
		MathLibrary::Vector3 Pos2 {4,5,6};
		MathLibrary::Vector3 Pos3 {};

		cout << "VECTOR3 TESTS\n" << endl;

		Pos3 = Pos1 + Pos2;
		cout << "1 2 3  +  4 5 6  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 - Pos2;
		cout << "1 2 3  -  4 5 6  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 * Pos2;
		cout << "1 2 3  *  4 5 6  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 * 5;
		cout << "1 2 3  *  5f" << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 / 5;
		cout << "1 2 3  /  5f" << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 += Pos1;
		cout << "1 1 1  +=  1 2 3  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 -= Pos1;
		cout << "1 1 1  -=  1 2 3  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 *= Pos1;
		cout << "1 1 1  *=  1 2 3  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 *= 5;
		cout << "1 1 1  *=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 /= 5;
		cout << "1 1 1  /=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		-Pos3;
		cout << " -Pos3  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  ==  Pos1  =  " << (Pos3 == Pos1) << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  !=  Pos1  =  " << (Pos3 != Pos1) << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  <  Pos1  =  " << (Pos3 < Pos1) << endl;

		cout << "Pos1[n]  =" << "  Pos1[0]=" << Pos1[0] << "  Pos1[1]=" << Pos1[1] << "  Pos1[2]=" << Pos1[2] << endl;


		cout << "\n";
		

		cout << "1 2 3  DOT  4 5 6  =  " << Pos1.Dot(Pos2) << endl;
		
		Pos3 = Pos1.Cross(Pos2);
		cout << "1 2 3  CROSS  4 5 6  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		cout << "1 2 3  MAGNITUDE  =  " << Pos1.Magnitude() << endl;

		Pos3 = {1,1,1};
		cout << "1 1 1  NORMALISE  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1.Normalised();
		cout << "1 2 3  NORMALISED  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;
		
		Pos3 = {1.00001,2.00002,3.00003};
		cout << "1 2 3  APPROX(0.0001)  1.00001 2.00002 3.00003  =  " << Pos1.IsApproximatelyEqual(Pos3, 0.0001) << endl;

		cout << "1 2 3  ANGLEBETWEEN  4 5 6  =  " << Pos1.AngleBetween(Pos2) << endl;

		cout << "1 2 3  DISTANCE  4 5 6  =  " << Pos1.Distance(Pos2) << endl;

		cout << "1 2 3  ANGLE2D  =  " << Pos1.Angle2D() << endl;

		cout << "\n\n\n";

	}

	// Vector4 tests
	{

		MathLibrary::Vector4 Pos1 {1,2,3,1};
		MathLibrary::Vector4 Pos2 {4,5,6,0};
		MathLibrary::Vector4 Pos3 {};

		cout << "VECTOR4 TESTS\n" << endl;

		Pos3 = Pos1 + Pos2;
		cout << "1 2 3 1  +  4 5 6 0  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;
		
		Pos3 = Pos1 - Pos2;													 
		cout << "1 2 3 1  -  4 5 6 0  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = Pos1 * Pos2;													 
		cout << "1 2 3 1  *  4 5 6 0  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = Pos1 * 5;													 
		cout << "1 2 3 1  *  5f  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = Pos1 / 5;													 
		cout << "1 2 3 1  /  5f  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		Pos3 += Pos1;
		cout << "1 1 1 1  +=  1 2 3 1  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		Pos3 -= Pos1;
		cout << "1 1 1 1  -=  1 2 3 1  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		Pos3 *= Pos1;
		cout << "1 1 1 1  *=  1 2 3 1  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		Pos3 *= 5;
		cout << "1 1 1 1  *=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		Pos3 /= 5;
		cout << "1 1 1 1  /=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1,1,1,1};
		-Pos3;
		cout << " -Rot3  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = { 1,1,1,1 };
		cout << "Rot3  ==  Rot1  =  " << (Pos3 == Pos1) << endl;

		cout << "Rot3  !=  Rot1  =  " << (Pos3 != Pos1) << endl;

		cout << "Rot3  <  Rot1  =  " << (Pos3 < Pos1) << endl;

		cout << "Rot1[n]  =" << "  Rot1[0]=" << Pos1[0] << "  Rot1[1]=" << Pos1[1] << "  Rot1[2]=" << Pos1[2] << "  Rot1[3]=" << Pos1[3] << endl;

		cout << "\n";

		cout << "1 2 3  DOT  4 5 6  =  " << Pos1.Dot(Pos2) << endl;

		Pos3 = Pos1.Cross(Pos2);
		cout << "1 2 3 1  CROSS  4 5 6 0  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		cout << "1 2 3 1  MAGNITUDE  =  " << Pos1.Magnitude() << endl;

		Pos3 = {1,1,1,1};
		cout << "1 1 1 1  NORMALISE  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = Pos1.Normalised();
		cout << "1 2 3 1  NORMALISED  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << " " << Pos3.w << endl;

		Pos3 = {1.00001,2.00002,3.00003,1};
		cout << "1 2 3 1  APPROX(0.0001)  1.00001 2.00002 3.00003 0  =  " << Pos1.IsApproximatelyEqual(Pos3, 0.0001) << endl;

		cout << "1 2 3 1  ANGLEBETWEEN  4 5 6 0  =  " << Pos1.AngleBetween(Pos2) << endl;

		cout << "1 2 3 1  DISTANCE  4 5 6 0  =  " << Pos1.Distance(Pos2) << endl;

		cout << "\n\n\n";

	}

	// Matrix3 tests
	{
		
		MathLibrary::Matrix3 Matr1 = {1,2,0,3,4,0,5,6,1};
		MathLibrary::Matrix3 Matr2 = {6,5,0,4,3,0,2,1,1};
		MathLibrary::Matrix3 Matr3;

		MathLibrary::Vector3 Pos1 = {1,2,3};
		MathLibrary::Vector3 Pos2;
		
		cout << "MATRIX3 TESTS\n" << endl;

		Pos2 = Matr1 * Pos1;
		cout << ReadArray(Matr1.arr, 9) << "  *  1 2 3  =  " << Pos2.x << " " << Pos2.y << " " << Pos2.z << endl;

		Matr3 = Matr1 * Matr2;
		cout << ReadArray(Matr1.arr, 9) << "  *  " << ReadArray(Matr2.arr, 9) << "  =  " << ReadArray(Matr3.arr, 9) << endl;
	
		Matr1 *= Matr2;
		cout << "1 2 0 | 3 4 0 | 5 6 1  *=  " << ReadArray(Matr2.arr, 9) << "  =  " << ReadArray(Matr1.arr, 9) << endl;

		cout << "Matr1  ==  Matr2  =  " << (Matr1 == Matr2) << endl;

		cout << "Matr1  !=  Matr2  =  " << (Matr1 != Matr2) << endl;

		cout << "Matr1[n]  = ";
		for (int i = 0; i < 9; i++) {
			cout << " [" << i << "]=" << Matr1[i];
		}

		cout << "\n";

		//

		cout << "\n\n\n\n";

	}

	// Matrix4 tests
	{

		MathLibrary::Matrix4 Matr1 = {1,2,3,0,4,5,6,0,7,8,9,0,10,11,12,1};
		MathLibrary::Matrix4 Matr2 = {12,11,10,0,9,8,7,0,6,5,4,0,3,2,1,1};
		MathLibrary::Matrix4 Matr3;

		MathLibrary::Vector4 Pos1 = {1,2,3,0};
		MathLibrary::Vector4 Pos2;

		cout << "MATRIX4 TESTS\n" << endl;

		Pos2 = Matr1 * Pos1;
		cout << ReadArray(Matr1.arr, 16) << "  *  " << "1 2 3 0  =  " << Pos2.x << " " << Pos2.y << " " << Pos2.z <<  " " << Pos2.w << endl;

		Matr3 = Matr2 * Matr1;
		cout << ReadArray(Matr2.arr, 16) << "  *  " << ReadArray(Matr1.arr, 16) << "  =  " << ReadArray(Matr3.arr, 16) << endl;

		Matr2 *= Matr1;
		cout << "12 11 10 0 | 9 8 7 0 | 6 5 4 0 | 3 2 1 1  *=  " << ReadArray(Matr1.arr, 16) << "  =  " << ReadArray(Matr2.arr, 16) << endl;

		cout << "Matr1  ==  Matr2  =  " << (Matr1 == Matr2) << endl;

		cout << "Matr1  !=  Matr2  =  " << (Matr1 != Matr2) << endl;

		cout << "Matr1[n]  = ";
		for (int i = 0; i < 16; i++) {
			cout << " [" << i << "]=" << Matr1[i];
		}

		cout << "\n";

		//

		cout << "\n\n\n\n";

	}

}

