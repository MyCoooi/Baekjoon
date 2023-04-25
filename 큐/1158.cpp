#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) q.push(i);

    int cnt = 0;
    while(!q.empty()) {
        cnt++;

        if (cnt % K == 0) {
            res.push_back(q.front());
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }

    cout << "<";
    for (int i = 0; i < res.size(); i++) {
        if (i != res.size()-1) cout << res[i] << ", ";
        else cout << res[i];
    }
    cout << ">\n";
}