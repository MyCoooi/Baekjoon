#include <iostream>
using namespace std;

int dp[10002][4];
int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dp[i][0];
    }
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            dp[i][1] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]);
            dp[i][2] = max(max(dp[i-2][1], dp[i-2][2]), dp[i-2][3]);
            dp[i][3] = max(max(dp[i-3][1], dp[i-3][2]), dp[i-3][3]);
        }
        else {
            if (i - 1 < 0)
                dp[i][1] = dp[i][0];
            else
                dp[i][1] = dp[i][0] + max(dp[i-1][2], dp[i-1][3]);
            if (i - 2 < 0)
                dp[i][2] = dp[i][0];
            else
                dp[i][2] = dp[i][0] + max(max(dp[i-2][1], dp[i-2][2]), dp[i-2][3]);
            if (i - 3 < 0)
                dp[i][3] = dp[i][0];
            else
                dp[i][3] = dp[i][0] + max(max(dp[i-3][1], dp[i-3][2]), dp[i-3][3]);
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         printf("dp[%d][%d] : %d ", i, j, dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", max(max(dp[n][1], dp[n][2]), dp[n][3]));
}