#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> op; // 연산을 담는 벡터
stack<int> s;

void myPush(int n);
void myPop();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int prevN = 0;
    int inputN;
    for (int i = 0; i < N; i++) {
        cin >> inputN;

        if (inputN > prevN) {
            for (int k = prevN+1; k <= inputN; k++) {
                myPush(k);
            }
            myPop();
            prevN = inputN;
        } else {
            if (s.top() == inputN) myPop();
            else {
                cout << "NO";
                exit(0);
            }
        } // else 문
    }

    for (auto o : op) cout << o << '\n';
}

void myPush(int n) {
    s.push(n);
    op.push_back('+');
}

void myPop() {
    s.pop();
    op.push_back('-');
}