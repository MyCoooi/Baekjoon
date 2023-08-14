#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> input;
int mem[101];

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        input.push_back(make_pair(first, second));
    }

    sort(input.begin(), input.end(), compare);

    fill(mem, mem + n, 1);

    // for (auto p : input) {
    //     printf("%d %d\n", p.first, p.second);
    // }

    int lis = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[j].second < input[i].second) {
                mem[i] = max(mem[i], mem[j] + 1);
            }
        }
        lis = max(lis, mem[i]);
    }

    int res = n - lis;
    printf("%d\n", res);
}