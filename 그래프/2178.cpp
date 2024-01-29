#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int SIZE = 10001;
vector<int> nodes;
vector<int> graph[SIZE];
queue<pair<int, int>> q;
bool visited[SIZE];

int bfsSearch(int targetNode) {
    while (!q.empty()) {
        int curNodeN = q.front().first;
        int curNodeC = q.front().second;
        q.pop();
        
        if (!visited[curNodeN]) {
            visited[curNodeN] = true;

            if (curNodeN == targetNode) {
                return curNodeC;
            }

            for (int i = 0; i < graph[curNodeN].size(); i++) {
                if (!visited[graph[curNodeN][i]]) {
                    q.push(make_pair(graph[curNodeN][i], curNodeC + 1));
                }
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int i = 0; i < input.size(); i++) { // 한 줄 입력 받아 정수(1, 0) 분리 후 nodes 벡터에 저장
            nodes.push_back(input[i] - '0');
        }
    }

    // nodes의 인덱스가 곧 노드의 번호 nodes[1]은 노드 번호가 1.
    for (int i = 0; i < N; i++) { // 옆 노드로 가는 엣지 확인. 서로 인접한 칸으로만 이동할 수 있으므로 바로 옆에 있는 노드만 확인하면 됨.
        for (int j = 0; j < M - 1; j++) {
            int curNodeNum = i * M + j;
            if (nodes[curNodeNum] == 1 && nodes[curNodeNum + 1] == 1) {
                graph[curNodeNum].push_back(curNodeNum + 1); // 노드1에서 노드2로 갈 수 있으면
                graph[curNodeNum + 1].push_back(curNodeNum); // 노드2에서 노드1로도 갈 수 있다.
            }
        }
    }

    for (int i = 0; i < N - 1; i++) { // 아래 노드로 가는 엣지 확인. 서로 인접한 칸으로만 이동할 수 있으므로 바로 위 아래에 있는 노드만 확인하면 됨.
        for (int j = 0; j < M; j++) {
            int curNodeNum = i * M + j;
            if (nodes[curNodeNum] == 1 && nodes[curNodeNum + M] == 1) {
                graph[curNodeNum].push_back(curNodeNum + M); // 노드1에서 노드5로 갈 수 있으면
                graph[curNodeNum + M].push_back(curNodeNum); // 노드5에서 노드1로도 갈 수 있다.
            }
        }
    }

    for (int i = 0; i < SIZE; i++) { // 작은 노드부터 처리하기 위해 노드 번호를 오름차순 정렬
        sort(graph[i].begin(), graph[i].end());
    }

    q.push(make_pair(0, 1));
    cout << bfsSearch(N * M - 1) << '\n';
}