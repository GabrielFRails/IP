#include <stdio.h>
#include <math.h>

int main (){

	int number, i, Q;
	scanf("%d", &number);

	if (number < 2000 && number > 5) {

		for (i = 2; i <= number; i++) {

			if((i % 2) == 0) {

				Q = pow(i,2);
				printf("%d^2 = %d\n", i, Q);
			}
		}

	}

	return 0;
}