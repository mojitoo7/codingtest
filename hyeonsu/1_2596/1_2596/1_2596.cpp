#include <iostream>
#include <string>
using namespace std;

int main() {
    string A = "000000";
    string B = "001111";
    string C = "010011";
    string D = "011100";
    string E = "100110";
    string F = "101001";
    string G = "110101";
    string H = "111010";
    string patterns[8] = { A, B, C, D, E, F, G, H };

    int len;
    cin >> len;

    string message;
    cin >> message;


    string answer;

    for (int i = 0; i < len; i++) {
        string temp = message.substr(i * 6, 6);
        bool matched = false;

        if (temp == A) {
            answer.append("A");
            matched = true;
        }
        else if (temp == B) {
            answer.append("B");
            matched = true;
        }
        else if (temp == C) {
            answer.append("C");
            matched = true;
        }
        else if (temp == D) {
            answer.append("D");
            matched = true;
        }
        else if (temp == E) {
            answer.append("E");
            matched = true;
        }
        else if (temp == F) {
            answer.append("F");
            matched = true;
        }
        else if (temp == G) {
            answer.append("G");
            matched = true;
        }
        else if (temp == H) {
            answer.append("H");
            matched = true;
        }

        if (!matched) {
            for (int j = 0; j < 8; j++) {
                int diff = 0;
                for (int k = 0; k < 6; k++) {
                    if (temp[k] != patterns[j][k]) {
                        diff++;
                    }
                }
                if (diff <= 1) {
                    answer.push_back('A' + j); //patterns[j]로 하니까 틀림
                    matched = true;
                    break;
                }
            }
        }

        if (!matched) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << answer << endl;

    return 0;
}