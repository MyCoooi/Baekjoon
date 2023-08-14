#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int memSize = 102;
int w(int a, int b, int c);
float mem[memSize][memSize][memSize]; // a, b, c

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    fill(mem[0][0], mem[memSize][0], 0.5);

    while(!cin.eof()) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1){
            break;
        }
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}

int w(int a, int b, int c) {
    if (mem[a+50][b+50][c+50] != 0.5) {
        return mem[a+50][b+50][c+50];
    }
    else {
        if (a <= 0 || b <= 0 || c <= 0) {
            mem[a+50][b+50][c+50] = 1.0;
            return mem[a+50][b+50][c+50];
        }
        else if (a > 20 || b > 20 || c > 20) {
            mem[a+50][b+50][c+50] = w(20, 20, 20);
            return mem[a+50][b+50][c+50];
        }
        else if (a < b && b < c) {
            mem[a+50][b+50][c+50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
            return mem[a+50][b+50][c+50];
        }
        else {
            mem[a+50][b+50][c+50] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
            return mem[a+50][b+50][c+50];
        }
    }
}