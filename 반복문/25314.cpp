#include <iostream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N / 4; i++)
        cout << "long ";
    cout << "int\n";
}