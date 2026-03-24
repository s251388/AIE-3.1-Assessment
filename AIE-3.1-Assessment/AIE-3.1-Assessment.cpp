
#include <iostream>
#include <vector>

using namespace std;

namespace MathLibrary {
	
	struct Vector3 {

		float x, y, z;

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
			temp1 *= *this;
			float mag1 = (temp1.x + temp1.y + temp1.z);        // Gets the XYZ values squared and added. The two magnitudes don't need to be
															   // square-rooted back down because they are BOTH squared, their relationship
			Vector3 temp2 = op;                                // to eachother will be the same no matter what i multiply or divide them by.
			temp2 *= op;
			float mag2 = (temp2.x + temp2.y + temp2.z);

			return (mag1 < mag2);
		}

		float operator[](int i) {          // Originally i used switch cases but this felt more efficient, i make a temporary vector of the
										   // current Vector3's XYZ values, then just use the input int to return the float at that index.
			vector<float> XYZ {x,y,z};
			
			return XYZ[i];

		}

	};

	struct Vector4 {

		float x, y, z, w;

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
			vector<float> XYZW{x,y,z,w};

			return XYZW[i];

		}

	};

	struct Matrix3 {

	};

}


int main()
{
	
	MathLibrary::Vector3 Pos1{1,2,3};
	MathLibrary::Vector3 Pos2{4,5,6};
	MathLibrary::Vector3 Pos3{};

	Pos3 = Pos1 + Pos2;
	cout << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  +  " << Pos2.x << "," << Pos2.y << "," << Pos2.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = Pos1 - Pos2;
	cout << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  -  " << Pos2.x << "," << Pos2.y << "," << Pos2.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = Pos1 * Pos2;
	cout << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  *  " << Pos2.x << "," << Pos2.y << "," << Pos2.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = Pos1 * 5;
	cout << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  *  " << "5f" << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = Pos1 / 5;
	cout << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  /  " << "5f" << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;


	cout << "Pos3 from here on will always be set to 1,1,1 before operations." << endl;

	Pos3 = {1,1,1};
	Pos3 += Pos1;
	cout << " +=  " << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	Pos3 -= Pos1;
	cout << " -=  " << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	Pos3 *= Pos1;
	cout << " *=  " << Pos1.x << "," << Pos1.y << "," << Pos1.z << "  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	Pos3 *= 5;
	cout << " *=  5  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	Pos3 /= 5;
	cout << " /=  5  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	-Pos3;
	cout << " -Pos  =  " << Pos3.x << "," << Pos3.y << "," << Pos3.z << endl;

	Pos3 = {1,1,1};
	cout << "Pos3  ==  Pos1  =  " << (Pos3 == Pos1) << endl;

	Pos3 = {1,1,1};
	cout << "Pos3  !=  Pos1  =  " << (Pos3 != Pos1) << endl;

	Pos3 = {1,1,1};
	cout << "Pos3  <  Pos1  =  " << (Pos3 < Pos1) << endl;

	cout << "Pos1[n]  =" << "  Pos1[0]=" << Pos1[0] << "  Pos1[1]=" << Pos1[1] << "  Pos1[2]=" << Pos1[2] << endl;



	cout << "\n\n\n";

	MathLibrary::Vector4 Rot1{1,2,3,4};
	MathLibrary::Vector4 Rot2{5,6,7,8};
	MathLibrary::Vector4 Rot3{};

	Rot3 = Rot1 + Rot2;
	cout << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "," << "  +  " << Rot2.x << "," << Rot2.y << "," << Rot2.z << "," << Rot2.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = Rot1 - Rot2;
	cout << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "," << "  -  " << Rot2.x << "," << Rot2.y << "," << Rot2.z << "," << Rot2.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = Rot1 * Rot2;
	cout << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "," << "  *  " << Rot2.x << "," << Rot2.y << "," << Rot2.z << "," << Rot2.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = Rot1 * 5;
	cout << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "," << "  *  " << "5f" << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = Rot1 / 5;
	cout << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "," << "  /  " << "5f" << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;


	cout << "Rot3 from here on will always be set to 1,1,1,1 before operations." << endl;

	Rot3 = {1,1,1,1};
	Rot3 += Rot1;
	cout << " +=  " << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	Rot3 -= Rot1;
	cout << " -=  " << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	Rot3 *= Rot1;
	cout << " *=  " << Rot1.x << "," << Rot1.y << "," << Rot1.z << "," << Rot1.w << "  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	Rot3 *= 5;
	cout << " *=  5  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	Rot3 /= 5;
	cout << " /=  5  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	-Rot3;
	cout << " -Rot  =  " << Rot3.x << "," << Rot3.y << "," << Rot3.z << "," << Rot3.w << endl;

	Rot3 = {1,1,1,1};
	cout << "Rot3  ==  Rot1  =  " << (Rot3 == Rot1) << endl;

	Rot3 = {1,1,1,1};
	cout << "Rot3  !=  Rot1  =  " << (Rot3 != Rot1) << endl;

	Rot3 = {1,1,1,1};
	cout << "Rot3  <  Rot1  =  " << (Rot3 < Rot1) << endl;

	cout << "Rot1[n]  =" << "  Rot1[0]=" << Rot1[0] << "  Rot1[1]=" << Rot1[1] << "  Rot1[2]=" << Rot1[2] << "  Rot1[3]=" << Rot1[3] << endl;


}

