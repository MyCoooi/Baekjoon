#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
      q.push(i);

    cout << "<";
    while (!q.empty()) {
      for (int i = 0; i < K - 1; i++) {
        q.push(q.front());
        q.pop();
      }
      cout << q.front();
      if (q.size() != 1)
        cout << ", ";
      q.pop();
    }
    cout << ">";
}