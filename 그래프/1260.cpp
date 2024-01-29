#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int SIZE = 1001;
vector<int> graph[SIZE];
bool visitedNode[SIZE]; // i번째 노드의 방문 여부 t/f
queue<int> q;

void dfs(int node) {
    for(auto nextNode : graph[node]) {
        if (!visitedNode[nextNode]) { // 방문하지 않았다면
            visitedNode[nextNode] = true; // 방문
            cout << nextNode << ' ';
            dfs(nextNode);
        }
    }
}

void bfs() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (visitedNode[node]);
        else {
            visitedNode[node] = true;
            cout << node << ' ';
            for (auto nextNode : graph[node]) {
                if (!visitedNode[nextNode]) {
                    q.push(nextNode);
                }
            }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N, M, V; // N: 정점 개수, M: 간선 개수, V: 시작 정점 번호
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) { 
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }

    for (int i = 0; i < SIZE; i++) { // vector 오름차순으로 정렬(번호가 작은 노드부터 순회하기 위해서)
        sort(graph[i].begin(), graph[i].end());
    }

    visitedNode[V] = true;
    cout << V << ' ';
    dfs(V);
    cout << '\n';
    memset(visitedNode, false, sizeof(bool) * SIZE);
    q.push(V);
    bfs();
}