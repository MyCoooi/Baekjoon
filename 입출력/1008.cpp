#include <iostream>
#include <iomanip> // cout���� ��µǴ� �⺻ ���е��� ��������. std:cout�� �⺻ ���е��� 6.
using namespace std;

int main() {
	short b; int a;
	cin >> a >> b;
	cout << setprecision(10);
	cout << (1.0 * a) / b << endl;	
}