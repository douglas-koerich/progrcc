#include <stdio.h>
#include <ctype.h>

int main() {
    // Variaveis de entrada
    float preco;
    int categoria;
    char situacao;

    // Variaveis de saida
    float bruto, liquido, imposto;

    // Entrada de dados
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Digite a categoria (1/2/3): ");
    scanf("%d", &categoria);
    printf("Digite a situacao (R/N): ");
    scanf(" %c", &situacao);    // precisa do espaco pra limpar o buffer
                                // mas nao na prova escrita :-)
    situacao = toupper(situacao);   // nem essa linha era necessaria na prova

    // Letra (a)
    if (preco <= 25) {
        // Primeira forma de selecao possivel: usando escolha-caso
        switch (categoria) {
            case 1:
                bruto = preco + preco * 0.05;   // primeira formula possivel
                break;

            case 2:
                bruto = preco * (1 + 8 / 100.0); // segunda formula possivel
                break;

            default:
                bruto = preco * 1.10;           // terceira formula possivel
        }
    }
    else {
        // Uma outra forma de selecao possivel: escada if-else
        if (categoria == 1) {
            bruto = preco * 1.12;   // usando a terceira formula acima
        }
        else {
            if (categoria == 2) {
                bruto = preco * 1.15;
            }
            else {
                bruto = preco * 1.20;
            }
        }
    }
    printf("Novo preco bruto (com aumento): R$ %.2f\n", bruto);

    // Letra (b)
    if (categoria == 2 || situacao == 'R') {
        imposto = bruto * 0.05;
    }
    else {
        imposto = bruto * 0.08;
    }
    // ou: imposto = bruto * (categoria == 2 || situacao == 'R')? 0.05: 0.08;
    printf("Imposto a pagar: R$ %.2f\n", imposto);

    // Letra (c)
    liquido = bruto + imposto;
    printf("Novo preco liquido (com imposto): R$ %.2f\n", liquido);

    // Letra (d): aqui soh pode usar escada if-else (switch nao funciona aqui)
    if (liquido <= 50) {
        printf("Barato\n");
    }
    else {
        if (liquido >= 120) {
            printf("Caro\n");
        }
        else {
            printf("Normal\n");
        }
    }
    return 0;
}
