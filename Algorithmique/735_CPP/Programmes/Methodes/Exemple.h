/* 
 * File:   Exemple.h
 * Author: celine
 *
 * Created on 21 novembre 2014, 12:37
 */

#ifndef EXEMPLE_H
#define	EXEMPLE_H

class Exemple {
private:
    int _i;
    
public:
    Exemple();
    Exemple(int p);
    Exemple(const Exemple& orig);
    Exemple& operator=(const Exemple& autre);
    void affiche() const; //const garantit que l'objet ne sera pas modifié
    void set(int p);
    virtual ~Exemple();

};

#endif	/* EXEMPLE_H */

