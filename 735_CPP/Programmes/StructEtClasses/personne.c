#include <iostream>

struct SPersonne //Personne est un type
{
	char nom[100];
	char prenom[50];

	private:
		int numSecu;
};

class CPersonne
{
	int numSecu;
	public:
		char nom[100];
		char prenom[50];
};

int main(int argc, char** argv)
{
	CPersonne cp;
	SPersonne sp;
	std::cout << "Ce programme ne fait rien " << std::endl;
	return 0;
}

