#include <iostream>
using namespace std;

int mem[1001][1001];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    string s1, s2; // s1: row, s2: col
    cin >> s1 >> s2;

    for (int i = 0; i <= s1.length(); i++)
        mem[0][i] = 0;
    for (int i = 0; i <= s2.length(); i++)
        mem[i][0] = 0;
    
    int res = 0;
    for (int i = 1; i <= s2.length(); i++) {
        for (int j = 1; j <= s1.length(); j++) {
            if (s2[i - 1] == s1[j - 1]) {
                mem[j][i] = mem[j - 1][i - 1] + 1;
            }
            else {
                mem[j][i] = max(mem[j - 1][i], mem[j][i - 1]);
            }
            res = max(res, mem[j][i]);
        }
    }
    printf("%d\n", res);
}