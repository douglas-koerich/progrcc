#define NUM_CURSOS	3
#define NUM_VAGAS	4

struct candidato {
	int codigo;
	unsigned short idade;
	unsigned pontuacao;
	int curso;	// 1 a 6, equivalente ao numero do curso/coluna na matriz
};
typedef struct candidato candidato;	// pode-se dar o mesmo nome

