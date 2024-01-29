#include <iostream>
#include <string.h>
using namespace std;

int N;
int input[2005];
int dp[2005][2005]; // 0: 펠린드롬 x, 1: 펠린드롬 o, -1: 미정

int palindromeCheck (int startIdx, int endIdx);

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> input[i];
  }

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < N; i++) {
    dp[i][i] = 1;
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int S, E;
    cin >> S >> E;

    int startIdx = S - 1;
    int endIdx = E - 1;

    cout << palindromeCheck(startIdx, endIdx) << '\n';
  }
}

int palindromeCheck (int startIdx, int endIdx) {
    if(endIdx - startIdx == 1) {
        if (input[startIdx] == input[endIdx]) {
            return dp[startIdx][endIdx] = 1;
        }
        return dp[startIdx][endIdx] = 0;
    }
    if (dp[startIdx][endIdx] == -1) {
        if (input[startIdx] == input[endIdx]) {
            if (palindromeCheck(startIdx + 1, endIdx - 1) == 1)
                dp[startIdx][endIdx] = 1;
            else
                dp[startIdx][endIdx] = 0;
        } 
        else {
            dp[startIdx][endIdx] = 0;
        } 
    }
    return dp[startIdx][endIdx];
}