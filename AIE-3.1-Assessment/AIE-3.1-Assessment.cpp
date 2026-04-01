
#include <iostream>
#include <string>

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
			temp.w = w - op.w;

			return temp;
		}

		Vector4 operator*(const Vector4& op) {

			Vector4 temp;
			temp.x = x * op.x;
			temp.y = y * op.y;
			temp.z = z * op.z;
			temp.w = w * op.w;

			return temp;
		}

		Vector4 operator*(const float& op) {

			Vector4 temp;
			temp.x = x * op;
			temp.y = y * op;
			temp.z = z * op;
			temp.w = w * op;

			return temp;
		}

		Vector4 operator/(const float& op) {

			Vector4 temp;
			temp.x = x / op;
			temp.y = y / op;
			temp.z = z / op;
			temp.w = w / op;

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
			w -= op.w;

			return *this;
		}

		Vector4 operator*=(const Vector4& op) {

			x *= op.x;
			y *= op.y;
			z *= op.z;
			w *= op.w;

			return *this;
		}

		Vector4 operator*=(const float& op) {

			x *= op;
			y *= op;
			z *= op;
			w *= op;

			return *this;
		}

		Vector4 operator/=(const float& op) {

			x /= op;
			y /= op;
			z /= op;
			w /= op;

			return *this;
		}

		Vector4 operator-() {

			x *= -1;
			y *= -1;
			z *= -1;
			w *= -1;

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
			float mag1 = (temp1.x + temp1.y + temp1.z + temp1.w);        // Gets the XYZ values squared and added. The two magnitudes don't need to be
			// square-rooted back down because they are BOTH squared, their relationship
			Vector4 temp2 = op;                                // to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= op;
			float mag2 = (temp2.x + temp2.y + temp2.z + temp2.w);

			return (mag1 < mag2);
		}

		float operator[](int i) {          // Originally i used switch cases but this felt more efficient, i make a temporary vector of the
			// current Vector3's XYZ values, then just use the input int to return the float at that index.
			
			float XYZW[4] {x,y,z,w};

			return XYZW[i];

		}

	};

	struct Matrix3 {

		union {
			struct {
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;
			};
			float arr[9];
			float grid[3][3];
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

		Vector3 operator*(Vector3 op) {

			op.x = grid[0][0] * op.x + grid[0][1] * op.x + grid[0][2] * op.z;			// Still wrapping my head around this, so the vector's X must be multiplied
			op.y = grid[1][0] * op.x + grid[1][1] * op.x + grid[1][2] * op.z;			// by one of Matr's full vectors, M0x * Vx + M0y * Vx + M0z * Vx ? I'm not
			op.z = grid[2][0] * op.x + grid[2][1] * op.x + grid[2][2] * op.z;			// sure what this is for and need to look into it more.

		return op;
		
		}
		
		//Matrix3 operator*(const Matrix3& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix3 operator*=(const Matrix3& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix3 operator==(const Matrix3& op) {
		//
		//	return;
		//
		//}
		//
		//Matrix3 operator!=(const Matrix3& op) {
		//
		//	return;
		//
		//}
		//
		//float operator[](int i) {
		//
		//	return this->arr[i];
		//
		//}

	};

}


string ReadArray(float Array[], size_t Size) {

	int Root = sqrt(Size);

	string Build = to_string(Array[0]);
	Build.erase(Build.find_last_not_of("0") + 1, string::npos);				 // Read about this on Stack Overflow, first param is a function for getting the
	Build.erase(Build.find_last_not_of(".") + 1, string::npos);
	
	for (int i = 1; i < Size; i++) {
		Build += " " + to_string(Array[i]);
		Build.erase(Build.find_last_not_of("0") + 1, string::npos);
		Build.erase(Build.find_last_not_of(".") + 1, string::npos);

		if (i % Root == 2 && i != Size - 1) {
			Build += " |";
		}

	}

	return Build;
}


