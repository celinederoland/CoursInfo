#include <iostream>

int main(int argc, char** argv)
{
	int a = 5;
	int& b = a; //b et a désignent la même variable, la même adresse en mémoire
	const int& cst_a = a; //a accessible uniquement en lecture.
	b = 10;
	std::cout << "a = " << a << " ; b = " << b << std::endl;
	a--;
	std::cout << "a = " << a << " ; b = " << b << std::endl;
	return 0;
	
	//Appels interdits :
	/*
	 * int &t; (alias non initialisé)
	 * int &t = 5; (car 5 n'est pas une lvalue. Exemples de lvalue : a, t[i], *(t+i). Astuce : lvalue = on peut lui appliquer l'opérateur d'adresse)
	 * swap(a,10)
	*/
}

