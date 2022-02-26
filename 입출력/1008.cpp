#include <iostream>
#include <iomanip> // cout에서 출력되는 기본 정밀도를 재정의함. std:cout의 기본 정밀도는 6.
using namespace std;

int main() {
	short b; int a;
	cin >> a >> b;
	cout << setprecision(10);
	cout << (1.0 * a) / b << endl;	
}