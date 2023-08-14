#include <iostream>
#include <string.h>

using namespace std;

long long mem[101];

long long p(int n);

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    memset(mem, 0, sizeof(int) * 101);

    mem[1] = mem[2] = mem[3] = 1;
    mem[4] = mem[5] = 2;

    int testCase;
    cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;

        printf("%lld\n", p(n));
    }
}

long long p(int n) {
    if (mem[n] != 0);
    else {
        int partIdx = 1;
        for (int i = 6; i <= n; i++) {
            if (mem[i] != 0);
            else {
                mem[i] = mem[partIdx] + mem[i - 1];
            }
            partIdx++;
        }
    }
    return mem[n];
}