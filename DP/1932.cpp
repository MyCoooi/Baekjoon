#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>*> dp;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N;
    cin >> N;
    int inputSize = 1;
    for (int i = 0; i < N; i++) {
        vector<pair<int,int>>* v = new vector<pair<int,int>>;
        for (int j = 0; j < inputSize; j++) {
            int n;
            cin >> n;
            v->push_back(make_pair(n, n));
        }
        dp.push_back(v);
        inputSize++;
    }

    inputSize = 2;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < inputSize; j++) {
            if (j >= 1)
                (*dp[i])[j].first += max((*dp[i-1])[j-1].first, (*dp[i-1])[j-1].second);
            if (j != inputSize - 1)
                (*dp[i])[j].second += max((*dp[i-1])[j].first, (*dp[i-1])[j].second);
        }
        inputSize++;
    }

    // for(int i = 0; i < N; i++) {
    //     printf("i: %d\n", i);
    //     for (auto p : *dp[i]) {
    //         printf("(%d, %d) ", p.first, p.second);
    //     }
    //     printf("\n");
    // }

    int res = -1;
    for (auto p : *dp[N-1]) {
        res = max(res, p.first);
        res = max(res, p.second);
    }

    printf("%d\n", res);
}