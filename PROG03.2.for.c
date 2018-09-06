#include <stdlib.h>
#include <stdio.h>

int main() {
    int qtde_valores;
    printf("Quantos valores serao lidos? ");
    scanf("%d", &qtde_valores);

    int contador; // declaracao antes do for
    unsigned maior, menor;
    float soma, media;

    for (contador = 1; contador <= qtde_valores; ++contador) {
        unsigned valor;
        printf("Digite um valor: ");
        scanf("%u", &valor);

        if (contador == 1) {
            // Nao ha memoria ainda de maior e menor
            maior = menor = valor; // ambos iguais ao valor
        } else {
            if (valor > maior) {
                maior = valor;  // atualiza memoria do maior
            }
            if (valor < menor) {
                menor = valor;  // idem para o menor
            }
        }
        soma += valor; // acumula na soma o novo valor

        // A variavel 'valor' eh DESTRUIDA na memoria ao fim do laco
        // (ela NAO ARMAZENA o seu conteudo do passo anterior)
    }
    // Fora do laco, ao concluir a leitura dos numeros,
    // estah pronto para calcular a media
    media = soma / qtde_valores;

    printf("O maior valor eh %u e o menor eh %u.\n", maior, menor);
    printf("A media dos valores eh %f.\n", media);

    return EXIT_SUCCESS;
}

