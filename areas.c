#include <stdlib.h>
#include <stdio.h>

// Declaracao das funcoes, i.e., seus PROTOTIPOS (sem bloco de codigo, terminados com ;)
int calculaAreaRetangulo(int, int); // nao precisa por o nome dos argumentos (ex. lado1 e lado2)
float calculaAreaCirculo(int);
double calculaAreaTriangulo(double, double);
float calculaAreaTrapezio(float base_menor, float base_maior, float altura);    // explicitar o nome dos argumentos
                                                                                // ajuda a nao trocar a ordem deles
void imprimeValorArea(double);  // se tipos NUMERICOS de diferentes tamanhos podem ser passados, define como sendo o maior deles
                                // isso eh possivel porque C converte entre tipos numericos, mas nao entre outros tipos

void imprimeValorArea(double area) {    // essa funcao tem uma categoria especial, chamada de "procedimento"
                                        // 'area', sendo um argumento da funcao, eh tambem uma variavel LOCAL da mesma
    printf("A area da figura geometrica vale %lf\n", area);
}

int main(void) {    // A funcao 'main' NAO recebe argumentos (lista "void") e devolve/retorna um inteiro (EXIT_SUCCESS=0)
    int l1, l2;
    printf("Digite o comprimento de um dos lados do retangulo: ");
    scanf("%d", &l1);
    printf("Agora, digite o comprimento do outro lado: ");
    scanf("%d", &l2);
    int area = calculaAreaRetangulo(l1, l2);
    // printf("A area do retangulo vale %d\n", area);
    imprimeValorArea(area);

    int r;
    printf("Digite o raio da circunferencia: ");
    scanf("%d", &r);
    float a = calculaAreaCirculo(r);
    // printf("A area do circulo vale %f\n", a);
    imprimeValorArea(a);

    double base_t, altura_t;
    printf("Digite a base do triangulo: ");
    scanf("%lf", &base_t);
    printf("Digite a altura do triangulo: ");
    scanf("%lf", &altura_t);
    // printf("A area do triangulo vale %lf\n", calculaAreaTriangulo(base_t, altura_t));   // imprime o retorno da funcao
    imprimeValorArea(calculaAreaTriangulo(base_t, altura_t));   // retorno do calculo eh passado como argumento pra impressao

    float base_m, base_M, altura;
    printf("Digite a base menor do trapezio: ");
    scanf("%f", &base_m);
    printf("Digite a base MAIOR do trapezio: ");
    scanf("%f", &base_M);
    printf("Digite a altura do trapezio: ");
    scanf("%f", &altura);
    a = calculaAreaTrapezio(base_m, base_M, altura);
    // printf("A area do trapezio vale %f\n", a);
    imprimeValorArea(a);

    return EXIT_SUCCESS;
}

int calculaAreaRetangulo(int lado1, int lado2) { // nao pode ser (int lado1, lado2)
    int area;   // variavel LOCAL de retorno (existe e eh visivel somente dentro desta funcao)
    area = lado1 * lado2;
    return area;
}

float calculaAreaCirculo(int raio) {
    float area; // nenhuma relacao com as outras variaveis 'area' existentes fora desta funcao
    area = 3.14159265359F * raio * raio;
    return area;
}

double calculaAreaTriangulo(double base, double altura) {
    return base * altura / 2;   // eh possivel retornar o resultado de uma expressao
}

float calculaAreaTrapezio(float base_menor, float base_maior, float altura) {
    float area = (base_menor + base_maior) * altura / 2;
    return area;
}

