#include <iostream>

int main(int argc, char** argv)
{
	int t[5] = { 3, 5, -2, 4, 1};//t = &t[0], pointeur non déplaçable  
	for (int i = 0; i < 5; i++)
	{
		std::cout << t[i] << " à l'adresse " << t+i << std::endl;
	}
	return 0;
}

//Différence avec le pointeur : 
	// Pointeur : int *a : je réserve de l'espace pour le pointeur mais pas pour l'int.
	// Tableau : int t[5] : je réserve de l'espace pour 5 variables de type int

