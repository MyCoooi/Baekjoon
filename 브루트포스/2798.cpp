#include <iostream>
using namespace std;

int main() {
	int cardNum, m;
	cin >> cardNum >> m;
	int* nums = new int[cardNum];

	for (int i = 0; i < cardNum; i++) {
		cin >> nums[i];
	}

	int sum = 0;
	for (int i = 0; i < cardNum-2; i++) {
		for (int k = i + 1; k < cardNum-1; k++) {
			for (int n = k + 1; n < cardNum; n++) {
				int tmp = nums[i] + nums[k] + nums[n];
				if (tmp <= m && tmp > sum) sum = tmp;
			}
		}
	}
	cout << sum << endl;
}