/* Sabe-se que
 * a) 1 peh = 12 polegadas
 * b) 1 jarda = 3 pehs
 * c) 1 milha = 1760 jardas
 * Faca uma FUNCAO que receba uma medida em jardas, faca as conversoes
 * e devolva os valores em polegadas E em milhas.
 */

#include <stdlib.h>
#include <stdio.h>

void converte(float, // passagem por valor (copia da variavel)
              float*, float*);  // passagens por endereco (copia do ponteiro)

int main(void) {
    float jardas;
    printf("Digite o valor da distancia em jardas: ");
    scanf("%f", &jardas);

    float polegadas, milhas;
    converte(jardas, &polegadas, &milhas); // passa os enderecos para escrita nos seus conteudos

    printf("A medida correspondente em polegadas eh %f e em milhas eh %f.\n", polegadas, milhas);

    return EXIT_SUCCESS;
}

void converte(float jardas, float* pPolegadas, float* pMilhas) {
    // Embora seja completamente desnecessario neste exemplo, eh boa
    // pratica testar se o(s) ponteiro(s) recebido(s) eh(sao) nulo(s)
    if (pPolegadas == NULL || pMilhas == NULL) {
        return;
    }
    float pehs = jardas * 3;
    *pPolegadas = pehs * 12;
    *pMilhas = jardas / 1760;
}
