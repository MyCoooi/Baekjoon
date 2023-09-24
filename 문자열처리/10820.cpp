#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    char input[101];
    while(cin.getline(input, 101, '\n')) {
        int res[4] = {0, }; // 소문자, 대문자, 숫자, 공백
        for (char c : input) {
            if (c == '\0')
                break;
            if (c == ' ')
                res[3] += 1;
            else if (isupper(c))
                res[1] += 1 ;
            else if (islower(c))
                res[0] += 1;
            else
                res[2] += 1;
        }
        for (int i : res) {
            cout << i << ' ';
        }
        cout << '\n';

        input[101] = {};
    }

}