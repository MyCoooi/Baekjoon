#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    getline(cin,s);

    int M;
    cin >> M;

    stack<char> left;
    stack<char> right;
    for (int i = 0; i < s.size(); i++) left.push(s[i]);

    while(M--) {
        char command;
        cin >> command;

        if (command == 'L') { // 커서를 왼쪽으로 이동
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (command == 'D') { // 커서를 오른쪽으로 이동
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (command == 'B') { // 커서의 왼쪽 문자 삭제
            if (!left.empty()) left.pop();
        }
        else if (command == 'P') { // 커서의 왼쪽에 문자 추가
            char c;
            cin >> c;
            left.push(c);
        }
    } 

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}