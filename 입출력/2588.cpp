#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	short a, b;
	cin >> a >> b;

	for (int mB = 1; mB <= 100; mB *= 10) {
		short tmp = 0, carry = 0, mul;
		for (int mA = 1; mA <= 100; mA *= 10) {
			mul = ((b / mB) % 10) * ((a / mA) % 10) + carry;
			tmp += mA * (mul % 10);
			carry = ((mul / 10) == 0) ? 0 : mul / 10;
		}
		tmp += carry * 1000;
		cout << tmp << endl;
		sum += tmp*mB;
	}
	cout << sum << endl;
}
/*
ex) 472
(472/1) % 10 => 2
(472/10) % 10 => 7
(472/100) % 10 => 4
*/