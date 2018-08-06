#ifndef _EXERC2REG_H_
#define _EXERC2REG_H_

// Definicao do tipo de dados heterogeneo ("registro")
struct habitante {
	int idade;
	char sexo;
	float salario;
	int filhos;
};

// Define nomes para os arquivos que armazenam o censo
#define ARQ_TEXTO	"/tmp/censo.txt"
#define ARQ_BINARIO	"/tmp/censo.bin"

// Prototipos das funcoes do exercicio
void cadastraCenso(struct habitante [*], int);	// grava nos arquivos
float calculaMediaSalario(struct habitante*, int);	// le do vetor
void menorMaiorIdade(int*, int*);	// le do arquivo-texto
									// como nao pode devolver (retornar)
									// duas variaveis, faz isso por ponteiro
int mulheres3sal900(void);	// le do arquivo-binario (sem parametros porque
							// a regra eh fixa e o nome do arquivo lido tbem

#endif

