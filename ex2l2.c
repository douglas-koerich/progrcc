#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned DS, D, M, A, S;
    printf("Digite a data na forma D/M/A: ");
    scanf("%d/%d/%d", &D, &M, &A); // evite fazer dessa forma, a nao ser que
                                   // voce confie bastante no seu usuario!

    if (M < 3) { // se o mes for janeiro ou fevereiro
        M += 10; // janeiro: 1->11; fevereiro: 2->12...
        --A;     // ... do ano anterior (precedente)
    } else {
        M -= 2;  // marco: 3->1; abril: 4->2; ... dezembro: 12->10
    }
    unsigned truncada = 2.6 * M - 0.1; // float pra int TRUNCA o valor
    S = A / 100; // divisao inteira, fica com os dois primeiros numeros em S
    A %= 100;    // A fica com os dois ultimos numeros (o resto do seculo)

    unsigned QA = A / 4;
    unsigned QS = S / 4;

    DS = (truncada + D + A + QA + QS - 2 * S) % 7;

    switch (DS) {
        case 0: puts("Dom"); break;
        case 1: puts("Seg"); break;
        case 2: puts("Ter"); break;
        case 3: puts("Qua"); break;
        case 4: puts("Qui"); break;
        case 5: puts("Sex"); break;
        case 6: puts("Sab"); break;
        default: puts("???");
    }

    return EXIT_SUCCESS;
}

