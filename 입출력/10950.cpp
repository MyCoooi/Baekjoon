#include <iostream>
using namespace std;

int main() {
	int Test_num = 0;
	cin >> Test_num;
	
	for (int i = 0; i < Test_num; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		cout << a + b << endl;
	}
}