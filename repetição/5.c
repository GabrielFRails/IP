#include <stdio.h>

//2, 6, 10, 14, 18.

int main(){

    int num_init = 0, razao = 0, ntermos = 0, soma = 0, i = 0, aux = 0;
    scanf("%d%d%d", &num_init, &razao, &ntermos);

    for(i = 1; i < ntermos; i++){

        aux = num_init + (razao * i);
        soma = num_init + (num_init + (razao * i)); 
        printf("%d -- %d\n", soma, aux);
        
    }

    

    return 0;
}

