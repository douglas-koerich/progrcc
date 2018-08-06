#include <stdio.h>
#include <math.h>
#include "trabalho.h"

bool movimento_ok_executa(int numero) {
    // Localiza o numero na placa
    int ln = 0, cn;
    bool achei = false;
    while (ln < TAMANHO) {
        cn = 0;
        while (cn < TAMANHO) {
            if (placa_jogo[ln][cn] == numero) {
                achei = true;
                break;
            }
            else {
                ++cn;
            }
        }
        if (achei == false) {
            ++ln;
        }
        else {
            break;
        }
    }
    // Localiza o espaco na placa
    int l0 = 0, c0;
    achei = false;
    while (l0 < TAMANHO) {
        c0 = 0;
        while (c0 < TAMANHO) {
            if (placa_jogo[l0][c0] == 0) {
                achei = true;
                break;
            }
            else {
                ++c0;
            }
        }
        if (achei == false) {
            ++l0;
        }
        else {
            break;
        }
    }
    bool ok = false;
    if (ln == l0) {
        ok = abs(cn-c0) == 1;
    }
    else if (cn == c0) {
        ok = abs(ln-l0) == 1;
    }
    if (ok == true) {
        placa_jogo[l0][c0] = numero;
        placa_jogo[ln][cn] = 0;
        ++contador_movimentos;
    }
    return ok;
}
