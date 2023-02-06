#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int testCase;
    cin >> testCase;
    cin.ignore();

    while(testCase--) {
        stack<char> openingBracketStack;
        string s;
        getline(cin, s);
        bool check = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (openingBracketStack.empty()) {
                    check = false;
                    break;
                }
                else {
                    openingBracketStack.pop();
                }
            }
            else if (s[i] == '(')
                openingBracketStack.push('(');
        }
        
        if (check&&openingBracketStack.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}