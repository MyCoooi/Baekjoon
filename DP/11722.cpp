#include <iostream>
#include <algorithm>
using namespace std;

int mem[1001][2];

int main() {
    cin.tie(0) -> sync_with_stdio(false);


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(mem[i], mem[i] + 2, 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> mem[i][0];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (mem[j][0] > mem[i][0]) {
                mem[i][1] = max(mem[i][1], mem[j][1] + 1);
            }  
        }
        res = max(res, mem[i][1]);
    }
    printf("%d\n", res);
}