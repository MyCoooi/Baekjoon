#include <iostream>
#include <stack>
using namespace std;

int input[1000001]; // 입력으로 들어온 수열 저장
int lis[1000001]; // LIS 수열 저장
int idx[1000001]; // lis 배열에서 input[i]가 들어가 있는 위치(인덱스)가 idx[i].

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> input[i];

    lis[0] = input[0];
    idx[0] = 0;
    int lisLastIdx = 0;
    for (int i = 1; i < n; i++) {
        if (lis[lisLastIdx] < input[i]) {
            lisLastIdx++;
            lis[lisLastIdx] = input[i];
            idx[i] = lisLastIdx;
        }
        else {
            int left = 0;
            int right = lisLastIdx;
            int mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (lis[mid] == input[i])
                    break;
                else if (lis[mid] < input[i]) {
                    if (mid + 1 <= lisLastIdx && lis[mid + 1] > input[i]) {
                        mid += 1;
                        break;
                    }
                    left = mid + 1;
                }
                else {
                    if (mid - 1 >= 0 && lis[mid - 1] < input[i]) {
                        break;
                    }
                    right = mid - 1;
                }
            }
            lis[mid] = input[i];
            idx[i] = mid;
        }
    }

    stack<int> res;
    printf("%d\n", lisLastIdx + 1);
    int lisEndIdx = lisLastIdx;
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == lisEndIdx) {
            res.push(input[i]);
            lisEndIdx--;
        }
        if (lisEndIdx < 0) {
            break;
        }
    }
    while (!res.empty()) {
        printf("%d ", res.top());
        res.pop();
    }
}