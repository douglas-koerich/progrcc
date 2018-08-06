#include <stdio.h>

int main() {
	int hj_dia, hj_mes, hj_ano,
		amanha_dia, amanha_mes, amanha_ano;

	printf("Digite o dia de hoje (0-31): ");
	scanf("%d", &hj_dia);
	printf("Digite o mes de hoje (1-12): ");
	scanf("%d", &hj_mes);
	printf("Digite o ano de hoje: ");
	scanf("%d", &hj_ano);

	amanha_mes = hj_mes;
	amanha_ano = hj_ano;

	if (hj_dia >= 28) {
		/*
		if (hj_mes == 2) {
			amanha_dia = 1;
			amanha_mes = 3;
		}
		else {
			if (hj_mes == 1 || hj_mes == 3 || hj_mes == 5 ||
				hj_mes == 7 || hj_mes == 8 || hj_mes == 10 ||
				hj_mes == 12) {
				if (hj_dia != 31) {
					amanha_dia = hj_dia + 1;
				}
				else {
					amanha_dia = 1;
					if (hj_mes == 12) {
						amanha_mes = 1;
						amanha_ano = hj_ano + 1;
					}
					else {
						amanha_mes = hj_mes + 1;
					}
				}
			}
			else {
				if (hj_dia != 30) {
					amanha_dia = hj_dia + 1;
				}
				else {
					amanha_dia = 1;
					amanha_mes = hj_mes + 1;
				}
			}
		}
		*/
		switch (hj_mes) {
			case 2:
				amanha_dia = 1;
				amanha_mes = 3;
				break;

			case 1: case 3: case 5: case 7:
			case 8: case 10: case 12:
				if (hj_dia != 31) {
					amanha_dia = hj_dia + 1;
				}
				else {
					amanha_dia = 1;
					if (hj_mes == 12) {
						amanha_mes = 1;
						amanha_ano = hj_ano + 1;
					}
					else {
						amanha_mes = hj_mes + 1;
					}
				}
				break;

			default:
				if (hj_dia != 30) {
					amanha_dia = hj_dia + 1;
				}
				else {
					amanha_dia = 1;
					amanha_mes = hj_mes + 1;
				}
		}
	}
	else {
		amanha_dia = hj_dia + 1;
	}
	printf("Amanha eh %02d/%02d/%04d.\n", amanha_dia, amanha_mes, amanha_ano);

	return 0;
}

