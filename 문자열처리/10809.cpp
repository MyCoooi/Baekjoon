#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    string input;
    cin >> input;
    for (int i = 97; i <= 122; i++) {
        if (input.find(char(i)) != string::npos) {
            cout << input.find(char(i)) << " ";
        }
        else
            cout << -1 << " ";
    }
}