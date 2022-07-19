#include <iostream>
using namespace std;

int mem[1000001] = {0,};
void recursive(int n, int cnt);

void recursive(int n, int cnt) {
    if (mem[n] == 0 || mem[n] > cnt) {
        mem[n] = cnt;
    }
    if (n == 1 || mem[n] < cnt) return;

    if (n%3 == 0) {
        recursive(n/3, cnt+1);
    }
    if (n%2 == 0) {
        recursive(n/2, cnt+1);
    }
    if (n != 0) recursive(n-1, cnt+1);    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    recursive(n, 0);
    cout << mem[1] << '\n';
}