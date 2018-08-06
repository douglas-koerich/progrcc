#include <stdlib.h>
#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media /*parcial*/;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("Media obtida: %.1f.\n", media);

    if (media >= 0.0 && media < 3.0) {
        printf("Reprovado.\n");
    } else {
        if (media >= 3 && media < 7.0) {
            printf("Exame.\n");
            float nota_exame;   // Variavel LOCAL ao bloco desse 'if'
            nota_exame = 12.0 - media;
            printf("Deve tirar nota %.1f para ser aprovado.\n", nota_exame);
            /*
            printf("Digite a nota obtida no exame: ");
            float exame;
            scanf("%f", &exame);

            float media_final = (media + exame) / 2;
            if (media_final >= 6.0) {
                printf("Aprovado por exame.\n");
            } else {
                printf("Reprovado por exame.\n");
            }
            */
        } else {
            printf("Aprovado.\n");
        }
    }
    return EXIT_SUCCESS;
}
