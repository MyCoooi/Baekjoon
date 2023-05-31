#include <iostream>
#include <stack>
using namespace std;

void calc(char myOperand);

stack<double> st;
int operand[27]; // 알파벳에 해당하는 피연산자

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N; // 피연산자 개수
    string notation; cin >> notation; // 후위 표기식

    for (int i = 0; i < N; i++)
        cin >> operand[i];
    
    for (int i = 0; i < notation.length(); i++) {
        if (notation[i] == '*' || notation[i] == '/' || notation[i] == '+' || notation[i] == '-')
            calc(notation[i]);
        else
            st.push(operand[notation[i] - 'A']); // 아스키 코드로 변환
    }
    cout<<fixed;
    cout.precision(2); // 소수점 2째 자리까지 출력
    cout << st.top();
}

void calc(char myOperand) {
    double first_operand = st.top();
    st.pop();
    double second_operand = st.top();
    st.pop();

    switch (myOperand) {
        case '*':
            st.push(second_operand * first_operand);
            break;
        case '/':
            st.push(second_operand / first_operand);
            break;
        case '+':
            st.push(second_operand + first_operand);
            break;
        case '-':
            st.push(second_operand - first_operand);
            break;
    }
}