#ifndef EXERC7LISTA7_H
#define EXERC7LISTA7_H

#define MAX_NOME    80

struct funcionario {
    char nome[MAX_NOME];
    float horas;
    char turno;
    char categoria;
    float valor_hr;
    float salario_bruto;
    float auxilio_alim;
};

void cadastra_novos(struct funcionario lista[*], size_t num);
void le_arquivo(struct funcionario lista[*], size_t max, size_t* usado);
void grava_arquivo(struct funcionario lista[*], size_t num);
void mostra_folha(void);

#endif
