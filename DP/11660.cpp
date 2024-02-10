#include <iostream>
using namespace std;

int dp[1025][1025];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N, M;
    cin >> N >> M; // 1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + num;
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        cout << res << "\n";
    }
}