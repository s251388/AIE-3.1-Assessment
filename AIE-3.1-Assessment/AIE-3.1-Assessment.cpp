
#include <iostream>
#include <vector>

using namespace std;

namespace MathLibrary {
    
    struct Vector3 {
        float x;
        float y;
        float z;

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
        float x;
        float y;
        float z;
        float w;
    };

    struct Matrix3 {

    };

}


int main()
{
    
    MathLibrary::Vector3 Vec1{1,2,3};
    MathLibrary::Vector3 Vec2{4,5,6};
    MathLibrary::Vector3 Vec3{};

    Vec3 = Vec1 + Vec2;
    cout << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  +  " << Vec2.x << "," << Vec2.y << "," << Vec2.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = Vec1 - Vec2;
    cout << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  -  " << Vec2.x << "," << Vec2.y << "," << Vec2.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = Vec1 * Vec2;
    cout << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  *  " << Vec2.x << "," << Vec2.y << "," << Vec2.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = Vec1 * 5;
    cout << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  *  " << "5f" << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = Vec1 / 5;
    cout << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  /  " << "5f" << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;


    cout << "Vec3 from here on will always be set to 1,1,1 before operations." << endl;

    Vec3 = {1,1,1};
    Vec3 += Vec1;
    cout << " +=  " << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    Vec3 -= Vec1;
    cout << " -=  " << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    Vec3 *= Vec1;
    cout << " *=  " << Vec1.x << "," << Vec1.y << "," << Vec1.z << "  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    Vec3 *= 5;
    cout << " *=  5  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    Vec3 /= 5;
    cout << " /=  5  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    -Vec3;
    cout << " -Vec  =  " << Vec3.x << "," << Vec3.y << "," << Vec3.z << endl;

    Vec3 = {1,1,1};
    cout << "Vec3  ==  Vec1  =  " << (Vec3 == Vec1) << endl;

    Vec3 = {1,1,1};
    cout << "Vec3  !=  Vec1  =  " << (Vec3 != Vec1) << endl;

    Vec3 = {1,1,1};
    cout << "Vec3  <  Vec1  =  " << (Vec3 < Vec1) << endl;

    cout << "Vec1[n]  =" << "  Vec1[0]=" << Vec1[0] << "  Vec1[1]=" << Vec1[1] << "  Vec1[2]=" << Vec1[2] << endl;

}

