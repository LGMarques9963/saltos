#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int f_rec(int n, string p, int tresMetros) {
    /**
        Input:
            n: tamanho da string p
            p: string que representa as posições das pedras
            tresMetros: flag que indica se o último movimento foi de 3 metros
        Output:
            quantidade de caminhos possíveis para chegar na posição n

        A recursão para resolver o problema é feita da seguinte forma:
            n é a posição atual, onde a margem inicial fica na posição 0 e a margem final na posição n
            f(n) é a quantidade de caminhos possíveis para chegar na margem final
            p é a string recebida por input, onde p[i] = 0 significa que não há pedra, portanto não é possível passar na posição i
            tresMetros é uma flag que indica se o último movimento foi de 3 metros

        Se n < 0, então não há caminho possível
        Se n = 0, então há um único caminho possível
        Se p[n] = 0, então não é possível passar na posição n
        f(n, 0) = f(n - 1, 0) + f(n - 2, 0) + f(n - 3, 1) se tresMetros = 0
        f(n, 1) = f(n - 1, 0) + f(n - 2, 0) se tresMetros = 1

     */

    if (n < 0) return 0;
    if (n == 0) return 1;
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return f_rec(n - 1, p, 0) + f_rec(n - 2, p, 0) + f_rec(n - 3, p, 1);
    if (tresMetros == 1) return f_rec(n - 1, p, 0) + f_rec(n - 2, p, 0);
    return 0;
}

int f_memo(int n, string p, int tresMetros, map<string, int> &memo) {
    /**
        Input:
            n: tamanho da string p
            p: string que representa as posições das pedras
            tresMetros: flag que indica se o último movimento foi de 3 metros
            memo: dicionário que armazena os resultados de chamadas anteriores, passado por referência
        Output:
            quantidade de caminhos possíveis para chegar na posição n

        A ideia é armazenar o resultado de f(n) em um dicionário, onde a chave é uma string composta 
        por n e tresMetros concatenados. Se a chave já existe no dicionário,  então o valor correspondente 
        é retornado, caso contrário, a função é chamada recursivamente e o resultado é armazenado no dicionário


     */
    string key = to_string(n) + to_string(tresMetros);
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo.find(key) != memo.end()) return memo[key]; 
    if (p[n] == '0') return 0;
    if (tresMetros == 0) return memo[key] = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo) + f_memo(n - 3, p, 1, memo);
    if (tresMetros == 1) return memo[key] = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo);
    
    
    
    /**
        Comentarios de Debug
     */

    // if (tresMetros == 0){
    //     int res = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo) + f_memo(n - 3, p, 1, memo);
    //     cout << "n: " << n << " p: " << p << " tresMetros: " << tresMetros << " res: " << res << endl;
    //     return memo[key] = res;
    // } 
        
    // if (tresMetros == 1) {
    //     int res = f_memo(n - 1, p, 0, memo) + f_memo(n - 2, p, 0, memo);
    //     cout << "n: " << n << " p: " << p << " tresMetros: " << tresMetros << " res: " << res << endl;
    //     return memo[key] = res;
    // }
    return 0;
}

int f_iter(int n, string p) {
    /**
        Input:
            n: tamanho da string p
            p: string que representa as posições das pedras
        Output:
            quantidade de caminhos possíveis para chegar na posição n

        A ideia foi resolver o problema usando 2 vetores:
            f1[n] é a quantidade de caminhos possíveis para chegar na posição n, desconsiderando os saltos de 3 metros
            fn[n] é a quantidade de caminhos possíveis para chegar na posição n, considerando a restrinção de não dar dois saltos de 3 metros seguidos

        fn(n) = fn(n - 1) + fn(n - 2) + f1(n - 3) se p[n] != 0
        f1(n) = fn(n - 1) + fn(n - 2) se p[n] != 0
        
     */

    vector<int> f1(n + 1), fn(n + 1);
    f1[0] = fn[0] = p[0] == '0' ? 0 : 1;
    f1[1] = fn[1] = p[1] == '0' ? 0 : 1;
    f1[2] = fn[2] = p[2] == '0' ? 0 : fn[1] + fn[0];

    for (int i = 3; i <= n; i++) {
        f1[i] = p[i] == '0' ? 0 : fn[i - 1] + fn[i - 2];
        fn[i] = p[i] == '0' ? 0 : fn[i - 1] + fn[i - 2] + f1[i - 3];
    }
    /**

        Comentarios de Debug

     */

    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout <<  i << ":" << f1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout <<  i << ":" << fn[i] << " ";
    // }
    // cout << endl;


    return fn[n];
}

int main(int argc, char *argv[]) {
    string p = argv[1];
    int n = p.length() - 1;
    map<string, int> memo;
    cout << "Recursão Simples: " << f_rec(n, p, 0) << endl;
    cout << "Recursão com Memoização: " << f_memo(n, p, 0, memo) << endl;
    cout << "Iterativo: " << f_iter(n, p) << endl;
    return 0;
}