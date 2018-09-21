int fatorial(int n) {
    int f, i;
    for (f = 1, i = n; i >= 1; --i) {
        f = f * i;
    }
    return f;
}

