#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int x, n;
    cin >> x >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        res += a * b;
    }
    if (res == x)
        printf("Yes\n");
    else
        printf("No\n");

}