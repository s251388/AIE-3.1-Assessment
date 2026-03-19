
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
            temp.x = this->x + op.x;
            temp.y = this->y + op.y;
            temp.z = this->z + op.z;

            return temp;
        }

        Vector3 operator-(const Vector3& op) {

            Vector3 temp;
            temp.x = this->x - op.x;
            temp.y = this->y - op.y;
            temp.z = this->z - op.z;

            return temp;
        }

        Vector3 operator*(const Vector3& op) {

            Vector3 temp;
            temp.x = this->x * op.x;
            temp.y = this->y * op.y;
            temp.z = this->z * op.z;

            return temp;
        }

        Vector3 operator+(const float& op) {

            Vector3 temp;
            temp.x = this->x * op;
            temp.y = this->y * op;
            temp.z = this->z * op;

            return temp;
        }
        
        Vector3 operator+(const float& op) {

            Vector3 temp;
            temp.x = this->x / op;
            temp.y = this->y / op;
            temp.z = this->z / op;

            return temp;
        }

        Vector3 operator=(const Vector3& op) {  // still confused about this

            Vector3 temp;
            temp.x = op.x;
            temp.y = op.y;
            temp.z = op.z;

            return temp;
        }

        Vector3 operator+=(const Vector3& op) {

            Vector3 temp = *this;
            temp.x += op.x;
            temp.y += op.y;
            temp.z += op.z;

            return temp;
        }

        Vector3 operator-=(const Vector3& op) {

            Vector3 temp = *this;
            temp.x -= op.x;
            temp.y -= op.y;
            temp.z -= op.z;

            return temp;
        }

        Vector3 operator*=(const Vector3& op) {

            Vector3 temp = *this;
            temp.x *= op.x;
            temp.y *= op.y;
            temp.z *= op.z;

            return temp;
        }

        Vector3 operator*=(const float& op) {

            Vector3 temp = *this;
            temp.x *= op;
            temp.y *= op;
            temp.z *= op;

            return temp;
        }

        Vector3 operator/=(const float& op) {

            Vector3 temp = *this;
            temp.x /= op;
            temp.y /= op;
            temp.z /= op;

            return temp;
        }

        Vector3 operator-() {

            Vector3 temp = *this;
            temp.x *= -1;
            temp.y *= -1;
            temp.z *= -1;

            return temp;
        }

        bool operator==(const Vector3& op) {
            return (this->x == op.x && this->y == op.y && this->z == op.z);
        }

        bool operator!=(const Vector3& op) {
            return (this->x != op.x || this->y != op.y || this->z != op.z);
        }
        
        bool operator<(const Vector3& op) {

            Vector3 temp1 = *this;
            temp1 *= *this;
            float mag1 = sqrt(temp1.x + temp1.y + temp1.z);
            
            Vector3 temp2 = op;
            temp2 *= op;
            float mag2 = sqrt(temp2.x + temp2.y + temp2.z);

            return (mag1 < mag2);
        }

        float operator[](int i){

            switch (i) {
                case 0:
                    return this->x;
                case 1:
                    return this->y;
                case 2:
                    return this->z;
            }
            return 0;

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
    







}

