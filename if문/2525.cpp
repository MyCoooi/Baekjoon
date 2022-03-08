#include <iostream>
using namespace std;

int main() {
    int hour, minute, baking_time;
    cin >> hour >> minute;
    cin >> baking_time;

    int in_minute = hour * 60 + minute;
    int finish_time = in_minute + baking_time;
    if (finish_time >= 24 * 60) finish_time = finish_time - 24 * 60;
    cout << finish_time / 60 << " " << finish_time % 60;
}