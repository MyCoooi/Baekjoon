#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> s; // 스택
    int stripTotalN = 0; // 잘려진 쇠 막대 조각의 총 갯수

    // 입력 받기
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            s.push(i);
        }
        else if (input[i] == ')') {
            if (s.top() == i-1) { // 레이저라면
                s.pop();
                stripTotalN += s.size();
            } else { // 쇠막대의 끝이라면
                s.pop();
                stripTotalN++;
            }
        }
    }
    cout << stripTotalN;
}