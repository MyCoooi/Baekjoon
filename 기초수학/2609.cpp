#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int gcd;
    int iterMax = a <= b ? a : b; 
    for (int i = 1; i <= iterMax; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    iterMax = a <= b? b : a;
    int lcm = gcd;
    int tmp = lcm;
    while (true) {
        if (tmp >= iterMax && tmp % a == 0 && tmp % b == 0) {
            lcm = tmp;
            break;
        }
        else
            tmp += lcm;
    }
    cout << gcd << '\n' << lcm << '\n';
}