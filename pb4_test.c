#include <stdio.h>
#include <stdlib.h>

/// un couloir reliant deux pièces de l'entrepôt
struct couloir {
    int a; ///< la première pièce
    int b; ///< la seconde pièce
    int c; ///< la couleur de la porte du couloir, ou 0 s'il n'y a pas de porte
};

/// \param n le nombre de couloirs de l'entrepôt
/// \param p le nombre de pièces de l'entrepôt
/// \param m le nombre de couleurs différentes pouvant être appliquées aux portes
/// \param s le nombre de portes de la même couleur pouvant être franchies sans interruption
/// \param x la pièce de départ
/// \param y la pièce d'arrivée
/// \param entrepot la liste de tous les couloirs de l'entrepôt
void entrepot_en_t(int n, int p, int m, int s, int x, int y, struct couloir* entrepot) {
    /* TODO Afficher le nombre minimum de portes franchies afin d'atteindre la
    pièce d'arrivée. Si cela n'est pas possible, afficher -1.  */

    // on aimerait pouvoir juste utiliser dijkstra. 
    // le truc qui derange, c'est la condition des couleurs des portes.
    //
    // idee 1: des qu'on a traverse la limite des portes de meme couleur, on interdit de passer dans une nouvelle porte de la meme couleur
    // probleme: on pourrait se retrouver bloque
    //
    // idee 2: 
}

int main() {
    int n;
    scanf("%d", &n);
    int p;
    scanf("%d", &p);
    int m;
    scanf("%d", &m);
    int s;
    scanf("%d", &s);
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);
    struct couloir* entrepot = (struct couloir*)malloc(n * sizeof(struct couloir));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &entrepot[i].a, &entrepot[i].b, &entrepot[i].c);
    }
    entrepot_en_t(n, p, m, s, x, y, entrepot);

    return 0;
}
