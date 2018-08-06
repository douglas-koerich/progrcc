#ifndef EXERC_CAP10_5_ADAPTADO_H
#define EXERC_CAP10_5_ADAPTADO_H

#define MAX_NOME            80
#define NUM_FUNCIONARIOS    18
#define SAL_MINIMO          937.00
#define NOME_ARQUIVO        "/tmp/cadastro.bin"

struct Funcionario {
    // Informacoes cadastradas
    char nome[MAX_NOME+1];  // preve um espaco adicional para o '\0'
    unsigned horas_trabalhadas;
    char turno;             // 'M', 'V' ou 'N'
    char categoria;         // 'O' ou 'G'

    // Informacoes computadas
    float valor_hora;
    float salario_base;
    float auxilio_alimentacao;
    float salario_final;
};

#endif // EXERC_CAP10_5_ADAPTADO_H
