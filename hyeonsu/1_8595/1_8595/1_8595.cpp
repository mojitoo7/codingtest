#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    cin >> length;

    string code;
    cin >> code;

    long long sum = 0;
    int secret_num = 0;
    int cnt = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(code[i])) {
            cnt++;
            if (cnt > 6) {
                secret_num = 0;
                cnt = 0;
            }
            else {
                secret_num = secret_num * 10 + (code[i] - '0');
            }
        }
        else {
            sum += secret_num;
            secret_num = 0;
            cnt = 0;
        }
    }


    sum += secret_num;

    cout << sum << endl;
    return 0;
}
