/* 
 * File:   main.cpp
 * Author: celine
 *
 * Created on 21 novembre 2014, 12:36
 */

#include <cstdlib>
#include "Exemple.h"
using namespace std;

/*
 * 
 */

void f(Exemple e) {
    e.affiche();
}

int main(int argc, char** argv) {

    Exemple e1;
    //instance de A créée avec constructeur par défaut
    e1 = Exemple(1);
    //Création d'une instance avec constructeur à 1 paramètre
    //Opérateur d'affectation 
    //instance détruite
    Exemple e2(e1);
    //Création de l'instance e2 par copie
    Exemple e3 = 3;
        //Même chose que Exemple e3(3)
    e3 = 6;
    Exemple e4 = Exemple(4);
        //Même chose que Exemple e4(5)
    f(e4);
        //Création du paramètre p par copie
        //Affiche sur p
        //Destruction du paramètre p
    Exemple tbl[4];
        //4 instances créées par défaut
    Exemple& e5 = tbl[2];
        //rien
    
    return 0;
} //8 destructeurs

