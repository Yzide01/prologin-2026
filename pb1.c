#include <stdio.h>
#include <stdlib.h>

//typing in english because I'm typing with dvorak layout
//calculates the distance between a and b in the square of side n
void mouvement_minimum(int n, int a, int b) {
    int x_dep,y_dep; //trying to calculate the "coordinates" 
    int x_arr,y_arr;
    x_dep = (a-1)/n;
    y_dep = (a-1)%n ;
    x_arr = (b-1)/n;
    y_arr = (b-1)%n; 


    printf("%d\n",abs(x_dep-x_arr)+abs(y_dep-y_arr));
}


int main() {
    int n;
    scanf("%d", &n);
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    mouvement_minimum(n, a, b);

    return 0;
}
