#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int* arr = new int[n];
    int* dp = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = arr[0];
    int tmp = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        tmp = max(dp[i], tmp);
    }
    cout << tmp << endl;
}