#include <iostream>
#include <stack>
using namespace std;

int count[1000001] = {0,}; // 등장 횟수 카운트
int sequence[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> st;
    int N;
    cin >> N;
    // 등장 횟수 카운트
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        count[sequence[i]] += 1;
    }
    // 오등큰수 찾기
    for (int i = 0; i < N; i++) {
        while (!st.empty()) {
            int top = st.top();
            if (count[sequence[i]] > count[sequence[top]]) {
                sequence[top] = sequence[i];
                st.pop();
            }
            else {
                break;
            }
        }
        st.push(i);
    }
    while(!st.empty()) {
        sequence[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < N; i++)
        cout << sequence[i] << " ";
}