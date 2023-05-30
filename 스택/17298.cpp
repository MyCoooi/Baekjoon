#include <iostream>
#include <stack>
using namespace std;

int mem[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> st; // <- 스택 추가
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> mem[i];

        while(!st.empty()) {
            int idx = st.top();
            if (mem[idx] >= mem[i]) // mem[i]가 오큰수가 아닐 때
                break;
            else { // mem[i]가 오큰수일 때
                mem[idx] = mem[i];
                st.pop();
            }
        }
        st.push(i);
    }
    while(!st.empty()) {
        mem[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++)
        cout << mem[i] << ' ';
}