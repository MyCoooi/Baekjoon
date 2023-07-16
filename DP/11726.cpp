#include <iostream>
using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = 1;
    dp[1] = 2;

    int n;
    cin >> n;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n-1];
}