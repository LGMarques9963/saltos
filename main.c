#include <string.h>
#include <stdio.h>

int f(int n, char *p, int tresMetros) {
    // printf("%d %c %d\n", n, p[n], tresMetros);
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return f(n - 1, p, 0) + f(n - 2, p, 0) + f(n - 3, p, 1);
    if (tresMetros == 1) return f(n - 1, p, 0) + f(n - 2, p, 0);
}

int main(int argc, char *argv[]) {
    char *p = argv[1];
    int n = strlen(p) - 1;
    printf("%d\n", f(n, p, 0));
    return 0;
}