#include <iostream>
using namespace std;

int input[1000001];
int mem[1000001];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    // 입력 받기
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    mem[0] = input[0];
    int memLastIdx = 0;

    for (int i = 1; i < n; i++) {
        if (mem[memLastIdx] < input[i]) {
            memLastIdx++;
            mem[memLastIdx] = input[i];
        }
        else {
            int left = 0;
            int right = memLastIdx;
            int mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (mem[mid] == input[i])
                    break;
                else if (mem[mid] < input[i]) {
                    if (mid + 1 <= memLastIdx && mem[mid + 1] > input[i]) {
                        mid++;
                        break;
                    }
                    left = mid + 1;
                }
                else {
                    if (mid - 1 >= 0 && mem[mid - 1] < input[i]) {
                        break;
                    }
                    right = mid - 1;
                }
            }
            mem[mid] = input[i];
        }
    }
    printf("%d\n", memLastIdx + 1);
}