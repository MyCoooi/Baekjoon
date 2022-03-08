#include <iostream>
using namespace std;

int main() {
    int hour, minute;
    cin >> hour >> minute;

    int day_in_minute = hour * 60 + minute;
    int day_in_minute_45ago;
    if (day_in_minute < 45) day_in_minute_45ago = 24*60 + (day_in_minute - 45);
    else day_in_minute_45ago = day_in_minute - 45;
    cout << day_in_minute_45ago / 60 << " " << day_in_minute_45ago % 60;
    cin >> hour;
}