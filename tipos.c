#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    bool b = true; // declaracao com inicializacao
    bool b_;       // declaracao sem inicializacao (valor inicial INCERTO!)
    bool b1 = false, b2; // duas declaracoes do mesmo tipo, sendo uma inicializada
    
    b_ = b; // atribuicao de variavel (copia de uma para outra)
    b = false; // idem (copia de uma constante para a variavel)
    
    char letra, AlgarismoDecimal;
    letra = 'G'; // constante char eh representada pelo simbolo entre aspas simples
    AlgarismoDecimal = '1';
    
    int positivo = 2, negativo;
    negativo = -10;
    
    unsigned num1 = 2, num2 = -2; // num2 *NAO* vai ter o valor -2 pois eh sem sinal
    
    float pi = 3.1416F; // A constante 3.1416 eh do tipo double (haveria uma conversao)
    double e;
    e = 2.718281828;
    float avogadro = 6.023e+23; // Notacao cientifica: 6.023 x 10^23
    double PIB_2016 = -1.7; // Numero real negativo
    
    return EXIT_SUCCESS;
}

