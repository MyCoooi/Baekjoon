#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> operatorSt; // 연산자 스택

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    string input;
    cin >> input;
    
    int curIdx = 0;

    while(curIdx < input.length()) {
        if (input[curIdx] >= 'A' && input[curIdx] <= 'Z') {
            printf("%c", input[curIdx]);
        }
        else if (input[curIdx] == ')') {
            while(!operatorSt.empty() && operatorSt.top() != '(') {
                printf("%c", operatorSt.top());
                operatorSt.pop();
            }
            if (!operatorSt.empty() && operatorSt.top() == '(') {
                operatorSt.pop();
            }
        }
        else if (input[curIdx] == '('){
            operatorSt.push(input[curIdx]);
        }
        if (input[curIdx] == '+' || input[curIdx] == '-' || input[curIdx] == '*' || input[curIdx] == '/') {
            if (operatorSt.empty() || operatorSt.top() == '(')
                operatorSt.push(input[curIdx]);
            else {
                if (input[curIdx] == '+' || input[curIdx] == '-') {
                    while(!operatorSt.empty() && operatorSt.top() != '(') {
                        printf("%c", operatorSt.top());
                        operatorSt.pop();
                    }
                    operatorSt.push(input[curIdx]);
                }
                else if (input[curIdx] == '*' || input[curIdx] == '/') {
                    if (operatorSt.top() == '+' || operatorSt.top() == '-') {
                        operatorSt.push(input[curIdx]);
                    }
                    else if (operatorSt.top() == '*' || operatorSt.top() == '/') {
                        printf("%c", operatorSt.top());
                        operatorSt.pop();
                        operatorSt.push(input[curIdx]);
                    }
                }
            }
        }
        curIdx++;
    }
    while (!operatorSt.empty()) {
        printf("%c", operatorSt.top());
        operatorSt.pop();
    }
}