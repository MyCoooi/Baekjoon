#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int a, b;
        cin >> a >> b;
        
        int gcd = 1;
        int iterMax = a <= b ? a : b;
        for (int i = 1; i <= iterMax; i++) {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
        int lcm;
        if (a == 1 || b == 1)
            lcm = a <= b? b : a;
        else if (gcd == 1)
            lcm = a * b;
        else {
            lcm = gcd * (a / gcd) * (b / gcd);
        }
        cout << lcm << '\n';
    }
}