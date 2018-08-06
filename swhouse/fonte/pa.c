int pa_termo_n(int a1, int r, int n) {
    int an;
    an = a1 + (n - 1) * r;
    return an;
}

int pa_soma_n(int a1, int an, int n) {
    return (a1 + an) * n / 2;
}
