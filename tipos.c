#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h"  // definicoes dos registros (estruturas) com seus campos

int main(void) {
    // +++DECLARACAO+++ do registro (requer a inclusao do tipos.h)
    // struct produto var_prod;    // uma variavel nao inicializada do tipo 'struct produto'
    produto var_prod;              // usando o typedef que simplificou o nome

    // Preenchendo os campos dessa variavel (valores da variavel composta)
    var_prod.codigo = 10;
    strcpy(var_prod.descricao, "Creolina");
    var_prod.valor_compra = 2.50;
    var_prod.valor_venda = 3.50;
    var_prod.qtde_estoque[0] = 50;  // valor para a primeira posicao do campo-vetor
    var_prod.qtde_estoque[1] = 20;  // valor para a segunda posicao
    var_prod.qtde_estoque[2] = 5;   // idem para a terceira
    var_prod.vencimento.dia = 31;   // subcampo 'dia' do campo 'vencimento' (ponto extra)
    var_prod.vencimento.mes = 12;
    var_prod.vencimento.ano = 2020;

    // Variavel unitaria inicializada
    produto outro_prod = {  // pode ser numa unica linha, dividido aqui para facilitar...
        // Na ordem dos campos...
        15,         // codigo
        "Vaselina", // descricao
        10.00,      // ...
        12.70,
        { 60, 30, 12 }, // inicializacao do campo-vetor, como num vetor convencional
        { 1, 4, 2015 }  // inicializacao do/a registro/estrutura interno/a
    };

    // Vetor de 3 produtos (registros/estruturas) alocado estaticamente
    produto lista_produtos[3];
    int i;
    for (i=0; i<3; ++i) {
        printf("---Dados do %do. produto:\n", i+1);
        printf("Digite o codigo: ");
        scanf("%d", &lista_produtos[i].codigo);
        printf("Informe a descricao: ");
        scanf(" %s", lista_produtos[i].descricao);
        printf("Valores de compra e venda: ");
        scanf("%f %f", &lista_produtos[i].valor_compra, &lista_produtos[i].valor_venda);
        int j;
        for (j=0; j<LOJAS; ++j) {
            printf("Digite a qtde. em estoque na loja #%d: ", j+1);
            scanf("%u", &lista_produtos[i].qtde_estoque[j]);
        }
        printf("Digite a data de vencimento, no formato d/m/a: ");
        scanf("%d/%d/%d", &lista_produtos[i].vencimento.dia, &lista_produtos[i].vencimento.mes,
              &lista_produtos[i].vencimento.ano);
    }

    // Vetor de 2 produtos (registros/estruturas) alocado dinamicamente
    produto* vetor_produtos = (produto*) malloc(2 * sizeof(produto));
    produto* ponteiro_nav = vetor_produtos; // ponteiro pra navegar no vetor (apontando para cada registro)
    for (i=0; i<2; ++i) {
        printf("---Dados do %do. produto:\n", i+1);
        printf("Digite o codigo: ");
        scanf("%d", &vetor_produtos[i].codigo); // sem usar o ponteiro de navegacao
        printf("Informe a descricao: ");
        scanf(" %s", vetor_produtos[i].descricao);
        printf("Valores de compra e venda: ");
        scanf("%f %f", &(*ponteiro_nav).valor_compra, &(*ponteiro_nav).valor_venda);    // resolvendo o ponteiro com * pra obter o registro
        int j;
        for (j=0; j<LOJAS; ++j) {
            printf("Digite a qtde. em estoque na loja #%d: ", j+1);
            scanf("%u", &ponteiro_nav->qtde_estoque[j]);    // (*p).campo eh o mesmo que p->campo
        }
        printf("Digite a data de vencimento, no formato d/m/a: ");
        scanf("%d/%d/%d", &(vetor_produtos+i)->vencimento.dia, &(vetor_produtos+i)->vencimento.mes,
              &(vetor_produtos+i).vencimento.ano);

        ++ponteiro_nav; // o endereco eh somado com o tamanho TOTAL do registro (em bytes)
                        // ("pula" para o proximo registro no vetor)
    }
    free(vetor_produtos);

    return EXIT_SUCCESS;
}
