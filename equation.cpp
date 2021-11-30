#include "equation.h"

equation::equation(float x, float y, float z, float sum){
	this->x = x;
	this->y = y;
	this->z = z;
	this->sum = sum;
	// sum != 0 if x,y,z == 0
}

equation::equation()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->sum = 0;
}

equation equation::operator-(const equation& other)
{
	equation temporary;
	temporary.x = this->x - other.x;
	temporary.y = this->y - other.y;
	temporary.z = this->z - other.z;
	temporary.sum = this->sum - other.sum;
	return temporary;
}

equation& equation::operator=(const equation& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->sum = other.sum;

	return *this;
}

bool equation::operator==(const equation& other)
{
	return this->x == other.x &&
		   this->y == other.y &&
		   this->z == other.z &&
		   this->sum == other.sum;
}

bool equation::operator!=(const equation& other)
{
	return this->x != other.x ||
		   this->y != other.y ||
		   this->z != other.z ||
		   this->sum != other.sum;
}


equation unite(const equation & one, const equation & second) //equation unite(const equation & one, const equation & second = equation(0,0,0,0))
{
	equation part1 = one;
	equation part2 = second;

	if (one.x == 0 && second.x == 0) {
		if (one.y != second.y) {
			part1.y *= second.y; part1.z *= second.y;  part1.sum *= second.y;

	        part2.y *= one.y; part2.z *= one.y;  part2.sum *= one.y;
		}
	}
    else if (one.x != second.x) {
		part1.x *= second.x;  part1.y *= second.x;
		part1.z *= second.x;  part1.sum *= second.x;

		part2.x *= one.x;  part2.y *= one.x;
		part2.z *= one.x;  part2.sum *= one.x;
	}

	return (part1 - part2);
}

equation calculation(const equation& one, equation& second, equation & third)
{
	second = unite(one, second);
	third = unite(one, third);
	third = unite(second, third);

	equation result;
	result.z = (third.sum / third.z);
	result.y = (second.sum - second.z * result.z) / second.y;
	result.x = (one.sum - one.y * result.y - one.z * result.z) / one.x;

	return result;
}
