#include <stdio.h>

	#include <stdlib.h>

int main () {

	float peso;
	float altura;
	float imc;
	printf("coloque seu peso");
	scanf("%f", &peso);
	printf("Coloque sua altura");
	scanf("%f", &altura);
	


	imc= peso / ( altura * altura);
	printf("%f imc   %f peso %f",imc,imc,peso);



}