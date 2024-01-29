#include <cstdio>
using namespace std;

const int SIZE = 51;
char board[SIZE][SIZE];
int cnt[SIZE][SIZE];
int N, M;
int minCnt = SIZE * SIZE + 1;

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        getchar(); // 입력 스트림 개행 문자 버리기
        for (int j = 0; j < M; j++) {
            scanf("%c", &board[i][j]);
        }
    }

    for (int i = 0; i <= N - 8; i++) { // 보드에서 8X8체스판이 나올 수 있는 경우의 수는 많으므로
        for (int j = 0; j <= M - 8; j++) { // 다시 칠해야 하는 정사각형 개수의 최솟값을 알려면 나올 수 있는 모두 체스판을 다 훑어야 함
            int bCnt = 0, wCnt = 0; // bCnt는 보드의 첫번째 정사각형이 B일 때 8X8 체스판에서 다시 칠해야 하는 정사각형 갯수, wCnt는 보드의 첫번째 정사각형이 W일 때 ~
            // 8X8 체스판마다 다시 칠해야 하는 정사각형의 갯수 구하기
            for (int r = i; r < i + 8; r++) {
                for (int c = j; c < j + 8; c++) {
                    if ((r + c) % 2 == 0) { // 정사각형의 r + c가 짝수일 때
                        if (board[r][c] != 'W') wCnt++; // 보드의 첫번째 정사각형이 W라면 board[r][c]는 W가 되어야 하는데, W가 아니면 다시 칠해야 하므로 wCnt에 1을 더해준다.
                        if (board[r][c] != 'B') bCnt++; // 보드의 첫번째 정사각형이 B라면 board[r][c]는 B가 되어야 하는데, B가 아니면 다시 칠해야 하므로 bCnt에 1을 더해준다.
                    }
                    else { // 정사각형의 r + c가 홀수라면,
                        if (board[r][c] != 'B') wCnt++; // 보드의 첫번째 정사각형이 W라면 board[r][c]는 B가 되어야 하는데, B가 아니면 다시 칠해야 하므로 wCnt에 1을 더해준다.
                        if (board[r][c] != 'W') bCnt++; // 보드의 첫번째 정사각형이 B라면 board[r][c]는 W가 되어야 하는데, W가 아니면 다시 칠해야 하므로 bCnt에 1을 더해준다.
                    }
                }
            }

            // 다시 칠해야 하는 정사각형의 최솟값을 찾기 위해 비교
            int tmp = wCnt;
            tmp = tmp <= bCnt ? tmp : bCnt;
            minCnt = minCnt >= tmp ? tmp : minCnt;
        }
    }

    printf("%d\n", minCnt);
}