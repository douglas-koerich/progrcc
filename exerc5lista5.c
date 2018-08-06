#include <stdlib.h> // size_t
#include <stdio.h>

void imprimeVetor(int [*], size_t);
// ou: void imprimeVetor(int [], size_t)
size_t removeNumero(int [*], size_t, int);

int main() {
    // Vetor de tamanho variavel: usuario escolhe o tamanho do vetor
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    // Preenche o vetor com numeros digitados pelo usuario
    // Se o usuario digitar -1, interrompe o preenchimento (nesse caso,
    // nao preenche ateh o final, por isso precisamos de um contador
    // de posicoes efetivamente ocupadas no vetor)
    int indice, contador;
    for (indice=contador=0; indice<tamanho; ++indice) {
        printf("Digite o valor para a posicao %d: ", indice);
        scanf("%d", &vetor[indice]);
        if (vetor[indice] == -1) {
            break;  // sai do laco de leitura
        }
        ++contador;
    }

    // Imprime o vetor com os valores digitados
    imprimeVetor(vetor, contador);  // note que nao percorre todo o vetor,
                                    // somente as posicoes preenchidas no
                                    // laco anterior

    // Pede o numero a ser removido
    int num;
    printf("Digite um numero para remover do vetor: ");
    scanf("%d", &num);

    // Remove do vetor todas as ocorrencias desse numero
    contador = removeNumero(vetor, contador, num);

    // Imprime o vetor atualizado
    imprimeVetor(vetor, contador);  // nao se usa [] na passagem do vetor como parametro

    return 0;
}

void imprimeVetor(int vet[], size_t tam) {  // aqui o colchetes eh obrigatoriamente vazio!
    int indice; // declara variavel local
    for (indice=0; indice<tam; ++indice) {
        printf("%d ", vet[indice]);
    }
    printf("\n");
}

size_t removeNumero(int v[], size_t t, int n) {
    int i;
    for (i=0; i<t; ++i) {
        if (n == v[i]) {
            int i2;   // variavel local ao bloco if, soh existe aqui dentro
            for (i2=i+1; i2<t; ++i2) {
                v[i2-1] = v[i2];
            }
            --t;
        }
    }
    // Devolve o novo tamanho do vetor
    return t;
}

