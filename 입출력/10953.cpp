#include <iostream>
using namespace std;

int split_and_sum(string s, char d) {
	int sum = 0;
	int idx = s.find(d, 0);
	if (idx == 0) return -1;
	else {
		sum += s[idx - 1] - '0' + s[idx + 1] - '0';
		return sum;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		cout << split_and_sum(input, ',') << endl;
	}
}