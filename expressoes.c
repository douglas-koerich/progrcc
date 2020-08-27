/*
Soma: +
Subtracao: -
Multiplicacao: *
Divisao(!): /  --> operandos inteiros --> DIVISAO INTEIRA 5 / 2 = 2
               --> um dos operandos real --> DIVISAO REAL 5 / 2.0 = 2.5
Resto da DIVISAO INTEIRA: 5 % 2 = 1

CASOS ESPECIAIS:
    a = a + b;  -->  a += b;
    c = c - d;  -->  c -= d;  (CUIDADO! c = d - c nao pode ser feito da mesma forma)
    x = x * y;  -->  x *= y;
    z = z / w;  -->  z /= w;  (nao para z = w / z)
    m = m % n;  -->  m %= n;  (nao para m = n / m)

CASOS MAIS QUE ESPECIAIS:
    x = x + 1;  -->  x += 1;  --> x++; (ou ++x;)
    y = y - 1;  -->  y -= 1;  --> y--; (ou --y;)

Potenciacao: pow(5, 2) = 25  |_  #include <math.h>
Raiz quadrada: sqrt(9) = 3   |

PRECEDENCIA:
    a = b * c + d; --> b*c executado primeiro, depois somado com d
    a = b * (c + d); --> agora a soma eh feita antes

    x = y * (z - w / (v + u)); --> aninhamento de precedencias com parenteses   
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int val1, val2;
    
    printf("Digite o primeiro valor: ");
    scanf("%d", &val1);

    printf("Digite o segundo valor: ");
    scanf("%d", &val2);

    int soma;
    soma = val1 + val2;
    printf("A soma dos valores eh %d\n", soma);

    int subtracao = val1 - val2;
    printf("A subtracao do primeiro pelo segundo eh %d\n", subtracao);

    printf("O produto dos valores eh %d\n", val1 * val2);

    printf("O primeiro dividido pelo segundo resulta em %d (div. inteira)\n", val1 / val2);
    printf("O primeiro dividido pelo segundo resulta em %.2f (div. real)\n", (float) val1 / val2);

    int potencia = pow(val1, val2);
    printf("O primeiro elevado a potencia do segundo eh %d\n", potencia);

    float raiz = sqrt(val2);
    printf("A raiz quadrada do segundo valor eh %f\n", raiz);

    return EXIT_SUCCESS;
}