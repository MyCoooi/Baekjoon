#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// struct cmp {
//     bool operator()(int a, int b) {
        
//     }
// };

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (x != 0)
            pq.push(x);
        else {
            if (pq.empty())
                printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
}