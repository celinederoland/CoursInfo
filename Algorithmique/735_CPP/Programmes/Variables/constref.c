#include <iostream>

//Motivations :
	//S'il n'est pas prévu de modifier x, autant ne pas le permettre
	//Pas de copie des données
double carre(const double& x)
{
	return x*x;
}

//Remarque : pour les types de base, bien gérés par le processeurs et peu couteux à recopier, on préviligiera le passage par valeur

int main(int argc, char** argv)
{
	double z = 3;
	std::cout << "carré de z " << carre(z) << std::endl;
	return 0;
}

