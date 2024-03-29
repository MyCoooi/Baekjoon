#include <iostream>
using namespace std;

int mem[1001][2];
// mem[i][0]: input 값
// mem[i][1]: 각 수가 취할 수 있는 가장 큰 증가하는 부분 수열 값

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mem[i][0];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        mem[i][1] = mem[i][0];
        for (int j = i - 1; j >= 0; j--) {
            if (mem[j][0] < mem[i][0]) {
                mem[i][1] = max(mem[i][1], mem[j][1] + mem[i][0]);
            }
        }
        res = max(res, mem[i][1]);
    }

    printf("%d\n", res);
}