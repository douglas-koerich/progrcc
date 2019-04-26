#include <stdlib.h>
#include <stdio.h>

#define NUM_OBJETOS 10  // nao tem ponto-e-virgula em #define!

int main(void) {
    float precos_unitarios[NUM_OBJETOS];
    int obj;
    for (obj=0; obj<NUM_OBJETOS; ++obj) {   // preenchimento de vetor eh feito com
        printf("Valor unitario: ");         // (a) inicializacao (nao eh o caso aqui)
        scanf("%f", &precos_unitarios[obj]);// (b) laco de atribuicao ou scanf a cada posicao
    }
    int qtdes_vendidas[NUM_OBJETOS];
    for (obj=0; obj<NUM_OBJETOS; ++obj) {
        printf("Qtde. vendida: ");
        scanf("%d", &qtdes_vendidas[obj]);
    }
    printf("*** RELATORIO DE VENDAS ***\n");
    float total_geral = 0.0;
    int indice_mais_vendido = 0, qtde_mais_vendida = 0;
    for (obj=0; obj<NUM_OBJETOS; ++obj) {
        if (qtdes_vendidas[obj] > qtde_mais_vendida) {
            indice_mais_vendido = obj;
            qtde_mais_vendida = qtdes_vendidas[obj];
        }
        printf("Obj no. %2d--> %d un. x R$ %.2f = ", obj+1,
               qtdes_vendidas[obj], precos_unitarios[obj]);
        float total = qtdes_vendidas[obj] * precos_unitarios[obj];
        printf("R$ %.2f\n", total);
        total_geral += total;
    }
    printf("***************************\n");
    printf("Total geral: R$ %.2f\n", total_geral);
    printf("Comissao paga (salario + perc. vendas): R$ %.2f\n",
           545.0 + total_geral * 0.05);
    printf("O objeto mais vendido estah na posicao %d e seu valor unitario eh R$ %.2f\n",
           indice_mais_vendido, precos_unitarios[indice_mais_vendido]);

    return EXIT_SUCCESS;
}

