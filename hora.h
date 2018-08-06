#ifndef HORA_H
#define HORA_H

// Definicao do meu registro de tempo ("estampa de tempo")
struct hora {
    int hora;
    int minuto;
    int segundo;
};
typedef struct hora Hora;   // evita o uso da expressao "struct hora" na declaracao
                            // das variaveis

#endif
