#include <iostream>
using namespace std;

int code1 = 0;
int code2 = 0;
int mem[41];

int fib(int n);
int fibonacci(int n);

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    fib(n);
    fibonacci(n);

    printf("%d %d", code1, code2);
}

int fib(int n) {
    if (n == 1 || n == 2) {
        code1++;
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int fibonacci(int n) {
    mem[1] = 1;
    mem[2] = 1;
    for(int i = 3; i <= n; i++) {
        code2++;
        mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n];
}