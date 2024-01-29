#include <iostream>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  int N, S;
  cin >> N >> S;
  int haps[100001];
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    haps[i] = haps[i - 1] + num; // 누적합 구하기
  }

  int startIdx = 1;
  int endIdx = startIdx;
  int minLength = 100000;
  while(true) {
    if (startIdx > endIdx || startIdx > N || endIdx > N) {
      break;
    }
    int hap = haps[endIdx] - haps[startIdx - 1];
    if (hap < S) {
      endIdx++;
      if (endIdx - startIdx + 1 >= minLength) {
        startIdx++;
      }
    } else {
      minLength = min(minLength, endIdx - startIdx + 1);
      startIdx++;
    }
  }
  if (haps[N] < S)
    cout << 0 << "\n";
  else
    cout << minLength << "\n";
}