#include <stdio.h>
#include <math.h>

double calculaIntegral(int, int, int);    // prototipo ("declaracao") da funcao

int main() {
    int n;      // numero de trapezios a serem usados na aproximacao
    double pi;   // valor de PI calculado com base na formula do enunciado

    // Leitura da variavel de entrada
    printf("Digite o numero de aproximacoes (n): ");
    scanf("%d", &n);

    const int a = 0;    // da formula da integral que calcula PI
    const int z = 1;    // idem

    double I = calculaIntegral(a, z, n);
    pi = 4 * I;

    printf("O valor aproximado de PI eh %.10lf\n", pi);

    return 0;
}

// Definicao (codigo) da funcao
double calculaIntegral(int a, int b, int n) {
    // A funcao que sera usada para obter o 'y' correspondente ao 'x' eh
    // y = f(x) = 1 / (1+x^2)

    double A;        // area do trapezio "da vez"
    double S = 0.0;  // somatorio das areas dos trapezios (aproximacao da
                    // integral)

    double xesq, xdir, yesq, ydir;
    double delta_x = (b-a)/ (double) n; // cast senao vai ser divisao inteira

    int t;  // contador de trapezios
    for (t=1, xesq=a; t<=n; ++t, xesq+=delta_x) {  // para 'n' trapezios...
        xdir = xesq + delta_x;              // atualiza xdir com base no novo xesq
                                            // (desse passo)
        yesq = 1 / (1 + pow(xesq, 2));      // calcula os y's correspondentes
        ydir = 1 / (1 + pow(xdir, 2));
        A = (ydir + yesq) / 2 * delta_x;    // calcula a area para este trapezio
        S += A;                             // soma esta area no total de areas
    }

    return S;   // devolve o valor calculado dentro desta funcao para o algoritmo
                // (funcao) que me chamou
}

