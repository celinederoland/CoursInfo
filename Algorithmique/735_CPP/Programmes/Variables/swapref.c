#include <iostream>

void swap(int &i, int &j)
{
	int tmp = i;
	i = j;
	j = tmp;
}

int main(int argc, char** argv)
{
	int a = 5;
	int b = 10;
	swap(a, b);
	std::cout << "a = " << a << " ; b = " << b << std::endl;
	return 0;
}

