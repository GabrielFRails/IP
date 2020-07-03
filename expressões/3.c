#include <stdio.h>

#define pi 3.14159

int main () {

    float raio, h, Ac, Al, At, precoLata;
    scanf("%f%f", &raio, &h);

    Ac = pi * raio * raio;
    Al = 2 * pi * raio * h;
    At = 2 * Ac + Al;
    precoLata = At * 100;

    printf("O VALOR DO CUSTO E = %.2f R$\n", precoLata);

    return 0;
}