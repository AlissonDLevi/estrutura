#include<stdio.h>
#include<string.h>


int inverte (char *n, int y, int aux) {
    if (y <= aux) return 1;
    else {
        if (n[y - 1] != n[aux]) return 0;

        return inverte(n, y-1, aux+1);
    } 
}

 int palindromo (char *n) {
    int aux1, x = 0;

    aux1 = inverte(n, strlen(n), x);

    if (aux1 == 1) printf("Eh palindromo\n");
    else printf("Nao eh palindromo\n");
   }
 int main() {
 
   palindromo("riasotivesortemaametrosevitosair");
   return 0;
   }