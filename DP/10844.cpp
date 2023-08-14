#include <iostream>
#include <string.h>
using namespace std;

int mem[101][10];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < 101; i++) {
        memset(mem[i], 0, sizeof(int) * 10);
    }

    for (int i = 1; i < 10; i++) {
        mem[1][i] = 1; 
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 1 && j == 0)
                continue;
            else {
                if (j == 0) {
                    mem[i+1][1] += mem[i][j] % 1000000000;
                    mem[i+1][1] %= 1000000000;
                }
                else if (j == 9) {
                    mem[i+1][8] += mem[i][j] % 1000000000;
                    mem[i+1][8] %= 1000000000;
                }
                else {
                    mem[i+1][j-1] += mem[i][j] % 1000000000;
                    mem[i+1][j-1] %= 1000000000;
                    mem[i+1][j+1] += mem[i][j];
                    mem[i+1][j+1] %= 1000000000;
                }
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < 10; i++) {
        res += mem[N][i] % 1000000000;
        res %= 1000000000;
    }

    printf("%lld\n", res);



}