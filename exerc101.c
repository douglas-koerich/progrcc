#include <stdio.h>
#include <stdio_ext.h>

// DEFINICAO da estrutura
#define MAX_NOME	20
struct habitante {	// isto eh o MODELO do registro, nao armazena informacao!
	// Campos do registro do habitante
	char sexo;
	float altura;
	int idade;	// ERRADO: int idade = 0;	// modelo nao guarda valores!
	char olhos;	// A - azuis, V - verdes, C - castanhos
	char nome[MAX_NOME+1];
	// struct data data_nasc; >>> Voce pode ter um registro dentro de outro
};	// aqui precisa de um ponto-e-virgula

typedef struct habitante Habitante;

/*** Nao faz parte do problema, apenas pusemos aqui para ilustrar outro
 * modo de usar o typedef...
typedef struct data {
	int dia, mes, ano;
} Data;	// Data NAO eh uma variavel, eh um apelido de struct data feito
		// pelo typedef
***/

/* Exemplos de variaveis globais, inclusive com inicializacao...
// DECLARACAO de variaveis (globais, zeradas) do tipo-estrutura
struct habitante hab_a, hab_b;
Habitante hab_c;

// Inicializacao de variavel-estrutura
struct habitante hab_x = {
	'F', 1.50, 22, 'V', "Joao"	// na ordem da definicao dos campos!
};
Habitante grupo_de_casais[50][2] = {
	{ { 'M', 1.80, 30, 'A', "Joaquim" },	{ 'F', 1.70, 27, 'A', "Josefa" } },
	{ { 'F', 1.62, 56, 'V', "Fritz" },	{ 'M', 1.68, 57, 'C', "Frida" } }
	// se nao preenche as demais, funciona como no vetor de escalares...
};
*/

#define POPULACAO	5

int main(void) {
	/* Outros exemplos de variaveis, inclusive alocacao dinamica
	Habitante hab_d;
	struct habitante* hab_din = (struct habitante*) malloc(sizeof(struct habitante));	// um habitante alocado dinamicamente

	// Exemplificando o acesso aos campos das variaveis:

	// Preenchendo o hab_d com seus dados, campo a campo
	hab_d.sexo = toupper(getchar());
	hab_d.altura = 1.80;
	printf("Digite a idade do hab_d: ");
	scanf("%d", &hab_d.idade);
	hab_d.olhos = 'C';
	strcpy(hab_d.nome, "Anonimo");

	// Preenchendo o habitante alocado dinamicamente
	(*hab_din).sexo = 'M';
	hab_din->altura = 1.60;	// (*hab_din).altura = 1.60;
	...
	*/

	Habitante povo[POPULACAO];

	/* Se fosse com alocacao dinamica...
	Habitante *povo = (Habitante*) malloc(POPULACAO*sizeof(Habitante));
	*/

	// Questionario: preencher o vetor
	int h;
	for (h = 0; h < POPULACAO; ++h) {
		printf("\nHabitante #%d\n", h+1);
		printf("Digite o nome: ");
		__fpurge(stdin);
		gets(povo[h].nome);
		do {
			printf("Digite o sexo: ");
			scanf(" %c", &povo[h].sexo);
			povo[h].sexo = toupper(povo[h].sexo); // converte para maiusc.
		} while (povo[h].sexo != 'F' && povo[h].sexo != 'M');
		printf("Digite a altura: ");
		scanf("%f", &povo[h].altura);
		printf("Digite a idade: ");
		scanf("%d", &povo[h].idade);
		char cor;
		do {
			printf("Digite a cor dos olhos: ");
			__fpurge(stdin);
			cor = toupper(getchar());
		} while (cor != 'A' && cor != 'V' && cor != 'C');
		povo[h].olhos = cor;
	}

	// Estatisticas
	Habitante* ph;
	float media = 0.0;
	int maior = -1, cont = 0, femin = 0, homens = 0; 
	// (cada incremento de ph poe no inicio da proxima estrutura)
	for (h = 0, ph = povo; h < POPULACAO; ++h, ++ph) {
		// letra a
		if (ph->olhos == 'C' && ph->altura > 1.60) {
			++cont;
			media += ph->idade;
		}
		// letra b
		if (ph->idade > maior) {
			maior = ph->idade;
		}
		// letra c
		if (ph->sexo == 'F' &&
			((ph->idade >= 20 && ph->idade <= 45) ||		// 1o. criterio
			 (ph->olhos == 'V' && ph->altura < 1.70))) {	// 2o. criterio
			++femin;
		}
		// letra d
		if (ph->sexo == 'M') {
			++homens;
		}
	}
	// No final tira a media para a letra a
	media /= cont;

	// Resultados
	printf("\n\na) Media de idade: %.1f anos.\n", media);
	printf("b) Maior idade: %d anos.\n", maior);
	printf("c) Mulheres com criterios: %d\n", femin);
	printf("d) Percentual de homens: %.1f%%\n", homens*100.0/POPULACAO);
	return 0;
}

