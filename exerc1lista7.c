#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exerc1lista7.h"

int main(int argc, char* argv[]) {
    // Vou receber o numero de funcionarios como um parametro da chamada do
    // programa; tambem vou receber o nome-base dos arquivos que vou gravar
    // Exemplo: $./a.out 10 teste
    // Vai ler um total de 10 funcionarios e gravar os registros nos arquivos
    // teste.txt e teste.bin
    if (argc != 3) {    // O nome do programa (./a.out) conta
        puts("Numero invalido de parametros");
        printf("Use: %s <num. de funcionarios> <nome do arquivo>\n", argv[0]);
        return -1;  // main() retorna ao sistema operacional com um codigo de erro
    }
    // Converte o argumento "numero de funcionarios" que vem da linha de comando
    // como uma string para uma variavel inteiro (pra ser usada no tamanho do
    // vetor)
    int num = atoi(argv[1]);    // argv[1] tem a string "10" no exemplo acima

    // Vou alocar estaticamente o vetor de funcionarios
    Funcionario vetor[num];

    // Abro/crio os arquivos texto e binario para salvar os registros a medida
    // que for lendo-os do teclado
    char nome_arquivo_texto[100];
    strcpy(nome_arquivo_texto, argv[2]);    // argv[2] tem a string "teste" no exemplo acima
    strcat(nome_arquivo_texto, ".txt");
    char nome_arquivo_binario[100];
    strcpy(nome_arquivo_binario, argv[2]);
    strcat(nome_arquivo_binario, ".bin");
    FILE* texto = fopen(nome_arquivo_texto, "w");
    if (texto == NULL) {
        perror("Erro ao criar arquivo-texto");
        return -1;
    }
    FILE* binario = fopen(nome_arquivo_binario, "wb");
    if (binario == NULL) {
        perror("Erro ao criar arquivo-binario");
        fclose(texto);  // nao deixa arquivo aberto
        return -1;
    }

    // Vamos preencher o vetor com as informacoes
    int i;
    for (i=0; i<num; ++i) {
        printf("Digite os dados do %do. funcionario:\n", i+1);
        printf("Codigo? "); scanf("%d", &vetor[i].codigo_func);
        printf("Salario-base? "); scanf("%f", &vetor[i].salario_base);
        printf("Total de vendas? "); scanf("%f", &((vetor+i)->total_vendas));

        // Aproveito a posicao do vetor onde estou (o registro do funcionario)
        // para fazer o calculo dos demais campos
        vetor[i].valor_comissao = vetor[i].total_vendas * 6 / 100;
        vetor[i].salario_liquido = vetor[i].salario_base + vetor[i].valor_comissao;

        // Tambem aproveito para salvar o registro nos dois arquivos
        fprintf(texto, "%d,%.2f,%.2f,%.2f,%.2f\n", vetor[i].codigo_func,
                vetor[i].salario_base, vetor[i].total_vendas, vetor[i].valor_comissao,
                vetor[i].salario_liquido);
        fwrite(&vetor[i], sizeof(Funcionario), 1, binario);
    }
    // Fecha arquivos assim que nao precisa mais acessa-los
    fclose(texto);
    fclose(binario);

    // Imprime a tabela e suas totalizacoes
    float base_total = 0.0, vendas_total = 0.0, comissao_total = 0.0, liquido_total = 0.0;
    puts("Funcionario | Bruto (R$) | Vendas (R$) | Comissao (R$) | Liquido (R$)");
    puts("------------+------------+-------------+---------------+-------------");
    for (i=0; i<num; ++i) {
        printf("%11d | %10.2f | %11.2f | %13.2f | %12.2f\n", vetor[i].codigo_func,
               vetor[i].salario_base, vetor[i].total_vendas, vetor[i].valor_comissao,
               vetor[i].salario_liquido);
        base_total += vetor[i].salario_base;
        vendas_total += vetor[i].total_vendas;
        comissao_total += vetor[i].valor_comissao;
        liquido_total += vetor[i].salario_liquido;
    }
    puts("------------+------------+-------------+---------------+-------------");
    printf("TOTAL       | %10.2f | %11.2f | %13.2f | %12.2f\n", base_total,
           vendas_total, comissao_total, liquido_total);

    // Recupera do arquivo o penultimo registro
    // Se a leitura do arquivo eh sequencial, como se sabe qual eh o penultimo?
    // Toda leitura de arquivo eh no sentido direto, nunca no inverso; em outras
    // palavras, eu preciso estar no "inicio" do penultimo registro no arquivo
    // Com arquivo-texto, isso eh muito dificil de implementar (precisa ter uma
    // memoria dos registros ao chegar no fim do arquivo)
    // Normalmente, quando alguma operacao desse tipo eh necessaria (solicitada
    // pelo cliente), usa-se um arquivo binario porque o tamanho de cada registro
    // nele eh fixo
    binario = fopen(nome_arquivo_binario, "rb");
    if (binario == NULL) {
        perror("Erro na abertura do arquivo binario");
        return -1;
    }
    // Quando um arquivo eh aberto, o "ponteiro" de leitura estah no inicio do
    // arquivo, pronto pra ler o primeiro registro
    // Vamos "saltar" esse "ponteiro" para o penultimo registro
    // Referencia: SEEK_END (fim do arquivo)
    // Deslocamento para tras (negativo), no tamanho de um registro
    // 2x porque vai "pular" para tras o conteudo do ultimo e do penultimo, para
    // ficar no inicio dos bytes deste
    if (fseek(binario, -2*sizeof(Funcionario), SEEK_END) < 0) {
        perror("Erro ao buscar penultimo registro");
        fclose(binario);
        return -1;
    }
    Funcionario rascunho;
    if (fread(&rascunho, sizeof(rascunho), 1, binario) < 1) {
        perror("Erro ao ler o registro do arquivo");
        fclose(binario);
        return -1;
    }
    printf("Penultimo registro: codigo = %d.\n", rascunho.codigo_func);
    fclose(binario);

    return 0;
}