int main()
{

	// Vector3 tests
	{

		MathLibrary::Vector3 Pos1 {1,2,3};
		MathLibrary::Vector3 Pos2 {4,5,6};
		MathLibrary::Vector3 Pos3 {};

		Pos3 = Pos1 + Pos2;
		cout << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  +  " << Pos2.x << " " << Pos2.y << " " << Pos2.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 - Pos2;
		cout << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  -  " << Pos2.x << " " << Pos2.y << " " << Pos2.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 * Pos2;
		cout << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  *  " << Pos2.x << " " << Pos2.y << " " << Pos2.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 * 5;
		cout << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  *  " << "5f" << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = Pos1 / 5;
		cout << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  /  " << "5f" << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;


		cout << "\nPos3 from here on will always be set to 1,1,1 before operations.\n" << endl;

		Pos3 = {1,1,1};
		Pos3 += Pos1;
		cout << " +=  " << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 -= Pos1;
		cout << " -=  " << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 *= Pos1;
		cout << " *=  " << Pos1.x << " " << Pos1.y << " " << Pos1.z << "  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 *= 5;
		cout << " *=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		Pos3 /= 5;
		cout << " /=  5  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		-Pos3;
		cout << " -Pos  =  " << Pos3.x << " " << Pos3.y << " " << Pos3.z << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  ==  Pos1  =  " << (Pos3 == Pos1) << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  !=  Pos1  =  " << (Pos3 != Pos1) << endl;

		Pos3 = {1,1,1};
		cout << "Pos3  <  Pos1  =  " << (Pos3 < Pos1) << endl;

		cout << "Pos1[n]  =" << "  Pos1[0]=" << Pos1[0] << "  Pos1[1]=" << Pos1[1] << "  Pos1[2]=" << Pos1[2] << endl;

		cout << "\n\n\n";

	}

	// Vector4 tests
	{

		MathLibrary::Vector4 Rot1 {1,2,3,4};
		MathLibrary::Vector4 Rot2 {5,6,7,8};
		MathLibrary::Vector4 Rot3 {};

		Rot3 = Rot1 + Rot2;
		cout << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  +  " << Rot2.x << " " << Rot2.y << " " << Rot2.z << " " << Rot2.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;
		
		Rot3 = Rot1 - Rot2;													 
		cout << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  -  " << Rot2.x << " " << Rot2.y << " " << Rot2.z << " " << Rot2.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = Rot1 * Rot2;													 
		cout << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  *  " << Rot2.x << " " << Rot2.y << " " << Rot2.z << " " << Rot2.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = Rot1 * 5;													 
		cout << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  *  " << "5f" << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = Rot1 / 5;													 
		cout << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  /  " << "5f" << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;


		cout << "\nRot3 from here on will always be set to 1,1,1,1 before operations.\n" << endl;

		Rot3 = {1,1,1,1};
		Rot3 += Rot1;
		cout << " +=  " << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		Rot3 -= Rot1;
		cout << " -=  " << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		Rot3 *= Rot1;
		cout << " *=  " << Rot1.x << " " << Rot1.y << " " << Rot1.z << " " << Rot1.w << "  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		Rot3 *= 5;
		cout << " *=  5  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		Rot3 /= 5;
		cout << " /=  5  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		-Rot3;
		cout << " -Rot  =  " << Rot3.x << " " << Rot3.y << " " << Rot3.z << " " << Rot3.w << endl;

		Rot3 = {1,1,1,1};
		cout << "Rot3  ==  Rot1  =  " << (Rot3 == Rot1) << endl;

		Rot3 = {1,1,1,1};
		cout << "Rot3  !=  Rot1  =  " << (Rot3 != Rot1) << endl;

		Rot3 = {1,1,1,1};
		cout << "Rot3  <  Rot1  =  " << (Rot3 < Rot1) << endl;

		cout << "Rot1[n]  =" << "  Rot1[0]=" << Rot1[0] << "  Rot1[1]=" << Rot1[1] << "  Rot1[2]=" << Rot1[2] << "  Rot1[3]=" << Rot1[3] << endl;

		cout << "\n\n\n";

	}

	// Matrix3 tests
	{
		
		MathLibrary::Matrix3 Matr1 = {1,2,3,4,5,6,7,8,9};
		MathLibrary::Matrix3 Matr2 = {9,8,7,6,5,4,3,2,1};
		MathLibrary::Matrix3 Matr3;

		MathLibrary::Vector3 Pos1 = {1,2,3};
		MathLibrary::Vector3 Pos2;
		Pos2 = Matr1 * Pos1;

		// CONTINUE HERE
		cout << ReadArray(Matr1.arr, 9) << "  ?  " << ReadArray(Matr2.arr, 9) << "  =  " << ReadArray(Matr3.arr, 9) << endl;

		



	}

}

