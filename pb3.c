#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pile_t {
    int element;
    struct pile_t* prochain;
} pile;

pile* creer_pile_vide(){
    return NULL;
}

// Empile un element dans la pile
pile* empile(pile* p, int e){
    pile* nouveau = malloc(sizeof(pile));
    nouveau -> element = e;
    nouveau -> prochain = p;
    return nouveau;
}

// Depile un element de la pile. Renvoie l'element depile. Renvoie -1 si la pile est vide
int depile(pile** ptr_p){
    if (*ptr_p){
        int res = (*ptr_p)->element;
        pile* temp = *ptr_p;
        *ptr_p = (*ptr_p)->prochain;
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

// Stocke les informations donnees par l'entree 'robots'
void get_infos(char** robots, int n, char **prenoms, char** noms, char* types, int* seuils){
    for (int i=0; i<n; i++){
        int ind = 0;
        prenoms[i] = malloc(17*sizeof(char));
        noms[i] = malloc(17*sizeof(char));
        int j = 0;
        while (robots[i][ind] != ' '){
            prenoms[i][j] = robots[i][ind];
            ind++;
            j++;
        }
        prenoms[i][j] = '\n';
        ind++;

        j = 0;
        while (robots[i][ind] != ' '){
            noms[i][j] = robots[i][ind];
            ind++;
            j++;
        }
        noms[i][j] = '\n';
        ind++;

        types[i] = robots[i][ind];

        seuils[i] = robots[i][ind+2] - '0';  //conversion en entier 
    }
}


// Ajoute les robots qui peuvent devenir notre ami le tour i dans la pile, l'enregistre dans le tableau des resultats
bool ajoute_amis_pile(int n, pile** ptr_p, int* seuils, int* resultats, int jour){
    bool res = false;
    for (int i = 0; i<n; i++){
        if (seuils[i] == 0){
            *ptr_p = empile(*(ptr_p),i);
            seuils[i] --; //pour que l'on ne l'empile pas encore dans le futur
            res = true;
            resultats[i] = jour;
        }
    }
    return res; //retourne true s'il y a eu un nouvel ami
}


void free_robots(char** robots, int n, char** prenoms, char** noms, char* types, int* seuils){
    for (int i = 0; i<n; i++){
        free(robots[i]);
        free(prenoms[i]);
        free(noms[i]);
    }
    free(types);
    free(seuils);
    free(robots);
    free(prenoms);
    free(noms);
}


/// \param n le nombre de robots
/// \param robots la liste des descriptions des robots : séparés par un espace, d'abord le prénom (maximum 16 caractères), ensuite le nom (maximum 16 caractères), puis le type du robot (P pour un robot prénomial, N pour un robot nomial) et finalement un entier seuil, le nombre de relations en commun nécessaire avant que le robot n'accepte notre demande de lien
void calcul_lien(int n, char** robots) {
    /* TODO Afficher, sur une ligne et séparés par un espace, le nombre minimal
    de jours nécessaires pour former un lien de confiance avec chaque robot.
    S'il est impossible de former un lien de confiance avec un robot, afficher
    `-1`.  */

    int* resultats = malloc(n*sizeof(int));
    for (int i = 0; i<n; i++){
        resultats[i] = -1;
    }

    int* seuils = malloc(n*sizeof(int));
    char* types = malloc(n*sizeof(char));
    char** prenoms = malloc(n*sizeof(char*));
    char** noms = malloc(n*sizeof(char*));

    get_infos(robots, n, prenoms, noms, types, seuils);

    int jour = 1;

    pile* p = creer_pile_vide();
    while (ajoute_amis_pile(n,&p,seuils,resultats,jour)){
        //on depile toute la pile, on prend en compte les amis pour reduire les seuils ("propagation")
        while (p){
            int ami = depile(&p);
            for (int i=0; i<n; i++){
                if ((strcmp(prenoms[i],prenoms[ami]) == 0 && types[i] == 'P')||((strcmp(noms[i],noms[ami]) == 0 && types[i] == 'N'))){
                    seuils[i] --;
                }
            }
        }
        jour++;
    }

    for (int i=0; i<n-1; i++){
        printf("%d ",resultats[i]);
    }
    printf("%d\n", resultats[n-1]);

    free_robots(robots, n, prenoms, noms, types, seuils);
    free(resultats);
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
