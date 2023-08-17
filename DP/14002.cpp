#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int mem[1001][3];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        fill(mem[i], mem[i] + 2, 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> mem[i][0];
        mem[i][2] = i;
    }

    int resIdx = 0;
    int resLIS = 0;
    for (int i = 0; i < n; i++) {
        int maxLSIIdx = i;
        for (int j = i - 1; j >= 0; j--) {
            if (mem[j][0] < mem[i][0] && mem[i][1] < mem[j][1] + 1) {
                mem[i][1] = mem[j][1] + 1;
                mem[i][2] = j;
            }
        }
        if (resLIS < mem[i][1]) {
            resLIS = mem[i][1];
            resIdx = i;
        }
    }
    stack<int> res;
    while (mem[resIdx][2] != resIdx) {
        res.push(mem[resIdx][0]);
        resIdx = mem[resIdx][2];
    }
    res.push(mem[resIdx][0]);
    printf("%d\n", resLIS);
    while (!res.empty()) {
        printf("%d ", res.top());
        res.pop();
    }
}