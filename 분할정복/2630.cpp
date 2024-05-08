#include <iostream>
using namespace std;

bool coloredPapers[129][129];
int whitePaperCnt = 0;
int bluePaperCnt = 0;
int N; // 2, 4, 8, 16, 32, 64, 128 중 하나

int search(int size, int curR, int curC);

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> coloredPapers[i][j];
    }
  }

  int status = search(N, 0, 0);
  if (status == 1) bluePaperCnt++;
  else if (status == 0) whitePaperCnt++;

  cout << whitePaperCnt << "\n" << bluePaperCnt;

  return 0;
}

// return 값이 0이면 그 영역은 모두 0, 1이면 그 영역은 모두 1, -1이면 영역의 색이 다 다름
int search(int size, int curR, int curC) {
  // 기저 부분
  if (size == 1) {
    return coloredPapers[curR][curC];
  }

  // 유도 부분
  int statusArr[4];
  int deltas[4][2] = {{0,0},{0,size / 2},{size / 2,0},{size / 2,size / 2}}; // 제 1사분면, 2사분면, 3사분면, 4사분면

  for (int d = 0; d < 4; d++) {
    statusArr[d] = search(size / 2, curR + deltas[d][0], curC + deltas[d][1]);
  }

  bool check = true;
  for (int i = 0; i < 3; i++) {
    if (statusArr[i] != statusArr[i+1]) {
      check = false;
      break;
    }
  }
  if (check) {
    return statusArr[0];
  }
  for (int i = 0; i < 4; i++) {
    if (statusArr[i] == 0) {
      whitePaperCnt++;
    }
    else if (statusArr[i] == 1) {
      bluePaperCnt++;
    }
  }
  return -1;
}