#include <iostream>
using namespace std;

#include "equation.h"

//enter only float or int. if you enter (1+1) like 2, the program will break

equation equation_cin(int number) {
 
    float x, y, z, sum;
    cout << "Enter x,y,z,sum of "<< number <<" equation: ";
    cin >> x >> y >> z >> sum;
    cout << endl;
    return equation(x, y, z, sum);
}

int main()
{
    equation one = equation_cin(1);

    equation second = equation_cin(2);

    equation third = equation_cin(3);

    equation result = calculation(one, second, third);

    cout << "     RESULT" << endl;
    cout << result.x << " " << result.y << " " << result.z << endl;

    system("pause");

    return 0;
}
