#include <iostream>
using namespace std;

void findPrime(int n, int m);
short isNotPrime[1000001]; // 모두 0으로 초기화.
// i번째 수가 소수면 isNotPrime[i] = 0, 소수가 아니면 isNotPrime[i] = 1

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    findPrime(N, M);
}

void findPrime(int n, int m) {
    isNotPrime[0] = isNotPrime[1] = 1;
    isNotPrime[2] = isNotPrime[3] = 0;

    for (int i = 2; i <= m; i++) { // isNotPrime[i번째 배수]는 모두 1
        for (int j = i*2; j <= m; j += i) { // j는 i의 배수
            if (isNotPrime[j] == 0) {
                isNotPrime[j] = 1;
            }
        }
    }

    for (int i = n; i <= m; i++) {
        if (!isNotPrime[i])
            cout << i << '\n';
    }
}