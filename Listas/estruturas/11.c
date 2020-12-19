#include <stdio.h>
#include <stdlib.h>

typedef struct IMOVEL{
    int n_moradores;
    int consumo_total;
    int consumo_medio;
}Imovel;

Imovel *im;

void swap(Imovel *im, int i, int j);
int veirify_consumo(Imovel *im, int i1, int i2);

int main(){

    int i, j, k = 1, N;
    float consumo = 0, moradores = 0;
    
    while(1){

        scanf("%d", &N);
        if(N==0) break;
        im = (Imovel*) calloc(N, sizeof(Imovel));

        for(i=0; i<N; i++){
            scanf("%d %d", &im[i].n_moradores, &im[i].consumo_total);
            im[i].consumo_medio = im[i].consumo_total / im[i].consumo_total;
        }
        printf("Cidade # %d:\n", k);


        for(i=0; i<N; i++)
            for(j=0; j<N; j++){
                if(veirify_consumo(im, i, j)==1) swap(im, i, j);
            }

        for(i=0; i<N; i++){
            printf("%d-%d ", im[i].n_moradores, im[i].consumo_medio);
            consumo += im[i].consumo_medio;
            moradores += im[i].n_moradores;
        }
        consumo /= moradores;
        printf("%.2f\n", consumo);
        k++;
        consumo = 0;
        free(im);
    
    }

    return 0;
}

int veirify_consumo(Imovel *im, int i1, int i2){
    if(im[i1].consumo_medio < im[i2].consumo_medio) return 0;
    return 1;
}

void swap(Imovel *im, int i, int j){
    Imovel aux;
    aux = im[i];
    im[i] = im[j];
    im[j] = aux;
}