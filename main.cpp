#include <string>
#include <iostream>
#include <map>
using namespace std;

int f_rec(int n, string p, int tresMetros) {
    // cout << n << " " << p[n] << " " << tresMetros << endl;
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return f_rec(n - 1, p, 0) + f_rec(n - 2, p, 0) + f_rec(n - 3, p, 1);
    if (tresMetros == 1) return f_rec(n - 1, p, 0) + f_rec(n - 2, p, 0);
}

int f_memo(int n, string p, int tresMetros, map<string, int> &memo) {
    string key = to_string(n) + to_string(tresMetros);
    if (memo.find(key) != memo.end()) return memo[key];
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return memo[key] = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo) + f_memo(n - 3, p, 1, memo);
    if (tresMetros == 1) return memo[key] = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo);
}

int main(int argc, char *argv[]) {
    string p = argv[1];
    int n = p.length() - 1;
    cout << "Recursão Simples: " << f_rec(n, p, 0) << endl;
    map<string, int> memo;
    cout << "Recursão com Memoização: " << f_memo(n, p, 0, memo) << endl;
    return 0;
}