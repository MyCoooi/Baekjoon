#include <iostream>
using namespace std;

int fiboCount_0[41] = {0,};
int fiboCount_1[41] = {0,};

int FiboCount_0(int n) {
    if (n == 0) {
        fiboCount_0[n] = 1;
    }
    else if (n == 1) fiboCount_0[n] = 0;
    else if (fiboCount_0[n] == 0) {
        fiboCount_0[n] = FiboCount_0(n-1) + FiboCount_0(n-2);
    }
    return fiboCount_0[n];
}

int FiboCount_1(int n) {
    if (n == 1) {
        fiboCount_1[n] = 1;
    }
    else if (n == 0) fiboCount_1[n] = 0;
    else if (fiboCount_1[n] == 0) {
        fiboCount_1[n] = FiboCount_1(n-1) + FiboCount_1(n-2);
    }
    return fiboCount_1[n];
}

int main() {
    int Testcase;
    cin >> Testcase;

    for(int i = 0; i < Testcase; i++) {
        int N;
        cin >> N;
        cout << FiboCount_0(N) << " " << FiboCount_1(N) << endl;        
    }
}