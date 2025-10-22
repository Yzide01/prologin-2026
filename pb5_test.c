#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/// \param n le nombre de numéros de tuiles disponibles
/// \param a le nombre d'exemplaires de la tuile portant le numéro $i$
void calcul_possibilites(int n, int* a) {
    /* TODO Afficher en sortie le reste de la division par $10^9 + 7$ du nombre
    de mains complètes différentes que Joseph Marchand peut former avec les
    tuiles disponibles  */



    // Si le nombre total de tuiles n'est pas divisible par 3, alors on ne peut pas trouver de solution
    // temps lineaire -> ne coute pas grand chose de verifier
    int n_tuiles = 0;
    for (int i=0; i<n; i++){
        n_tuiles += a[i];
    }
    if(n_tuiles%3){
        printf("0\n");
        return;
    }

    //  idee: le nombre d'elements est egal au nombre de tuiles / 3
    int nb_elem = n_tuiles/3;

    unsigned int res = 0;
    //idee: dans une main, chaque tuile appartient eventuellement a des suites de 3 tuiles et/ou des elements de 3 memes tuiles
    unsigned int * consecutifs = malloc(n*sizeof(int)); // Contient le nombre d'elements du type "3 tuiles consecutives" pour chaque tuile
    unsigned int* memes = malloc(n*sizeof(int)); // Continet le nombre d'elements du type "3 memes" tuiles pour chaque tuile

    // idee: faire des arbres pour les differents cas de figure et backtracking de gauche a droite
    //
    

    
    printf("%d\n",res);
    free(consecutifs);
    free(memes);
}

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    calcul_possibilites(n, a);

    return 0;
}
