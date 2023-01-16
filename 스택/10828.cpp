#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int arr[10001];
    int stackSize = 0;
public:
    Stack();
    void push(int x);
    int pop();
    int size();
    int empty();
    int top();
};

Stack::Stack() {
    for (int i = 0; i < 10001; i++) this->arr[i] = -1; // 초기화
}
void Stack::push(int x) {
    this->arr[this->stackSize] = x;
    this->stackSize += 1;
}
int Stack::pop() {
    if (this->empty()) return -1;
    else {
        int topNum = this->arr[this->stackSize-1];
        this->arr[this->stackSize-1] = -1;
        this->stackSize -= 1;
        return topNum;
    }
}
int Stack::size() {
    return this->stackSize;
}
int Stack::empty() {
    if (this->stackSize==0) return 1;
    else return 0;
}
int Stack::top() {
    if (this->empty()) return -1;
    else return this->arr[this->stackSize-1];
}

int main() {
    int commandNum; // 명령어 갯수
    cin >> commandNum;

    Stack s;
    while(commandNum--) {
        string command;
        cin >> command;

        if (command == "top") cout << s.top() << '\n';
        else if (command == "pop") cout << s.pop() << '\n';
        else if (command == "size") cout << s.size() << '\n';
        else if (command == "empty") cout << s.empty() << '\n';
        else { // 명령어가 push X인 경우
            int x;
            cin >> x;
            s.push(x);
        }
    }
}