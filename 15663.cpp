#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int input[8], numbers[8];

void permutation(int cnt, int bitMaskFlag);

int main() {
  cin.tie(0) -> sync_with_stdio(false);


  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    input[i] = num;
  }

  // 사전 순으로 출력하기 위해 오름차순 정렬
  sort(input, input + N);

  // 순열 구하기
  permutation(0, 0);
}

void permutation(int cnt, int bitMaskFlag) {
  // 기저 부분
  if (cnt == M) {
    for (int i = 0; i < M; i++) cout << numbers[i] << " ";
    cout << "\n";
    return;
  }

  // 유도 부분
    for (int i = 0; i < N; i++) {
      // 중복 체크 코드 작성하기 ---

      // -----------------------
      if ((bitMaskFlag & (1 << i)) != 0) continue;

      numbers[cnt] = input[i];
      permutation(cnt + 1, (bitMaskFlag || 1 << i));
    }
}