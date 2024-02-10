#include <iostream>
using namespace std;

int N, S; // 10 ≤ N < 100,000         0 < S ≤ 100,000,000
int hap[100001];

int main() {
    cin.tie(0) -> sync_with_stdio(false);

   int minLength = 1;
   int iterIdx = 0;
   cin >> N >> S;
   for (int i = minLength; i <= N; i++) { // 누적합 구하기
    int num;
    cin >> num;
    hap[i] = hap[i-1] + num;
   }
}