#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<long long> cables(K);
    long long max_length = 0;

    for (int i = 0; i < K; i++) {
        cin >> cables[i];
        max_length = max(max_length, cables[i]); //���� ��� ����
    }

    long long low = 1;  
    long long high = max_length; 
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2; // �߰���
        long long count = 0;

        for (long long cable : cables) {
            count += cable / mid;
        }

        if (count >= N) {  
            result = mid; 
            low = mid + 1; //�߰��� ������
        }
        else {  //���� ���� ���� x
            high = mid - 1; //�߰��� �Ʒ�����
        }
    }

    cout << result << endl;
    return 0;
}
