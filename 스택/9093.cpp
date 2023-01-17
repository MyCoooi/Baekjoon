#include <iostream>
#include <string>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    cin.ignore(); // 버퍼의 개행문자 제거
    while (testCase--) {
        string s;
        getline(cin, s); // 한 줄 읽어오기

        int previous = 0; // 이전 단어의 위치(인덱스)
        while (true) {
            string sub;
            int idx = s.find(' ', previous); // 공백 위치(인덱스)
            if (idx == string::npos) { 
                sub = s.substr(previous);
                for (int i = sub.length()-1; i >= 0; i--) cout << sub[i];
                cout << ' ';
                break;
            }
            else {
                sub = s.substr(previous, idx-previous);
                previous = idx+1;

                for (int i = sub.length()-1; i >= 0; i--) cout << sub[i];
                cout << ' ';
            }
        }
        cout << '\n';
    }
}