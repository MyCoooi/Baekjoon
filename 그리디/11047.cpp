#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N; // 동전 종류
    int K; // 가치
    int res = 0; // 최소 동전 갯수
    int coinArr[11];
    int size = 0;

    cin >> N >> K;
    int tmp = K;
    for(int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coinArr[i] = coin;
        size++;
    }
    for(int i = size-1; i >= 0; i--) {
        if (tmp == 0)
            break;
        else {
            if (coinArr[i] <= tmp) {
                res += tmp / coinArr[i];
                tmp = K % coinArr[i];
            }
        }
    }
    printf("%d\n", res);
}