#include "complex.h"

Complex *create_complex(double real, double img){

    Complex *cp = malloc(sizeof(Complex));
    if(cp == NULL){
        printf("Não foi possível alocar o numero\n");
        return 0;
    }

    cp->code[0] = 'C';
    cp->code[1] = 'P';
    cp->real = real;
    cp->img = img;
    //printf("real %.2lf\nimg %.2lf\n%.2lf e %.2lf\n", real, img, cp->real, cp->img);
    return cp;
}

Complex *create_complexPolar(double r, double ang){
    
    double real, img;
    real = r * cos(convert2Radianos(ang));
    img = r * sin(convert2Radianos(ang));
    return create_complex(real, img);
}

double convert2Radianos(double graus){

    return graus * pi / 180;
}

double convert2Graus(double radius){

    return radius * 180 / pi;
}

void saveComplex(Complex *cp, char* dir){
    FILE *p;
    p = fopen(dir, "wb");
    if(p == NULL) {
        printf("Não foi possível abrir o arquivo solicitado!\n");
        
    }
    
    fwrite(cp, sizeof(Complex), 1, p);
    fclose(p);
    
}

Complex * readComplex(char * dir){   
    Complex *temp = NULL;
    char code[2];
    FILE *p = fopen(dir, "rb");
    if(p == NULL){
        printf("Não foi possível abrir o arquivo no caminho especificado: \"%s\"\n", dir);
        return NULL;
    }

    temp = malloc(sizeof(Complex));
    if(temp == NULL){
        printf("Não foi possível alocar memória para o numero!\n");
        return NULL;
    }

   fread(code, 1, 2, p);
    if(code[0] != 'C' || code[1] != 'P'){
        printf("Não foi possível localizar um numero complexo no arquivo \"%s\"\n", dir);
        return NULL;
    }

    rewind(p);

    fread(temp, sizeof(Complex), 1, p);
    fclose(p);
    return temp;
}

void printComplexAlg(Complex *number){
    if(number == NULL){
        printf("Nao e possivel ler um ponteiro nulo\n");
    }
    printf("%.2lf+%.2lfi\n", number->real, number->img);
}

void printComplexGeo(Complex *number){
    if(number == NULL) printf("Nao e possivel ler um ponteiro nulo\n");

    printf("[%.2lf,%.2lf]\n", number->real, number->img);
}

void printComplexPolar(Complex *number){
    if(number == NULL) printf("Nao e possivel ler um ponteiro nulo\n");
    double ro, ang;

    ro = sqrt((pow(number->real,2)) + (pow(number->img, 2)));
    ang = convert2Graus(atan2(number->img, number->real));
    printf("%.2lf;%.2lf\n", ro, ang);
}

Complex * Soma_complexo(Complex * c1, Complex * c2){
    //(a + bi) + (c + di) = (a + c) + i (b + d)
    double real, im;
    real = c1->real + c2->real;
    im = c1->img + c2->img;
    return create_complex(real, im);
}

Complex * complexSub(Complex * a1, Complex *a2){
    //(a + bi) – (c + di) = (a – c) + i (b – d)
    double real, im;
    real = a1->real - a2->real;
    im = a1->img - a2->img;
    return create_complex(real, im); 
}

Complex * complexo_multi(Complex * c1, Complex * c2){
    //(a + bi) . (c + di) = (ac – bd) + i (ad + bc)
    double real, im;
    real = (c1->real*c2->real - c1->img*c2->img);
    im = (c1->real*c2->img + c1->img*c2->real);
    return create_complex(real, im);
}

    /*
        Z3 = x + yi = (a + bi) / (c + di).
        x = ac + bd/c^2 + d^2
        y = bc – ad/c^2 + d^2
    */

Complex * complexo_div(Complex * c1, Complex *c2){
    double x, y;
    x = ((c1->real * c2->real) + (c1->img * c2->img)) / (pow(c2->real, 2) + pow(c2->img, 2));
    y = ((c1->img * c2->real) - (c1->real * c2->img)) / (pow(c2->real, 2) + pow(c2->img, 2));
    return create_complex(x, y);
}