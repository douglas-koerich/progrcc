#ifndef PESSOA_H
#define PESSOA_H

// DEFINICAO de um novo tipo-registro
struct person {
    // Campos (propriedades) do registro
    float altura;
    char sexo;

    // Campos em sequencia que forem do mesmo tipo podem ser combinados
    // com virgula(s)
    float peso, peso_ideal, imc;
}; // Termina com ponto-e-virgula!

// Em arquivos-cabecalhos tambem se definem prototipos de funcoes (associadas
// ao tipo, nesse caso)
float calcula_imc(float, float);

#endif // PESSOA_H

