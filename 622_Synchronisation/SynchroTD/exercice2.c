#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



void threadA(int* px)
{
	int i;
	for (i = 0; i < 10; i++)
	{
			(*px)++;
			printf("Je suis le A et x vaut : %d \n",*px);
			sleep(1);
	}
}

void threadB(int* px)
{
	int i;
	for (i = 0; i < 10; i++)
	{
			(*px)--;
			printf("Je suis le B et x vaut : %d \n",*px);
			sleep(1);
	}
}

int* decompte(int* px)
{
	int* y = (int*) malloc(sizeof(int));
	*y = 0;
	while ( *px > 0 )
	{
		++(*y);
		--(*px); //section critique
	}
	return y;/* retourner la valeur de y */
}

int main(int argc, char** argv)
{
	//int x = atoi(argv[1]);
	int x = 0;	
	//int* case_retour_a;
	//int* case_retour_b;
	pthread_t ta,tb;
	pthread_create(&ta, NULL,(void*(*)(void*)) threadA,(void*) &x);
	pthread_create(&tb, NULL,(void*(*)(void*)) threadB,(void*) &x);
	pthread_join(ta,NULL);
	pthread_join(tb,NULL);
	//pthread_join(ta,(void**)&case_retour_a);
	//pthread_join(tb,(void**)&case_retour_b);
	//printf("Le thread a renvoie %d \n",*case_retour_a);
	//printf("Le thread b renvoie %d \n",*case_retour_b);
	//printf("La somme des deux est %d \n",(*case_retour_a) + (*case_retour_b));
	//free(case_retour_a);
	//free(case_retour_b);
	return 0;
}
