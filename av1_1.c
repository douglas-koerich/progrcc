#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int num_operario, pecas_operario;
    char sexo_operario;
    float salario_operario;

    int pecas_acima_30, total_pecas = 0, total_pecas_Ah = 0, num_Ah = 0,
        total_pecas_Bh = 0, num_Bh = 0, total_pecas_Ch = 0, num_Ch = 0,
        total_pecas_Am = 0, num_Am = 0, total_pecas_Bm = 0, num_Bm = 0,
        total_pecas_Cm = 0, num_Cm = 0, num_maior_operario;
    float total_folha = 0.0, maior_salario = 0.0, salario_minimo = 1000.0,
          media_Ah, media_Bh, media_Ch, media_Am, media_Bm, media_Cm;

    do {
        printf("Digite o numero do(a) operario(a): ");
        scanf("%d", &num_operario);
        if (num_operario != 0) {
            printf("Sexo do operario (M/F): ");
            scanf(" %c", &sexo_operario);
            printf("Numero de pecas fabricadas: ");
            scanf("%d", &pecas_operario);
            if (pecas_operario <= 30) {
                salario_operario = salario_minimo;
                if (sexo_operario == 'M') {
                    total_pecas_Ah += pecas_operario;
                    ++num_Ah;
                } else {
                    total_pecas_Am += pecas_operario;
                    ++num_Am;
                }
            } else {
                pecas_acima_30 = 30 - pecas_operario;
                if (pecas_operario >= 31 && pecas_operario <= 35) {
                    salario_operario = salario_minimo +
                                       (salario_minimo * 3.0/100 * pecas_acima_30);
                    if (sexo_operario == 'M') {
                        total_pecas_Bh += pecas_operario;
                        ++num_Bh;
                    } else {
                        total_pecas_Bm += pecas_operario;
                        ++num_Bm;
                    }
                } else {
                    salario_operario = salario_minimo +
                                       (salario_minimo * 0.05 * pecas_acima_30);
                    if (sexo_operario == 'M') {
                        total_pecas_Ch += pecas_operario;
                        ++num_Ch;
                    } else {
                        total_pecas_Cm += pecas_operario;
                        ++num_Cm;
                    }
                }
            }
            total_pecas += pecas_operario;
            total_folha += salario_operario;
            printf("Salario do operario %d: R$ %.2f.\n", num_operario, salario_operario);
            if (salario_operario > maior_salario) {
                maior_salario = salario_operario;
                num_maior_operario = num_operario;
            }
        }
    } while (num_operario != 0);
    media_Ah = total_pecas_Ah / num_Ah;
    media_Bh = total_pecas_Bh / num_Bh;
    media_Ch = total_pecas_Ch / num_Ch;
    media_Am = total_pecas_Am / num_Am;
    media_Bm = total_pecas_Bm / num_Bm;
    media_Cm = total_pecas_Cm / num_Cm;
    printf("a) Total da folha de pagamento do mes: R$ %.2f;\n", total_folha);
    printf("b) Numero total de pecas do mes: %d;\n", total_pecas);
    printf("c) Media de pecas fabricadas pelos homens: A=%.1f, B=%.1f, C=%.1f;\n",
           media_Ah, media_Bh, media_Ch);
    printf("d) Media de pecas fabricadas pelas mulheres: A=%.1f, B=%.1f, C=%.1f;\n",
           media_Am, media_Bm, media_Cm);
    printf("e) O maior salario foi recebido pelo(a) operario(a) %d.\n",
           num_maior_operario);
    return EXIT_SUCCESS;
}
