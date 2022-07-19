#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[80001];
    for (int i = 0; i < n; i++) {
        cin >> stack[i];
    }
    stack[n] = 1000000001;

    int idx = 0;
    unsigned long long sum = 0;
    while(idx < n) {
        int curHeight = stack[idx];
        int tmp = idx+1;
        while(true) {
            int nextHeight = stack[tmp];

            if (curHeight > nextHeight) tmp++;
            else {
                break;
            }
        }
        // stack[idx] = tmp-idx-1;
        sum += tmp-idx-1;
        idx++;
    }
    cout << sum;
}