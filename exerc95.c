#include <stdio.h>

/***********************************************************************/
// Estas definicoes nao fazem parte do exercicio, estao aqui
// para ilustrar a declaracao de matriz com tamanho constante
// pre-definido (nao variavel) e os tipos de inicializacao
#define LINHAS	2
#define COLUNAS	3
int exemplo[LINHAS][COLUNAS] =
{
	// cada linha pode ser vista como um vetor (de colunas)
	{ 56, 89, 12 },	// linha 0
	{ 87, 23, 11 }	// linha 1
};

int exemplo2[LINHAS][COLUNAS] =
{
	{ 56 },	// primeira coluna = 56, demais colunas terao 0
	{ 57, [2] = 30 },	// primeira coluna = 57, ultima = 30, do meio = 0 
};

int exemplo3[][COLUNAS] =	// NAO PODE DECLARAR ASSIM: int exemplo3[][]
{
	{ 38, 12 },	// soh preencheu 2 das 3 colunas, ultima = 0
	{ 23, 13, 11 },
	{ 36, 12, 9 },
	{ 44, 12, 7 }	// essa matriz tem 4 linhas!
};
/***********************************************************************/

void gira(int, int [*][*]);	// ou: void gira(int, int [][*]);

int main(void) {
	int tam;

	printf("Digite a dimensao da matriz quadrada: ");
	scanf("%d", &tam);

	// Declara uma matriz (vetor bidimensional) com 'tam' linhas
	// e 'tam' colunas
	int matriz[tam][tam];

	// Preenche a matriz com valores lidos do teclado
	// Percurso eh feito com LACOS ANINHADOS (n dimensoes = n lacos)
	int indice_lin, indice_col;
	for (indice_lin = 0; indice_lin < tam; ++indice_lin) { // para cada linha...
		for (indice_col = 0; indice_col < tam; ++indice_col) { // para cada coluna DA LINHA=indice_lin
			printf("Digite o valor em [%d][%d]: ", indice_lin, indice_col);
			scanf("%d", &matriz[indice_lin][indice_col]);
		}
	}

	// Imprime linha por linha da matriz
	for (indice_lin = 0; indice_lin < tam; ++indice_lin) { // para cada linha...
		for (indice_col = 0; indice_col < tam; ++indice_col) { // para cada coluna DA LINHA=indice_lin
			printf("%3d ", matriz[indice_lin][indice_col]);
		}
		// no fim de cada linha (depois do laco das colunas), pula na tela
		// para proxima linha
		putchar('\n');
	}
	putchar('\n');

	/***********************************************************
	 * Este codigo nao faz parte da solucao do exercicio, apenas
	 * ilustra o percurso em coluna ao inves de em linha
	// Imprime coluna por coluna da matriz ("matriz transposta")
	for (indice_col = 0; indice_col < tam; ++indice_col) { // para cada coluna...
		for (indice_lin = 0; indice_lin < tam; ++indice_lin) { // para cada linha DA COLUNA=indice_col
			printf("%3d ", matriz[indice_lin][indice_col]);	// NAO ALTERA A ORDEM DOS INDICES!!!
		}
		// no fim de cada coluna (depois do laco das linhas), pula
		// para proxima linha da tela
		putchar('\n');
	}
	***********************************************************/

	// Chama uma funcao para girar a matriz
	gira(tam, matriz);	// se a matriz nao fosse quadrada, precisaria
						// passar 2 parametros de tamanho (linhas e colunas)

	// Imprime linha por linha da matriz girada
	for (indice_lin = 0; indice_lin < tam; ++indice_lin) {
		for (indice_col = 0; indice_col < tam; ++indice_col) {
			printf("%3d ", matriz[indice_lin][indice_col]);
		}
		putchar('\n');
	}
	putchar('\n');

	return 0;
}

void gira(int tam, int m[][tam]) {	// a ordem dos parametros importa, porque
									// tam precisa ser conhecido antes de m
	int aux[tam][tam];
	int lm, cm, laux, caux;

	// Para cada linha percorrida em m, percorre uma coluna em aux
	for (lm = 0, caux = 0; lm < tam; ++lm, ++caux) {
		// Para cada coluna da linha de m percorrida, percorre uma
		// linha da coluna de aux DE BAIXO PARA CIMA
		for (cm = 0, laux = tam-1; cm < tam; ++cm, --laux) {
			aux[laux][caux] = m[lm][cm];
		}
	}
	// A matriz auxiliar tem a matriz girada, devolve (copia)
	// para matriz original
	for (lm = 0; lm < tam; ++lm) {
		for (cm = 0; cm < tam; ++cm) {
			// Copia-espelhada de uma matriz para outra
			m[lm][cm] = aux[lm][cm];
		}
	}
}

