#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool inputCompare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
    if (a.second == b.second) 
        return a.first <= b.first;
    return a.second <= b.second;
}

vector<pair<unsigned int, unsigned int>> rooms;
int N;
unsigned int curT = 0; // 현재 시간
int res = 0; // 회의 최대 개수;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        unsigned int startT;
        unsigned int finishT;
        cin >> startT >> finishT;
        rooms.push_back(make_pair(startT, finishT));
    }
    sort(rooms.begin(), rooms.end(), inputCompare);

    // for (auto m : rooms) {
    //     printf("%u, %u\n", m.first, m.second);
    // }

    int i = 0;
    curT = rooms[i].second;
    int size = rooms.size();
    res++;
    i++;
    while(curT <= rooms[size-1].second && i < size) {
        // printf("i: %d, curT: %u, res: %d\n", i, curT, res);
        for (int j = i; j < size; j++) {
            if (rooms[j].first >= curT) {
                curT = rooms[j].second;
                i = j + 1;
                res++;
                break;
            }
            else
                i++;
        }
    }
    printf("%d\n", res);
}

