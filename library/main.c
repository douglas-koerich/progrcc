#include <stdlib.h> // <> para arquivos-cabecalhos do sistema operacional
#include <stdio.h>
#include "an_comb.h"    // "" para arquivos-cabecalhos do proprio programa
#include "pa_pg.h"

int main(void) {
    // Para demonstracao, vamos simplesmente exercitar as funcoes
    // disponibilizadas pelos outros arquivos-fontes
    printf("Digite o primeiro termo em ambas P.A. e P.G.: ");
    int primeiro;
    scanf("%d", &primeiro);
    printf("Digite a razao de ambas P.A. e P.G.: ");
    int razao;
    scanf("%d", &razao);
    printf("Quantos termos essas series terao? ");
    size_t numero_termos;
    scanf("%zd", &numero_termos);

    int n_esimo_pa = termo_geral_pa(primeiro, razao, numero_termos);
    int soma_pa = soma_n_termos_pa(primeiro, n_esimo_pa, numero_termos);
    printf("P.A.: n_esimo = %d, soma = %d.\n", n_esimo_pa, soma_pa);

    int n_esimo_pg = termo_geral_pg(primeiro, razao, numero_termos);
    int soma_pg = soma_n_termos_pg(primeiro, razao, numero_termos);
    printf("P.G.: n_esimo = %d, soma = %d.\n", n_esimo_pg, soma_pg);

    printf("Digite o numero de elementos do conjunto (n): ");
    int num_elementos;
    scanf("%d", &num_elementos);
    printf("Digite o numero de elementos num agrupamento (p): ");
    int tam_grupo;
    scanf("%d", &tam_grupo);
    int perm = permutacao(num_elementos);
    int arr = arranjo(num_elementos, tam_grupo);
    int comb = combinacao(num_elementos, tam_grupo);
    printf("P(n) = %d, A(n,p) = %d, C(n,p) = %d.\n", perm, arr, comb);

    return EXIT_SUCCESS;
}
