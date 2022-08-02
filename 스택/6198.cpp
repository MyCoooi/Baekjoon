#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[80001] = {0,};
    long long ans = 0;
    int curIdx = 0;
    for (int i = 0; i < n; i++) {
        cin >> dp[curIdx];

        while (curIdx != 0) {
            if(dp[curIdx] >= dp[curIdx-1]) {
                dp[curIdx-1] = dp[curIdx];
                dp[curIdx] = 0;
                curIdx--;
            }
            else {
                curIdx++;
                break;
            }
        }
        if (curIdx == 0) curIdx++;

        ans += curIdx-1;
    }
    cout << ans;   
}