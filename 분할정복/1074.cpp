#include <iostream>
#include <math.h>
using namespace std;

void search(int n, int startR, int startC);

int ans = -1;
int N, r, c;
int cnt = 0;

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  cin >> N >> r >> c;

  search(N, 0, 0);
  cout << ans;
}

void search(int n, int startR, int startC) {

  if (n == 1) {
    int arr[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        arr[i][j] = cnt++;
        // cout << startR + i << ", " << startC + j << "\n";
        if (startR + i == r && startC + j == c) {
          ans = arr[i][j];
        }
      }
    }

    return;
  }

  if (r < startR + pow(2, n - 1) && c < startC + pow(2, n - 1)) { // 왼쪽 위
    // cout << "A" << "\n";
    search(n-1, startR, startC);
  } else if (r < startR + pow(2, n - 1)) { // 오른쪽 위
    cnt += pow(2, n - 1) * pow(2, n - 1);
    // cout << "B, " << cnt << "\n";
    search(n-1, startR, startC + pow(2, n - 1));
  } else if (c < startC + pow(2, n - 1)) { // 왼쪽 아래
    cnt += pow(2, n - 1) * pow(2, n - 1) * 2;
    // cout << "C, " << cnt << "\n";
    search(n-1, startR + pow(2, n - 1), startC);
  } else { // 오른쪽 아래
    cnt += pow(2, n - 1) * pow(2, n - 1) * 3;
    // cout << "D, " << cnt << "\n";
    search(n-1, startR + pow(2, n - 1), startC + pow(2, n - 1));
  }
}