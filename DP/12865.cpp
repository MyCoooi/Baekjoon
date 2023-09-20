#include <iostream>
#include <string.h>
using namespace std;

int W[101]; // 동전 무게 배열
int V[101]; // 동전 가치 배열
int mem[101][100001];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n, k; // N: 물건의 갯수, K: 배낭에 들어갈 수 있는 최대 무게
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> W[i] >> V[i];
    
    for (int i = 1; i <= n; i++) {
        // printf("i: %d\n", i);
        for (int j = 1; j <= k; j++) {
            if (i == 1) {
                if (W[i] <= j)
                    mem[i][j] = V[i];
                else
                    mem[i][j] = 0;
            }
            else {
                if (W[i] <= j)
                    mem[i][j] = max(mem[i - 1][j], mem[i - 1][j - W[i]] + V[i]);
                else
                    mem[i][j] = mem[i - 1][j];
            }
            // printf("%d ", mem[i][j]);
        }
        // printf("\n");
    }
    printf("%d\n", mem[n][k]);

}