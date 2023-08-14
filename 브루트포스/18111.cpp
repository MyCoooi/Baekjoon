#include <iostream>
using namespace std;

int heights[501][501];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N, M, B; // 집터의 세로 길이, 집터의 가로 길이, 시작 전 인벤토리 블록 갯수
    cin >> N >> M >> B;

    int resTime = INT32_MAX;
    int resHeight;
    int sum = 0;
    int maxHeight = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> heights[i][j];
            sum += heights[i][j];
            maxHeight = max(maxHeight, heights[i][j]);
        }
    }

    sum += B;
    while(maxHeight * N * M > sum) {
        maxHeight--;
    }


    for (int h = maxHeight; h >= 0; h--) {
        int remove = 0;
        int install = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (heights[i][j] == h);
                else if (heights[i][j] < h)
                    install += h - heights[i][j];
                else
                    remove += heights[i][j] - h;
            }
        }
        int totalTime = remove * 2 + install * 1;
        if (resTime > totalTime) {
            resTime = totalTime;
            resHeight = h;
        }
    }

    printf("%d %d\n", resTime, resHeight);
}