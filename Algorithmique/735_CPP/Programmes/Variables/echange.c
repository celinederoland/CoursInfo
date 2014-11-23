#include <iostream>
void swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

int main(int argc, char** argv)
{
	int a = 5;
	int b = 10;
	swap(&a,&b);
	std::cout << "a = " << a << " ; b = " << b << std::endl;
	return 0;
}


