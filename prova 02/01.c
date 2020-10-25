#include <stdio.h>
#include <math.h>

int digit_count(long int n);
int main(){

    long int n;
    scanf("%ld", &n);

    printf("Numero de digitos: %d", digit_count(n));

    return 0;
}

int digit_count(long int n){
    int cont=0;
    while(n/10>=1){
        n/=10;
        cont++;
    }
    return cont+1;
}