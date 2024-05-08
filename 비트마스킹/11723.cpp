#include <iostream>
#include <string>
using namespace std;

bool arr[21];

int check(int x) {
    if (arr[x]) return 1;
    else return 0;
}

void add(int x) {
    if(!arr[x]) arr[x] = true;
}

void remove(int x) {
    arr[x] = false;
}

void toggle(int x) {
    if (arr[x]) arr[x] = false;
    else arr[x] = true;
}

void all() {
    for (int i = 1; i <= 20; i++) arr[i] = true;
}

void empty() {
    for (int i = 1; i <= 20; i++) arr[i] = false;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int M; // 연산의 수
    cin >> M;

    cin.ignore();
    for (int i = 0; i < M; i++) {
        string cmd;
        int data = -1;
        cin >> cmd;
        if (cmd != "all" && cmd != "empty") cin >> data;
        
        if (cmd == "add") {
            add(data);
        }
        else if (cmd == "remove") {
            remove(data);
        }
        else if (cmd == "check") {
            cout << check(data) << "\n";
        }
        else if (cmd == "toggle") {
            toggle(data);
        }
        else if (cmd == "all") {
            all();
        }
        else if (cmd == "empty") {
            empty();
        }

    }
}