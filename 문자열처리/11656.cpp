#include <iostream>
#include <algorithm>
using namespace std;

string suffixArr[1001];

bool compare(string a, string b) {
    int l = a.length() < b.length() ? a.length() : b.length();

    for (int i = 0; i < l; i++) {
        if (i == l - 1 && a[i] == b[i]) {
            return a.length() < b.length();
        }
        else if (a[i] == b[i])
            continue;
        else {
            return a[i] < b[i];
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) { // input의 모든 접미사 구한 후 suffixArr에 저장
        suffixArr[i] = input.substr(i, input.length() - i);
    }

    sort(suffixArr, suffixArr + input.length(), compare);
    for (int i = 0; i < input.length(); i++) {
        cout << suffixArr[i] << '\n';
    }
}