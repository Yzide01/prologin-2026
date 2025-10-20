#include <stdio.h>
#include <stdlib.h>

/// \param n le nombre de robots

/// \param robots la liste des descriptions des robots : séparés par un espace, d'abord le prénom (maximum 16 caractères), ensuite le nom (maximum 16 caractères), puis le type du robot (P pour un robot prénomial, N pour un robot nomial) et finalement un entier seuil, le nombre de relations en commun nécessaire avant que le robot n'accepte notre demande de lien

void calcul_lien(int n, char** robots) {
    /* TODO Afficher, sur une ligne et séparés par un espace, le nombre minimal
    de jours nécessaires pour former un lien de confiance avec chaque robot.
    S'il est impossible de former un lien de confiance avec un robot, afficher
    `-1`.  */
    for (int i = 0; i < n; i++){

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
