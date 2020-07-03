#include <stdio.h>

/* preços: popular: R$ 1,00
		   Geral: R$ 5,00
		   Arquibancada: R$ 10,00
		   Cadeira: R$ 20,00 */

int main (){

	int pessoas, jogos, i;
	float popular, geral, arquibancada, cadeira; //float do número de pessoas em relação ao total
	float ppopular, pgeral, parquibancada, pcadeira; //float de porcentagens
	float atotal; //float de arrecadação total
	

	scanf("%d", &jogos);

	for (i = 1; i <= jogos; i++) {

		scanf("%d%f%f%f%f", &pessoas, &ppopular, &pgeral, &parquibancada, &pcadeira);

		popular = ppopular / 100 * pessoas;

		geral = pgeral / 100 * pessoas * 5;

		arquibancada = parquibancada / 100 * pessoas * 10;

		cadeira = pcadeira / 100 * pessoas * 20;

		atotal = popular + geral + arquibancada + cadeira;

		printf("A RENDA DO JOGO N. %d E = %.2f\n", i, atotal);

	}


	return 0;
}