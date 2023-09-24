#include <iostream>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);

    char input[101];
    cin.getline(input, 101, '\n');
    char res[101] = {};
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\0') {
            res[i] = input[i];
            break;
        }
        else {
            if (input[i] >= 'a' && input[i] <= 'z') {
                int asciiCode = int(input[i]) + 13;
                if (asciiCode > int('z'))
                    asciiCode = int('a') + (asciiCode % int('z')) - 1;
                res[i] = char(asciiCode);
            }
            else if (input[i] >= 'A' && input[i] <= 'Z') {
                int asciiCode = int(input[i]) + 13;
                if (asciiCode > int('Z'))
                    asciiCode = int('A') + (asciiCode % int('Z')) - 1;
                res[i] = char(asciiCode);
            }
            else {
                res[i] = input[i];
            }
        }
    }
    cout << res << '\n';
}