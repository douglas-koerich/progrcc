float calcula_media(float n1, float n2, float n3, char l) {
    float m;
    if (l == 'A') {
        m = (n1 + n2 + n3) / 3;
    } else if (l == 'P') {
        m = (5*n1 + 3*n2 + 2*n3) / (5+3+2);
    } else { // BONUS: caso a opcao seja invalida
        m = 0.0;
    }
    return m;
}

