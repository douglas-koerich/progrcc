#ifndef EXERC3LISTA7_H
#define EXERC3LISTA7_H

#define MAX_VEICULOS 300
#define TAM_PLACA 8 // "ZZZ-9999" (oito caracteres)
#define TAM_MODELO 20
#define PLACA_TESTE "ZZZ-9999"

// Definicao da estrutura para hh:mm
struct hh_mm {
    unsigned hora, minuto;
};
typedef struct hh_mm hh_mm;

// Definicao da estrutura para o registro do veiculo
struct veiculo {
    char placa[TAM_PLACA+1]; // o +1 eh para o terminador nulo
    char modelo[TAM_MODELO]; // como nao pus o +1 aqui, entao o nome podera ter
                             // ateh 19 caracteres, certo?
    char tamanho; // 'P'/'M'/'G' (valores do tipo char)
    hh_mm horario_entrada;   // Uma estrutura como campo de outra :-)
    hh_mm horario_saida;
};
typedef struct veiculo veiculo;

#endif // EXERC3LISTA7_H
