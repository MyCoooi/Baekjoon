#include <iostream>
#include <string.h>
using namespace std;

int graph[1001][1001];

int main() {
  cin.tie(0) -> sync_with_stdio(false);

  memset(graph, -1, sizeof(int));
  int N, M, X;
  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    int start, end, t;
    cin >> start >> end >> t;

    graph[start][end] = t;
    
  }
}