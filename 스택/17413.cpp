#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string inS; // ���ڿ��� �ѹ��� �޾ƿ��°� ��ġ ����� Ƚ���� �ٿ��༭ �ð��� ���� ��.
    getline(cin, inS);

    bool isTag = false;
    string outS; // ����� ���ڿ�. ���ڿ��� �ѹ��� ����ϱ� ����
    stack<char> s; // �ܾ �����ϴ� ����

    for (int i = 0; i < inS.length(); i++) {
        // �±����� �ƴ��� �Ǻ�
        if (inS[i] == '<')
            isTag = true;
        else if (inS[i] == '>')
            isTag = false;

        if (isTag || inS[i] == ' ' || inS[i] == '>') {
            while (!s.empty()) {
                outS.push_back(s.top());
                s.pop();
            }
            outS.push_back(inS[i]);
        } else {
            // �ܾ� ������
            s.push(inS[i]);
        }
    }

    while (!s.empty()) {
        outS.push_back(s.top());
        s.pop();
    }
    cout << outS << '\n';
}