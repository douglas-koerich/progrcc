#include <stdio.h>
#include <math.h>
#include "ponto.h"

// Eh preferivel que estruturas passadas como parametros para funcoes o sejam
// atraves de ponteiros (use const se o ponteiro nao deve ser usado para
// alterar o conteudo da estrutura)
double calcDistPontos(const struct Ponto*, const struct Ponto*);

int main() {
    // DECLARACAO de uma variavel-registro
    struct Ponto p; // 'p' eh uma VARIAVEL do TIPO 'Ponto', composta por
                    // dois campos, 'x' e 'y' (como um ponto no plano deve ser)
    Pto q;          // Usando o typedef, ao inves
    double x;       // nao se confunde com o 'x' do 'p'

    printf("Digite as coordenadas do ponto P:\nX? ");
    scanf("%lf", &p.x);
    printf("Y? ");
    scanf("%lf", &p.y);

    printf("Digite as coordenadas do ponto Q:\nX? ");
    scanf("%lf", &q.x);
    printf("Y? ");
    scanf("%lf", &q.y);

    // Calcula a distancia entre os pontos P e Q
    double d = sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));

    // Chama uma funcao que faz o mesmo calculo
    d = calcDistPontos(&p, &q); // passa os ENDERECOS das variaveis-registros

    printf("A distancia entre os pontos eh %lf.\n", d);
    return 0;
}

double calcDistPontos(const struct Ponto* a, const struct Ponto* b) {
    // Como recebi ponteiros como parametros (e ponteiros sao soh numeros!),
    // preciso aplicar o * para acessar o conteudo do ponteiro (o registro)
    double d = sqrt(pow((*a).x - (*b).x, 2) + pow((*a).y - (*b).y, 2));

    // Melhor alternativa eh usar o operador "seta", que acessa o campo de
    // um registro atraves do ponteiro para esse registro
    d = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    return d;
}
