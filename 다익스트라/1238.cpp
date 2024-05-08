#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, M, X; //N: 마을 수, M: 단방향 도로 수, X: 파티가 열리는 마을 번호
vector<pair<int, int>> graph[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int node, int end);

int main() {
  
  scanf("%d %d %d", &N, &M, &X);
  for (int i = 0; i < M; i++) {
    int startP, endP, t;
    scanf("%d %d %d", &startP, &endP, &t);
    graph[startP].push_back(make_pair(endP, t));
  }
  
  int ans = -1;
  for (int i = 1; i <= N; i++) {
    if (i == X) continue;
    int goPartyTime = dijkstra(i, X); // i 정점에서 파티장 X까지 가는 최단시간
    int goHomeTime = dijkstra(X, i); // 파티장 X에서 i 정점까지 가는 최단시간
    ans = max(ans, goPartyTime + goHomeTime);
  }
  printf("%d", ans);
}

int dijkstra(int node, int end) {
  int value[1001]; // 시작 정점에서 i 정점까지 가는 최단 시간을 value[i]에 저장
  bool visited[1001];

  // value, visited 초기화
  for (int i = 1; i <= N; i++) {
    value[i] = INF;
    visited[i] = false;
  }

  value[node] = 0; // 자기 자신으로 가는 시간은 0
  pq.push(make_pair(0, node)); // 큐에 삽입

  while (!pq.empty()) {
    int w = pq.top().first; // node에서 도착 정점까지 가는 시간
    int v = pq.top().second; // 도착 정점 번호
    visited[node] = true; // 방문했음을 의미함
    pq.pop();

    for (int i = 0; i < graph[v].size(); i++) {

      int u = graph[v][i].first; // 도착 정점 번호
      int x = graph[v][i].second; // v에서 도착 정점까지 가는 시간
      if (visited[u]) continue;

      if (w + x < value[u]) {
        value[u] = w + x;
        pq.push(make_pair(value[u], u));
      }
    }
  }

  return value[end];
}