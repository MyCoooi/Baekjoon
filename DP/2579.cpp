#include <iostream>
using namespace std;

void recursive(int idx, int preIdx, int score);

int mem[302] = {0,};
int stairs[302];

void recursive(int idx, int preIdx, int score) {
    if (mem[idx] == 0 || mem[idx] < score) mem[idx] = score;

    if (idx > 0) {
        if (preIdx-idx == 2) recursive(idx-1, idx, mem[idx]+stairs[idx-1]);
        if (idx != 1) recursive(idx-2, idx, mem[idx]+stairs[idx-2]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int n;
    cin >> n;
    for (int i=0; i < n; i++) cin >> stairs[i];
    stairs[n+1] = 0;
    recursive(n-1, n+1, stairs[n-1]);
    int max;
    if (n > 1) max = (mem[0] >= mem[1]) ? mem[0] : mem[1];
    else max = mem[0];
    cout << max << "\n";
}