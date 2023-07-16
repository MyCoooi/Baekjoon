#include <iostream>
using namespace std;

int score[302][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int stair_num;
    cin >> stair_num;

    for(int i = 1; i <= stair_num; i++)
        cin >> score[i][0];

    score[stair_num][1] = score[stair_num][0];
    score[stair_num][2] = score[stair_num][0];
    score[0][0] = 0;

    for(int i = stair_num-1; i >= 0; i--) {
        if (i == 0) {
            score[i][1] = max(score[i+1][1], score[i+1][2]);
        }
        else if (i != stair_num-2)
            score[i][1] = score[i+1][2] + score[i][0];

        if (i != stair_num-1)
            score[i][2] = max(score[i+2][1], score[i+2][2]) + score[i][0];

        if (i == stair_num-2 && i != 0)
            score[i][1] = score[i][2];
        if (i == stair_num-1 && i != 0)
            score[i][2] = score[i][1];
    }
    
    cout << max(score[0][1], score[0][2]);
}