#include <stdio.h>
#include <math.h>

/*
Este Programa calcula y a partir de x.
*/

int main(){

    int x = 0, y = 0;
    scanf("%d", &x);

    if(x < 1){

        y = x;

    }else if(x == 1){

        y = 0;

    }else if(x > 1){

        y = pow(x, 2);

    }

    printf("Y = %d", y);

    return 0;
}