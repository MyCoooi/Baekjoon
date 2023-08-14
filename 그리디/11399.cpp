#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N; // 대기 중인 사람의 수
    vector<int> moneyWithdrawTimes; // 돈 인출 시간 배열
    int res = 0;
    int tmp = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int time;
        cin >> time;
        moneyWithdrawTimes.push_back(time);
    }
    sort(moneyWithdrawTimes.begin(), moneyWithdrawTimes.end());

    for(auto m : moneyWithdrawTimes) {
        tmp = tmp + m;
        res += tmp;
    }
    printf("%d\n", res);
}