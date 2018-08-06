#include <stdio.h>

int main() {
    // Variaveis de entrada
    int matricula;
    float cr;
    int ano_atual;

    // Variaveis contadoras, ja inicializadas
    int total = 0, letras = 0, matematica = 0, biologia = 0,
        vestibular = 0, transferencia = 0, enem = 0, alunos_do_ano = 0,
        cr7_5 = 0;

    // Variaveis para calculo do percentual dos cursos
    float pletras, pmatem, pbio;

    // Variaveis de maior e menor CR do ano
    float maior_cr = 0.0, menor_cr = 0.0;

    // Variavel do CR medio do ano
    float cr_medio = 0.0;

    // Apenas uma vez (como diz o enunciado): leitura do ano atual
    printf("Digite o ano em que estamos (AA): ");
    scanf("%d", &ano_atual);

    // Agora entra no laco de leitura ATE (do-while) que a matricula seja -1
    do {
        printf("Digite a matricula do aluno (aaaabcdee): ");
        scanf("%d", &matricula);

        // Nao faz sentido (e eh um erro) continuar se digitou -1
        if (matricula != -1) {
            ++total;    // mais um aluno pra estatistica

            printf("Digite o CR: ");
            scanf("%f", &cr);

            // Extracao dos campos do numero da matricula
            int aluno = matricula / 100000; // tira os 5 ultimos (bcdee)
            matricula %= 100000;    // fica com os 5 ultimos pra continuar
            int curso = matricula / 10000;  // tira os 4 ultimos (cdee), fica b
            matricula %= 10000;
            int ingresso = matricula / 1000; // fica c, tira o resto (dee)
            matricula %= 1000;
            int semestre = matricula / 100;
            int ano_ingresso = matricula % 100;

            // Agora que tem todos os dados do aluno, faz a contabilidade dele
            // Letra (a)
            if (curso == 1) ++letras;
            else if (curso == 2) ++matematica;
            else ++biologia;

            // Letra (e)
            if (ingresso == 1) ++vestibular;
            else if (ingresso == 2) ++transferencia;
            else ++enem;

            // Proximos calculos (letras b/c/d) soh valem se for aluno deste ano
            if (ano_ingresso == ano_atual) {
                ++alunos_do_ano;
                if (cr >= 7.5) ++cr7_5;
                cr_medio += cr; // soma para media depois do laco

                // Se eh o primeiro aluno deste ano, nao tem historico de outros
                if (alunos_do_ano == 1) {
                    menor_cr = maior_cr = cr;   // este cr vai ser a referencia
                }
                else {
                    if (cr > maior_cr) maior_cr = cr;   // atualiza se maior
                    if (cr < menor_cr) menor_cr = cr;   // atualiza se menor
                }
            }
        }
    } while (matricula != -1);

    // Atencao! O enunciado pedia que se cuidasse para totais zerados (porque
    // nao se pode usa-los como denominadores!)
    if (total == 0) {
        pletras = pmatem = pbio = cr_medio = 0.0;   // nao ha como calcular
    }
    else {
        pletras = letras * 100.0 / total;   // calculo da percentagem de letras
        pmatem = matematica * 100.0 / total;
        pbio = biologia * 100.0 / total;

        // O CR medio depende ter havido alunos neste ano
        if (alunos_do_ano == 0) {
            cr_medio = 0.0;
        }
        else {
            cr_medio /= alunos_do_ano;  // calculo da media (soma/num_alunos)
        }
    }
    printf("Dados dos cursos:\n");
    printf("Letras = %d (%.1f%%)\n", letras, pletras);
    printf("Matematica = %d (%.1f%%)\n", matematica, pmatem);
    printf("Biologia = %d (%.1f%%)\n", biologia, pbio);

    printf("\nFormas de ingresso:\n");
    printf("Vestibular = %d\n", vestibular);
    printf("Transferencia = %d\n", transferencia);
    printf("ENEM = %d\n", enem);

    printf("\nDados do ano atual:\n");
    printf("Num. de alunos com CR maior/igual a 7.5 = %d\n", cr7_5);
    printf("CR medio = %.1f\n", cr_medio);
    printf("Maior CR = %.1f\n", maior_cr);
    printf("Menor CR = %.1f\n", menor_cr);

    return 0;
}
