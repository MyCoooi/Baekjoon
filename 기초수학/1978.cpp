#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int N;
    cin >> N;

    int cnt = 0;
    while (N--) {
        int n;
        cin >> n;

        bool isPrime = true;
        if (n == 1)
            isPrime = false;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cnt++;
    }
    cout << cnt << '\n';
}