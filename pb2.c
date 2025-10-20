#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/// \param n le nombre de classes d'âge
/// \param t écart de temps entre les deux recensements
/// \param bornes la liste des bornes des classes d'âge
/// \param avant la liste du nombre de robots par classe d'âge lors du premier recensement
/// \param apres la liste du nombre de robots par classe d'âge lors du second recensement
///
///

//retourne si x est bien dans l'intervalle entre bornes[ind] et bornes[ind+1]. 
int appartient(int x, int * bornes, int ind, int n){
    if (n==ind){  //dans ce cas, la borne de droite est INFINITY
        return (x >= bornes[ind]);
    }
    else {
        return (x >= bornes[ind]) && (x < bornes[ind+1]);
    }
}

//donne l'indice de la borne du prochain robot qui peut etre couple avec robot (qui appartient a bornes[robot];bornes[robot+1])
//renvoie -1 s'il n'en existe pas
int trouve_ind_plus_proche(int robot, int* bornes, int* apres, int n, int t){
    //on verifie dans chaque intervalle si on peut trouver le "partenaire" de robot
    for (int i = robot; i < n-1; i++){
        if (apres[i]>0 && (bornes[i] + t < bornes[i+1]{
            return i;
        }
    } 
    //si le robot couple se trouve dans le dernier intervalle
    if (apres[n-1] > 0){
         return n-1;
    }
    return -1;
}

void verifier_classes(int n, int t, int* bornes, int* avant, int* apres) {
    /* TODO Afficher sur une ligne le nombre minimum de nouveaux robots et sur
    une seconde ligne le nombre de robots partis  */

    int arriv; //min des robots arrives = n_apres - taille du "couplage" max 
    int partis; //robots partis = n_avant - taille du "couplage" max       (on couple les anciens et nouveaux robots)
    
    int n_avant = 0;
    int n_apres = 0;
    int taille_couplage_max = 0;

    //premier tour pour "coupler" les robots avant/apres
    for (int i=0; i<n; i++){
        while (avant[i] > 0){
            avant[i] --;
            n_avant ++;
            trouve_ind_plus_proche(, int *bornes, int *apres, int n, int t)
            


        }
    }


    //dernier tour pour s'il reste des robots apres non couples, ce sont donc des robots arrives.
    for (int k =0; k<n; k++){
        n_apres = n_apres + apres[k];
    }



}

int main() {
    int n;
    scanf("%d", &n);
    int t;
    scanf("%d", &t);
    int* bornes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &bornes[i]);
    int* avant = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &avant[i]);
    int* apres = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &apres[i]);
    verifier_classes(n, t, bornes, avant, apres);

    return 0;
}
