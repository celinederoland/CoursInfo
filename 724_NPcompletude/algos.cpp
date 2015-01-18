/****************************************************************************
/* Points les plus proches dans un ensemble de points du plan
/****************************************************************************/
double distance_min_naif(const std::vector<Point> & T) {
    double dmin = std::numeric_limits<double>::max();
    int n = T.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = T[i].distance(T[j]);
            if (i != j & d < dmin) {
                dmin = d;
            }
        }
    }
    return dmin;
}

double distance_min_dpr(const std::vector<Point> & T) {
    std::vector<Point> T2 = T;
    trier_sous_tableau(T2,0,T2.size() - 1,Point::cmp_x);
    return distance_min_rec( T2, 0, T2.size()-1 );
}

double distance_min_rec(std::vector<Point> & T, int debut, int fin) {
    
    int n = fin - debut + 1;

    // conditions d'arrêt
    if (n < 2) { return std::numeric_limits<double>::max(); }
    else if (n == 2) { return T[debut].distance(T[debut + 1]); }
    
    // récursivité
    int mid = (debut + fin) / 2;
    double dgauche = distance_min_rec(T,debut, mid );
    double ddroite = distance_min_rec(T,mid + 1, fin );
    double dmin = min(dgauche, ddroite);
    
    
    // vérification de la bande centrale
    double separation = ( T[mid].x + T[mid+1].x ) / 2.0;  
    //points contenus dans la bande
    trier_sous_tableau(T, debut, fin, Point::cmp_x);
    int cmin = debut;
    while (T[cmin].x < separation - dmin) { cmin ++; }
    int cmax = fin;
    while (T[cmax].x > separation + dmin ) { cmax --; }
    //comparaison de chaque point avec les 7 suivants
    trier_sous_tableau(T, cmin, cmax, Point::cmp_y);
    for (int i = cmin; i < cmax + 1; i++) {
        for (int j = i + 1; j < min(i + 7, cmax); j++) {
            double tmp = T[i].distance( T[j] );
            if (tmp < dmin) { dmin = tmp; }
        }
    }
    return dmin;
}

/****************************************************************************
/* Pb de découpes de barres
/****************************************************************************/

int decoupe_naif(int n, int prix[]) {
    int prix_opt = 0;
    for (int i = 1; i <= min(n, 11); i++) {
        int tmp = prix[i] + decoupe_naif(n - i, prix, nb_appels);
        if (tmp > prix_opt) { prix_opt = tmp; }
    }
    return prix_opt;
}

int decoupe_dyn(int n, int prix[]) {
    int solutions[n+1];
    solutions[0] = 0;
    for (int i = 1; i <= n; i++) {
        solutions[i] = 0;
        for (int j = 1; j <= min(i, 11); j++) {
            int tmp = prix[j] + solutions[i - j];
            if (tmp > solutions[i]) { solutions[i] = tmp; }
        }
    }
    return solutions[n];
}

/****************************************************************************
/* Distance de Levenstein
/****************************************************************************/
int levenstein(char u[], char v[]) {
    /* L[i,j] = distance entre le préfixe de taille i de u 
     * et le préfixe de taille j de v */
    int L[N+1][M+1]; 
    
    //Pour passer d'un mot de 0 lettres à 1 lettre, ça coute 1
    for (int i = 0; i < N + 1; i++) { L[i][0] = 1; }
    for (int i = 0; i < M + 1; i++) { L[0][i] = 1; }
    //Pour passer d'un mot vide à un mot vide, ça coute 0
    L[0][0]=0;
    

    int c1,c2,c3;
    // u = u'a ; v = v'b
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            
            //Si on fait un changement sur la dernière lettre
            if (u[i-1] != v[j-1]) { c1 = L[i-1][j-1] + 1; }
            else { c1 = L[i-1][j-1]; }

            //Si on transforme u en v', puis on ajoute b
            c2 = L[i][j-1] + 1;

            // Si on transforme u' en v, puis on enlève a
            c3 = L[i-1][j] + 1;
            
            L[i][j] = min(c1,c2,c3);
        }
    }
    
    return L[N][M];
}
/****************************************************************************
/* Impression équilibrée d'un texte
/****************************************************************************/

//W[i,j] = pénalité minimale pour placer les j premiers mots sur i lignes
//N[i,j] = nombre de mots sur la ligne i pour le placement de j mots sur i lignes

    /* Initialisation de la matrice W.
    # Disposer 0 mots sur i lignes signifie qu'on a i lignes vides. On sait
    # calculer la pénalité pour une ligne vide alors on rempli tout de suite la
    # première colonne de la matrice W.*/
    pen_pour_une_ligne_vide = penalite( 0,0,M,L ) # =0 car debut = fin = 0
    for (int i = 0; i < n+1; i++ ) { W[i,0] = i * pen_pour_une_ligne_vide }

    /*La pénalité minimum pour disposer j mots sur une seule ligne est facile à
    # calculer puisqu'il n'y a qu'une seule façon de disposer j mots sur une
    # seule ligne. */
    for (int j = 0; j < n+1; j++ ) { 
				W[1,j] = penalite( 1, j, M, L );
        N[1,j] = j;
		}


		/* Initialisation de la matrice W à INFINI pour les valeurs par encore calculées*/
    for (int i = 2; i < n+1; i++ ) {
        for (int j = 1; j < n+1; j++ ) { W[i,j] = INFINI; }
		}

		/* Pour placer j mots sur i lignes, je vais décomposer j en sommes de 2 nombres :
		# j = a + (j-a) (correspond à disposer les a premiers mots sur i-1 lignes et les j-a derniers mots sur la ligne i).
		# avec la définition donnée pour a, la pénalité est W[i-1,a] + Penalite(a + 1,j,M,L)
		# il faut donc parcourir toutes les valeurs possibles de a (de 0 à j)
    # la valeur minimale de W[i-1,a] + Penalite(a + 1,j,M,L) est W[i,j]
		# a est le nombre de mots placés sur les i-1 premières ligne, donc N[i,j] = j-a */

    for (int i = 2; i < n+1; i++ ) {
        for (int j = 1; j < n+1; j++ ) {
            pen_min_pour_j_mots_sur_i_lignes = INFINI 
            nb_mots_i_moins_1_premieres_lignes_optimal = 0
            for (int a = 0; a < j; a++) {
                //on ne trouvera plus de minimum si un des termes de la somme est infini
                if (W[i-1,a] == INFINI) { break; }
                //on regarde si a minimise la pénalité
                candidat = W[i-1,a] + penalite(a+1, j, M, L)
                if ( candidat < pen_min_pour_j_mots_sur_i_lignes) {
                    pen_min_pour_j_mots_sur_i_lignes = candidat
                    nb_mots_i_moins_1_premieres_lignes_optimal = a
								}
						}

            W[i,j] = pen_min_pour_j_mots_sur_i_lignes
            N[i,j] = j - nb_mots_i_moins_1_premieres_lignse_optimal
				}
				/* si il était plus intéressant de disposer tous les mots sur i-1 lignes que sur i lignes,
        # c'est qu'on a dépassé le nombre de lignes optimal, inutile donc de continuer.*/
        if (W[i,n] > W[i-1,n]) { break; }
		}



/****************************************************************************
/* Sudoku
/****************************************************************************/

/****************************************************************************
/* Dancing Links
/****************************************************************************/

