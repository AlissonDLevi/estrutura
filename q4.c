#include<stdio.h>

int binomio(int n, int k){
    if(n== 0 && k== 0){
        return 1;
    }else{
        return binomio(n-1, k-1) + binomio(n-1,k);
    }
}

int main(int argc, char const *argv[])
{
    printf("o binomio (n,k)- %d\n",binomio(0,0));
    return 0;
}