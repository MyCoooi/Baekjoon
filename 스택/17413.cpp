#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string inS; // 문자열을 한번에 받아오는게 장치 입출력 횟수를 줄여줘서 시간이 빠를 듯.
    getline(cin, inS);

    bool isTag = false;
    string outS; // 출력할 문자열. 문자열을 한번에 출력하기 위해
    stack<char> s; // 단어를 저장하는 스택

    for (int i = 0; i < inS.length(); i++) {
        // 태그인지 아닌지 판별
        if (inS[i] == '<')
            isTag = true;
        else if (inS[i] == '>')
            isTag = false;

        if (isTag || inS[i] == ' ' || inS[i] == '>') {
            while (!s.empty()) {
                outS.push_back(s.top());
                s.pop();
            }
            outS.push_back(inS[i]);
        } else {
            // 단어 뒤집기
            s.push(inS[i]);
        }
    }

    while (!s.empty()) {
        outS.push_back(s.top());
        s.pop();
    }
    cout << outS << '\n';
}