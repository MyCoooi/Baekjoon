#include <iostream>
#include <vector>
using namespace std;

class Deque {
private:
    vector<int> v;
public:
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size();
    int empty();
    int front();
    int back();
};

void Deque::push_front(int x) {
    (this->v).insert((this->v).begin()+0, x);
}
void Deque::push_back(int x) {
    (this->v).push_back(x);
}
int Deque::pop_front() {
    int res = -1;
    if (!this->empty()) {
        res = v.front();
        v.erase(v.begin());
    }
    return res;
}
int Deque::pop_back() {
    int res = -1;
    if (!this->empty()) {
        res = v.back();
        v.pop_back();
    }
    return res;
}
int Deque::size() {
    return v.size();
}
int Deque::empty() {
    return v.empty();
}
int Deque::front() {
    if  (!this->empty())
        return v.front();
    else return -1;
}
int Deque::back() {
    if (!this->empty())
        return v.back();
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Deque dq;
    while(N--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push_front") {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "push_back") {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "pop_front") {
            cout << dq.pop_front()  << "\n";
        }
        else if (cmd == "pop_back") {
            cout << dq.pop_back() << "\n";
        }
        else if (cmd == "size") {
            cout << dq.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << dq.empty() << "\n";
        }
        else if (cmd == "front") {
            cout << dq.front() << "\n";
        }
        else if (cmd == "back") {
            cout << dq.back() << "\n";
        }
    }

}