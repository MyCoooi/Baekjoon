#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while(testCase--) {
        long long h; int w; long long n;
        cin >> h >> w >> n;

        cout << n - (ceil(n/double(h))-1)*h;
        int wNum = ceil(n/double(h));
        // int wNum = (n-1) / h + 1;
        if (wNum < 10)
            cout << 0 << wNum << '\n';
        else
            cout << wNum << '\n';
    }
}