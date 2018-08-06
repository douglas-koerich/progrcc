#include <stdio.h>
// inicio
int main() {
//	declare mols, moleculas : real
	float mols, moleculas = 0;	// variavel moleculas zerada
	
// 	leia mols
	printf("Digite o numero de mols: ");	// prompt para usuario
	scanf("%f", &mols);
	
//	moleculas <- mols * 6.023 * 10^23
	moleculas = mols * 6.023E+23;
	
//	escreva moleculas
	printf("O numero de moleculas em %.1f mols eh %.0f (%e)\n",
		   mols, moleculas, moleculas);
		   
// fim
	return 0;
}

