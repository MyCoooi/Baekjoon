#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>*> rgbV;
vector<vector<vector<int>*>*> costV;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    rgbV.push_back(new vector<int>); // r
    rgbV.push_back(new vector<int>); // g
    rgbV.push_back(new vector<int>); // b

    costV.push_back(new vector<vector<int>*>); // r
    costV.push_back(new vector<vector<int>*>); // g
    costV.push_back(new vector<vector<int>*>); // b
    
    for (int i = 0; i < 3; i++) {
        costV[i]->push_back(new vector<int>); // costV[i][0]
        costV[i]->push_back(new vector<int>); // costV[i][1]
    }

    int N; // 집의 갯수
    cin >> N;
    for (int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        rgbV[0]->push_back(r);
        rgbV[1]->push_back(g);
        rgbV[2]->push_back(b);
    }

    // costV 초기화
    for (int i = 0; i < 3; i++) {
        (*costV[i])[0]->push_back((*rgbV[i])[0]);
        (*costV[i])[1]->push_back((*rgbV[i])[0]);
    }

    for (int i = 1; i < N; i++) { // n iter
        // printf("i: %d\n", i);
        for (int j = 0; j < 3; j++) { // rgb iter
            // printf("j: %d\n", j);
            if (j == 0) {
                (*costV[j])[0]->push_back(min((*(*costV[1])[0])[i-1] + (*rgbV[j])[i], (*(*costV[1])[1])[i-1] + (*rgbV[j])[i]));
                (*costV[j])[1]->push_back(min((*(*costV[2])[0])[i-1] + (*rgbV[j])[i], (*(*costV[2])[1])[i-1] + (*rgbV[j])[i]));
            } 
            else if (j == 1) {
                (*costV[j])[0]->push_back(min((*(*costV[0])[0])[i-1] + (*rgbV[j])[i], (*(*costV[0])[1])[i-1] + (*rgbV[j])[i]));
                (*costV[j])[1]->push_back(min((*(*costV[2])[0])[i-1] + (*rgbV[j])[i], (*(*costV[2])[1])[i-1] + (*rgbV[j])[i]));
            } 
            else if (j == 2) {
                (*costV[j])[0]->push_back(min((*(*costV[0])[0])[i-1] + (*rgbV[j])[i], (*(*costV[0])[1])[i-1] + (*rgbV[j])[i]));
                (*costV[j])[1]->push_back(min((*(*costV[1])[0])[i-1] + (*rgbV[j])[i], (*(*costV[1])[1])[i-1] + (*rgbV[j])[i]));
            }
            // printf("%d, %d\n", (*(*costV[j])[0])[i], (*(*costV[j])[1])[i]);
        }
    }

    int res = INT32_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            res = min(res, (*(*costV[i])[j])[N-1]);
        }
    }

    printf("%d\n", res);
}