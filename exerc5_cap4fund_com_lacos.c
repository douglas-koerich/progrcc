#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h> // este include soh eh valido em Linux
#include <math.h>

int main() {
    int num1, num2, escolha;

    printf("Digite o 1o. numero: ");
    scanf("%d", &num1);
    printf("Digite o 2o. numero: ");
    scanf("%d", &num2);

    // Repita a entrada da escolha enquanto ela nao for valida
    do {
        printf("Qual operacao deseja realizar (1-4)? ");

        // Elimina quaisquer "sujeiras" deixadas no buffer do teclado
        // (p.ex. pela passagem anterior do laco nesta mesma leitura
        __fpurge(stdin); // soh em Linux; se fosse em Windows seria:
                         // fflush(stdin) que eh disponivel pelo stdio.h
                         //
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 4);

    switch (escolha) {
        case 1: {
            double media;
            media = (num1 + num2) / 2.0; // usa constante real para forcar
                                         // uma divisao real
            printf("A media dos numeros eh %lf.\n", media);
            break;

            // A variavel 'media' eh DESTRUIDA ao sair do
            // bloco {} deste case
        }
        case 2: {
            int diff;
            /*
            if (num1 > num2) {
                diff = num1 - num2;
            } else {
                diff = num2 - num1;
            }
            */
            // diff = abs(num1 - num2); // nao importando quem eh maior

            // Operador ternario de decisao (equivalente ao if-else acima)
            diff = (num1 > num2)? num1 - num2: num2 - num1;
            printf("A diferenca entre os numeros eh %d.\n", diff);
            break;
        }
        case 3: {
            // Vamos fazer a multiplicacao como uma repeticao de somas
            int contador = 1;
            int produto = 0;
            // Se num2 for negativo, nao posso comparar com o valor direto
            // pois o primeiro teste jah resultaria 'false'
            while (contador <= abs(num2)) {
                produto += num1; // produto = produto + num1;
                ++contador; // contador += 1; ou, contador = contador + 1
            }
            if (num2 < 0) { // inverte o sinal se o multiplicador for negativo
                produto = -produto;
            }
            printf("O produto entre os numeros eh %d.\n", produto);
            break;
        }

        case 4:
            if (num2 == 0) {
                printf("A divisao nao pode ser feita!\n");
            } else {
                double quoc = (double) num1 / num2; // divisao real, SEM resto!
                printf("A divisao entre os numeros eh %lf.\n", quoc);
            }
            // nao precisa do 'break' para a ultima clausula do switch
    }
    return EXIT_SUCCESS;
}

