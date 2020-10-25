#include <stdio.h>
#include <math.h>

//arquivo que abriga as várias funções que desenvolvi ou descobri em minhas sessões de estudos

unsigned long int fatorial(unsigned long int a){ // fatorial recursivo

    if(a == 1 || a == 0) return 1;

    else if(a > 1) return a * fatorial(a - 1);
}

int fibonacci( int t1, int t2, int n){ //função que retorna o n°ésimo número de uma sequência de fibonacci
    int seq[n], i=0;
    seq[0]=t1; seq[1]=t2;

    for(i=2; i<=n; i++){
        seq[i] = seq[i-1] + seq[i-2];
        if(i==n) return seq[n-1];
    }
}

int invert(int a){ //função que inverte um número de 3 dígitos
    int n1, n2, n3, new_number;
    n1 = a/100;
    n2 = (a%100)/10;
    n3 = a%10;
    new_number = n3*100 + n2*10 + n1;
    return new_number;
}

int soma_divisores(int x){ //função que retorna a soma dos divisores de um número
    int s=0, d;
    for(d=1;d<=x/2;d++){
        if(x%d==0){
            s+=d;
        }
    }
    return s;
}

double absoluto(double a){ //função para retornar o valor absoluto de um número
    if(a<0) return a*(-1); 
    else return a;
}