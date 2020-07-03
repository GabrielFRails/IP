#include <stdio.h>

int main(){

    double tempC = 0, tempF = 0;
    int cont = 0, i = 0;
    scanf("%d", &cont);

    

    for(i = 1; i <= cont; i++){

        scanf("%lf", &tempF);

        tempC = 5 * (tempF - 32) / 9;
        printf("%.2lf FAHRENHEIT EQUIVALE A %2.lf CELSIUS\n", tempF, tempC);

    }


    return 0;
}