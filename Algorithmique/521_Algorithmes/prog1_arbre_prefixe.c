#include <stdio.h>
#include <stdlib.h>
typedef struct Arbre Arbre;
struct Arbre
{
     int valeur;
     Arbre *gauche;
     Arbre *droit;
};

Arbre *initialisation(int val);
void ajout(Arbre *arbre, Arbre *gche, Arbre *drt);
void afficher_prefixe(Arbre *arbre);

int main()
{
     Arbre *a1 = initialisation(1);
     Arbre *a2 = initialisation(2);
     Arbre *a3 = initialisation(3);
     Arbre *a4 = initialisation(4);
     Arbre *a5 = initialisation(5);
     Arbre *a6 = initialisation(6);
     Arbre *a7 = initialisation(7);
     Arbre *a8 = initialisation(8);
     Arbre *a9 = initialisation(9);
     Arbre *a10 = initialisation(10);
     Arbre *a11 = initialisation(11);
     Arbre *a12 = initialisation(12);
     Arbre *a13 = initialisation(13);
     Arbre *a14 = initialisation(14);
     afficher_prefixe(a1);
     printf("\n");
     ajout(a1,a2,a9);
     ajout(a2,a3,a6);
     ajout(a9,a10,a12);
     ajout(a3,a4,a5);
     ajout(a6,a7,a8);
     ajout(a10,NULL,a11);
     ajout(a12,a13,a14);
     afficher_prefixe(a1);
     printf("Hello world!\n");
     return 0;
}

Arbre *initialisation(int val)
{
     Arbre *monArbre = malloc(sizeof(*monArbre));

     monArbre->valeur = val;
     monArbre->gauche = NULL;
     monArbre->droit = NULL;

     return monArbre;
}

void afficher_prefixe(Arbre *arbre)
{
     printf("%d\n",arbre -> valeur);
     if (arbre -> gauche != NULL) {
          afficher_prefixe(arbre -> gauche);
     }
     if (arbre -> droit != NULL) {
          afficher_prefixe(arbre -> droit);
     }
}

void ajout(Arbre *arbre, Arbre *gche, Arbre *drt)
{
     arbre -> gauche = gche;
     arbre -> droit = drt;
}
