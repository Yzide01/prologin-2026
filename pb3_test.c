#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pile_t {
    int element;
    struct pile_t* prochain;
} pile;

pile* creer_pile_vide(){
    pile* res = malloc(sizeof(pile));
    return res;
}

// Empile un element dans la pile
pile* empile(pile* p, int e){
    pile* nouveau = malloc(sizeof(pile));
    nouveau -> element = e;
    nouveau -> prochain = p;
    return nouveau;
}

//depile un element de la pile. Renvoie l'element depile. Renvoie -1 si la pile est vide
int depile(pile** p){
    if (*p){
        int res = (*p)->element;
        pile* temp = *p;
        *p = (*p)->prochain;
        free(temp);
        return res;
    }
    return -1;
}

// Libere l'espace memoire allouee a une pile
void free_pile(pile* p){
    if (p){
        if (p->prochain) free_pile(p->prochain);
        free(p);
    }
}

// Ajoute les robots qui peuvent devenir notre ami le tour i dans la pile, l'enregistre dans le tableau des resultats
bool ajoute_amis_pile(int n, pile* p, int* seuils){
    bool res = false;
    for (int i = 0; i<n; i++){
        if (seuils[i] == 0){
            empile(p,i);
            seuils[i] --; //pour que l'on ne l'empile pas encore dans le futur
            res = true;
        }
    }
    return res //retourne true s'il y a eu un nouvel ami
}


/// \param n le nombre de robots
/// \param robots la liste des descriptions des robots : séparés par un espace, d'abord le prénom (maximum 16 caractères), ensuite le nom (maximum 16 caractères), puis le type du robot (P pour un robot prénomial, N pour un robot nomial) et finalement un entier seuil, le nombre de relations en commun nécessaire avant que le robot n'accepte notre demande de lien
void calcul_lien(int n, char** robots) {
    /* TODO Afficher, sur une ligne et séparés par un espace, le nombre minimal
    de jours nécessaires pour former un lien de confiance avec chaque robot.
    S'il est impossible de former un lien de confiance avec un robot, afficher
    `-1`.  */

    int resultats = malloc(n*sizeof(int));
    bool continuer = true;  
    int ind = 0;

    //initialisation pile





    while (ajoute_amis_pile()){

    }


}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // \n
    char** robots = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        robots[i] = (char*)malloc((64 + 1) * sizeof(char));
        scanf("%[^\n]", robots[i]);
        getchar(); // \n
    }
    calcul_lien(n, robots);

    return 0;
}
