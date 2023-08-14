#include <iostream>
#include <algorithm>
using namespace std;

int mem[1001][3];
// mem[i][0]: 수 저장
// mem[i][1]: 각 수가 취할 수 있는 LIS 저장
// mem[i][2]: 각 수가 취할 수 있는 LDS 저장

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        fill(mem[i], mem[i] + 3, 1);
    }
    for (int i = 0; i < n; i++)
        cin >> mem[i][0];
    
    // LIS
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (mem[j][0] < mem[i][0])
                mem[i][1] = max(mem[i][1], mem[j][1] + 1);
        }
    }

    // LDS
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (mem[i][0] > mem[j][0])
                mem[i][2] = max(mem[i][2], mem[j][2] + 1);
        }
    }

    // for (int i = 0 ; i < n; i++) {
    //     for (int j = 0; j < 3; j++)
    //         printf("%d ", mem[i][j]);
    //     printf("\n");
    // }

    int res = mem[0][1] + mem[0][2];
    for (int i = 1; i < n; i++) {
        res = max(res, mem[i][1] + mem[i][2]);
    }
    res--;
    printf("%d\n", res);
}