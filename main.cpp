#include <string>
#include <iostream>
using namespace std;

int f(int n, string p, int tresMetros) {
    // cout << n << " " << p[n] << " " << tresMetros << endl;
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return f(n - 1, p, 0) + f(n - 2, p, 0) + f(n - 3, p, 1);
    if (tresMetros == 1) return f(n - 1, p, 0) + f(n - 2, p, 0);
}

int main(int argc, char *argv[]) {
    string p = argv[1];
    int n = p.length() - 1;
    cout << f(n, p, 0) << endl;
    return 0;
}