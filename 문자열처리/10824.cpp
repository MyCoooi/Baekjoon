#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ab = to_string(a) + to_string(b);
    string cd = to_string(c) + to_string(d);

    long long res = stoll(ab) + stoll(cd);
    cout << res << '\n';
}