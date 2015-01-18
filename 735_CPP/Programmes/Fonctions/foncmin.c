#include <iostream>

double min(double x, double y);
float min(float x, float y);

int main(int argc, char** argv)
{
	double z = min(3.5, 2.7);
	float f = min(2.5f, (float) 1);
	std::cout << "min_double : " << z << std::endl;
	std::cout << "min_float : " << f << std::endl;
	return 0;
}

double min(double x, double y)
{
	return x <= y ? x : y;
}

float min(float x, float y)
{
	return x <= y ? x : y;
}

