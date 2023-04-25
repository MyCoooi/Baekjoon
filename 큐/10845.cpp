#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
private:
    vector<int> v;
public:
    void myPush(int x);
    int myPop();
    int mySize();
    int myEmpty();
    int myFront();
    int myBack();
};

void MyQueue::myPush(int x) {
    (this->v).push_back(x);
}
int MyQueue::myPop() {
    if (!this->myEmpty()) {
        int n = (this->v)[0];
        (this->v).erase((this->v).begin());
        return n;
    }
    else return -1;
}
int MyQueue::mySize() {
    return (this->v).size();
}
int MyQueue::myEmpty() {
    return (this->v).empty();
}
int MyQueue::myFront() {
    if (!this->myEmpty()) return (this->v)[0];
    else return -1;
}
int MyQueue::myBack() {
    if (!this->myEmpty()) return (this->v)[(this->v).size()-1];
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string cmd;
    MyQueue q;
    while(N--) {
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q.myPush(x);
        }
        else if (cmd == "pop") {
            cout << q.myPop() << '\n';
        }
        else if (cmd == "size") {
            cout << q.mySize() << '\n';
        }
        else if (cmd == "empty") {
            cout << q.myEmpty() << '\n';
        }
        else if (cmd == "front") {
            cout << q.myFront() << '\n';
        }
        else if (cmd == "back") {
            cout << q.myBack() << '\n';
        }
    }
}