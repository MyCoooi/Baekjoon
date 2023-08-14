#include <iostream>
using namespace std;

int mem[1000001];
int fibonacci(int n);

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N;
    cin >> N;
    printf("%d\n", fibonacci(N));
}

int fibonacci(int n) {
    mem[0] = mem[1] = 1;
    for (int i = 2; i <= n; i++) {
        mem[i] = (mem[i - 1] + mem[i - 2]) % 15746;
    }
    return mem[n];
}