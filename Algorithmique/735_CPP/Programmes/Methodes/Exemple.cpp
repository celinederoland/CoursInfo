/* 
 * File:   Exemple.cpp
 * Author: celine
 * 
 * Created on 21 novembre 2014, 12:37
 */

#include "Exemple.h"
#include <iostream>
using namespace std;

/*Exemple::Exemple(){ 
    //appelle le constructeur par défaut de integer
 *  _i = 0; //affecte la valeur 0 à _i
}*/

Exemple::Exemple() : _i(0) { 
    //_i(0) appelle le constructeur de integer avec le paramètre 0)
    cout << "constructeur par défaut" << endl;
}    

Exemple::Exemple(int p) : _i(p) {
    cout << "constructeur à un paramètre" << endl;
}

Exemple::Exemple(const Exemple& orig) : _i(orig._i) {
    cout << "constructeur par copie" << endl;
}

Exemple& Exemple::operator=(const Exemple& autre) {
    if (this != &autre) {
        _i = autre._i;
    }
    return *this;
    cout << "affectation" << endl;
}

void Exemple::affiche() const {
    cout << "Exemple : " << _i << endl;
}

void Exemple::set(int p) {
    _i = p;
    cout << "setter" << endl;
}

Exemple::~Exemple() {
    cout << "destructeur" << endl;
}

