#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    vector<long long> roadDistances;
    vector<long long> oilPrices;

    int N; // 도시의 수
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        long long d;
        cin >> d;
        roadDistances.push_back(d);
    }
    for(int i = 0; i < N; i++) {
        long long p;
        cin >> p;
        oilPrices.push_back(p);
    }
    long long res = 0;
    long long minOilPrice = 1000000001;
    for (int i = 0; i < oilPrices.size() - 1; i++) {
        minOilPrice = min(minOilPrice, oilPrices[i]);
        res += roadDistances[i] * minOilPrice;
    }
    printf("%lld\n", res);
}