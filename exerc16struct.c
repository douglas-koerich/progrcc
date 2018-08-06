#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ponto {
	double x, y;
};

// Ao passar estruturas para funcoes, prefira passa-las por endereco; mas,
// para evitar que a funcao ALTERE o conteudo da estrutura, uma vez que ela
// pode faze-lo atraves do ponteiro, defina-o como 'const'
double distancia(const struct ponto*, const struct ponto*);

// Esta funcao, ao contrario, QUER alterar a estrutura passada como
// parametro
void preenche(struct ponto*);

int main(void) {
	struct ponto P, Q;	// dois pontos no plano cartesiano

	preenche(&P);
	preenche(&Q);

	// Salva os pontos em um arquivo-texto
	FILE* texto = fopen("pontos.txt", "wt");
	if (texto == NULL) {
		perror("Ihh, me ferrei...:");
		return -1;
	}
	fprintf(texto, "(%.3lf,%.3lf)\n", P.x, P.y);
	fprintf(texto, "(%.3lf,%.3lf)\n", Q.x, Q.y);
	fclose(texto);

	// Salva os pontos em um arquivo-binario
	FILE* binario = fopen("pontos.bin", "wb");
	if (binario == NULL) {
		perror("Bit, bit bit bit (me ferrei em binario)...:");
		return -1;
	}
	fwrite(&P, sizeof(struct ponto), 1, binario);
	fwrite(&Q, sizeof(struct ponto), 1, binario);
	fclose(binario);

	printf("A distancia entre os pontos eh %lf.\n", distancia(&P, &Q));

	// Com arquivos binarios formados por estruturas/registros de tamanho
	// fixo, pode-se fazer acesso aleatorio (e nao sequencial). Por
	// exemplo, o seguinte codigo le o valor do SEGUNDO ponto gravado no
	// arquivo, ignorando ("pulando") o primeiro ponto
	binario = fopen("pontos.bin", "rb");
	if (binario == NULL) {
		perror("Nhuoum, Nhuoum, ...:");
		return -1;
	}
	// O "ponteiro" de leitura do arquivo esta no inicio quando eh aberto;
	// vamos reposiciona-lo alguns bytes a frente; saltamos o numero de
	// bytes correspondentes ao tamanho de um registro (ponto), contando
	// a partir da posicao inicial
	struct ponto* um_ponto = (struct ponto*) malloc(sizeof(struct ponto));
	fseek(binario, sizeof(struct ponto), SEEK_SET);	// SEEK_SET = inicio
	fread(um_ponto, sizeof(struct ponto), 1, binario);
	printf("O segundo ponto eh: (%.3lf, %.3lf)\n", um_ponto->x, um_ponto->y);
	free(um_ponto);
	return 0;
}

void preenche(struct ponto* p) {
	printf("Digite a abscissa (x): ");
	scanf("%lf", &(p->x));
	printf("Digite a ordenada (y): ");
	scanf("%lf", &p->y);
}

double distancia(const struct ponto* p, const struct ponto* q) {
	double d = pow((q->x - p->x), 2) + pow((q->y - p->y), 2);
	d = sqrt(d);
	return d;
}

