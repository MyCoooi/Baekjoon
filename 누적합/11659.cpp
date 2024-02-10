#include <iostream>
using namespace std;

int nums[100001];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        int num;
        cin >> num;
        nums[i] = nums[i - 1] + num;
    }
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        cout << nums[end] - nums[start - 1] << '\n';
    }
    
}