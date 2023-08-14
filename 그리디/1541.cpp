#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    string input;
    cin >> input;

    vector<string> operand;

    char separator = '-';
    istringstream iss(input);
    string str_buf;
    while (getline(iss, str_buf, separator)) {
        operand.push_back(str_buf);
    }

    for(int i = 0; i < operand.size(); i++) {
        char separator = '+';
        int sum = 0;
        istringstream iss(operand[i]);
        string str_buf;
        while (getline(iss, str_buf, separator))
            sum += stoi(str_buf);
        operand[i] = to_string(sum);
    }

    int res = stoi(operand[0]);
    for(int i = 1; i < operand.size(); i++) {
        res -= stoi(operand[i]);
    }
    printf("%d\n", res);
}

