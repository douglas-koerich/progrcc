#ifndef PONTO_H_
#define PONTO_H_

// Definicao de uma estrutura que modela um ponto no plano cartesiano
// neste programa-exemplo
struct ponto {
    float x;
    float y;
};
typedef struct ponto Ponto;

// Prototipo da funcao que calcula a distancia entre dois pontos no plano
// float calcula_distancia(Ponto, Ponto); // passagem por COPIA das estruturas (possivel, mas ruim)
float calcula_distancia(const Ponto*, const Ponto*); // passagem por REFERENCIA/ENDERECO das estruturas
                                                     // use 'const' pra evitar que a funcao altere os parametros
#endif // PONTO_H_

