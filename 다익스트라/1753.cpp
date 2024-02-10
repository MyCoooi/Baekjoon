#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int V, E, K; // V: ������ ����, E: ������ ����, K: ���� ���� ��ȣ
vector<pair<int,int>> graph[20001]; // �� ���? ����Ǿ�? �ִ� ���? ���� ������ ���? �迭 (pait<���� ���?, �Ÿ�>)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �ּ� ���? ������ ã�� ���� �켱���� ť(pair<�Ÿ�, �������?>)
int value[20001]; // �ִܰŸ� ���̺�

int main() {
  scanf("%d %d", &V, &E);
  scanf("%d", &K);

  // ���� ���� �Է� �ޱ�
  for (int i = 0; i < E; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    graph[u].push_back(make_pair(v,w));
  }

  // �ִܰŸ� ���? �������� �ʱ�ȭ
  for (int i = 1; i <= V; i++) {
    value[i] = INF;
  }

  value[K] = 0; // ���� ���� -> ���� ���� �Ÿ��� 0���� ����

  pq.push(make_pair(0,K));

  while(!pq.empty()) {
    int x = pq.top().first; // �Ÿ�
    int u = pq.top().second; // ���� ���?
    pq.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;

      if(x + w <value[v]) {
        value[v] = x + w;
        pq.push(make_pair(x+w, v));
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (value[i] == INF) printf("INF\n");
    else printf("%d\n", value[i]);
  }
  
  return 0;

}