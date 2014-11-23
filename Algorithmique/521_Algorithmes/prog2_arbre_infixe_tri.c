#include <stdio.h>
#include <stdlib.h>
typedef struct Arbre Arbre;
struct Arbre
{
     int valeur;
     int numero;
     Arbre *gauche;
     Arbre *droit;
     Arbre *parent;
};

Arbre *initialisation(int val);
void ajout_gauche(Arbre *arbre, int val);
void ajout_droit(Arbre *arbre, int val);
void afficher_noeud(Arbre *arbre);
void afficher_prefixe(Arbre *arbre);
void afficher_infixe(Arbre *arbre);
Arbre *creer_trie(int t[],int taille);
void placer(Arbre *a, int val);

int numero_noeud;

int main()
{
     int t[] = {12,9,15,18,19,3,4,2,21,9,8,4,42};
     Arbre *a = creer_trie(t,13);
     afficher_prefixe(a);
     printf("\n");
     afficher_infixe(a);
     printf("Hello world!\n");
     return 0;
}

Arbre *initialisation(int val)
{
     Arbre *monArbre = malloc(sizeof(*monArbre));

     monArbre->parent = NULL;
     monArbre->valeur = val;
     monArbre->gauche = NULL;
     monArbre->droit = NULL;
     monArbre->numero = 0;

     return monArbre;
}

void afficher_noeud(Arbre *arbre)
{
     printf("Noeud %d : %d ",arbre -> numero,arbre -> valeur);
     if (arbre -> gauche != NULL ) {
          printf("fils gauche : Noeud %d : %d ", arbre -> gauche -> numero, arbre -> gauche -> valeur);
     }
     if (arbre -> droit != NULL ) {
          printf("fils droit : Noeud %d : %d ", arbre -> droit -> numero, arbre -> droit -> valeur);
     }
     printf("\n");
}
void afficher_prefixe(Arbre *arbre)
{
     afficher_noeud(arbre);
     if (arbre -> gauche != NULL) {
          afficher_prefixe(arbre -> gauche);
     }
     if (arbre -> droit != NULL) {
          afficher_prefixe(arbre -> droit);
     }
}

void afficher_infixe(Arbre *arbre)
{
     if (arbre -> gauche != NULL) {
          afficher_infixe(arbre -> gauche);
     }
     afficher_noeud(arbre);
     if (arbre -> droit != NULL) {
          afficher_infixe(arbre -> droit);
     }
}

void ajout_gauche(Arbre *arbre, int val)
{
     Arbre *gch = malloc(sizeof(*gch));

     numero_noeud++;

     gch->parent = arbre;
     gch->valeur = val;
     gch->numero = numero_noeud;
     gch->gauche = NULL;
     gch->droit = NULL;
     arbre->gauche = gch;
}

void ajout_droit(Arbre *arbre, int val)
{
     Arbre *drt = malloc(sizeof(*drt));

     numero_noeud++;

     drt->parent = arbre;
     drt->valeur = val;
     drt->numero = numero_noeud;
     drt->gauche = NULL;
     drt->droit = NULL;
     arbre->droit = drt;
}

Arbre *creer_trie(int t[],int taille)
{
     Arbre *a = initialisation(t[0]);
     int i;
     for (i = 1; i<taille; i++)
     {
          placer(a,t[i]);
     }
     return a;
}

void placer(Arbre *a, int val)
{
     if (val <= a->valeur) {
          if (a->gauche == NULL) {
               ajout_gauche(a,val);
          }
          else {
               (placer(a->gauche,val));
          }
     }
     else {
          if (a->droit == NULL) {
               ajout_droit(a,val);
          }
          else {
               (placer(a->droit,val));
          }
     }
}
