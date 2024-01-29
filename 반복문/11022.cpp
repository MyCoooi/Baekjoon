#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << left << setw(2) << a + b << "\n";
    }
}