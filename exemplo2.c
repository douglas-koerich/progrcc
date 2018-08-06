/* Escreva um programa que leia um valor correspondente ao numero de
 * segundos passados desde a meia-noite e imprima a hora correspondente no
 * formato HH:MM:SS */

#include <stdio.h>

int main() {
	int total, horas, minutos, segundos;

	printf("Digite o total de segundos desde a meia-noite: ");
	scanf("%d", &total);

	horas = total / 3600;	// divisao inteira!! (com resto)
	total = total % 3600;	// abandona o valor original para armazenar o resto
							// usado na proxima expressao (calculo dos minutos)
							// NOTA: eu poderia usar total %= 3600;
	minutos = total / 60;
	segundos = total % 60;

	printf("O valor corresponde a %02d:%02d:%02d.\n", horas, minutos, segundos);

	return 0;
}

