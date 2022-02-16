#include <iostream>
using namespace std;

int main() {
	const int size = 26;
	int alphabet_arr[size] = { 0, };
	char input[101] = { 0, };
	cin.getline(input, 101, '\n');
	for (char c : input) {
		if (c != '\0') alphabet_arr[(int)c - 97]++;
		else break;
	}
	for (int i = 0; i < size; i++) {
		cout << alphabet_arr[i] << " ";
	}
}