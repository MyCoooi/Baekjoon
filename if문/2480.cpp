#include <iostream>
using namespace std;

int main() {
    int dices[3] = {0,};
    cin >> dices[0] >> dices[1] >> dices[2];

    int reward;
    if (dices[0] == dices[1] && dices[0] == dices[2] && dices[1] == dices[2]) reward = 10000 + dices[0] * 1000;
    else if (dices[0] == dices[1]) reward = 1000 + dices[0] * 100;
    else if (dices[0] == dices[2]) reward = 1000 + dices[0] * 100;
    else if (dices[1] == dices[2]) reward = 1000 + dices[1] * 100;
    else {
        int max = dices[0];
        for (int i = 0; i < 3; i++) {
            if (max < dices[i]) max = dices[i];
        }
        reward = max * 100;
    }
    cout << reward << endl;
}