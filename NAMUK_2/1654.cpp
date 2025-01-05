// namuk_2week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define DEBUG
#ifdef DEBUG
#include <Windows.h>
#endif
using namespace std;

int main()
{
    long long k, key, recreate_cable_count = 0; //k = �̹� ������ �ִ� ������ ���� n = �ʿ��� ������ ����
    long long n;
    unsigned int max_key = ~0u, minkey = 0, max_key_2;  //����Ʈ1
    
    long long min_temp_size = 0 , max_temp_size = 0;
    int temp_n;

    cin >> k >> n;
    long* arr = new long[k]; //������ ���̺� ���� �Է¹��� �迭����
    int i, j;
    for (i = 0; i < k; ++i) {
        cin >> *(arr + i);  //���̺� ���� �Է¹ޱ�
    }

    for (i = 0; i < k; ++i) {
        recreate_cable_count = 0;
        for (j = 0; j < k; ++j) {
            recreate_cable_count += arr[j] / arr[i];// 800/120 + 500/120 + 400/120 + ....  
        }
        
        if (recreate_cable_count < n) { //���������� n���� �۰� �����°͵� �߿��� ���� ������ ã��
            if (max_key > arr[i])
                max_key = arr[i];
        }
        else if (recreate_cable_count == n) {//���������� n�̸� �׶��� ������ ���, �̶� ���������� ū ������ �������� ������ n���� �۾����� ����
            cout << arr[i];
            return 0;
        }

    }

    max_temp_size = max_key;
    while (1) {
        key = (max_key + minkey) / 2; //0 1
        if (key == 0) { //������ ���̰� 1cm�϶� key�� 0�̵� �̶� ó�����ֱ�
            cout << 1; return 0;
        }
        recreate_cable_count = 0;
        //std::cout << 1; //test
        for (i = 0; i < k; ++i) {
            recreate_cable_count += arr[i] / key;// 800/120 + 500/120 + 400/120 + .... �� �����
        }
        #ifdef DEBUG //�����
        std::cout << key << " " << recreate_cable_count << endl; //test
        Sleep(1000);
        #endif

        if (recreate_cable_count == n) { //�������� ���� n�� ���ٸ�, ���������� �� ���� n�� �� �� �ִ� �ּڰ����� ����
            min_temp_size = key;
            break;
        }    //Ű������ �������� n�̶� ���ٸ� 
        else if (recreate_cable_count < n) { //����Ž��
            max_key = key-1;
        }
        else { minkey = key+1; } //����Ž��

        if (key == (max_key + minkey) / 2){ //Ž���� n�� ������, ���� Ž���� Ư¡��, �����ʿ� �ִ� ��, �� n���� ū ���� �������� �ȴ�.
            cout << key;
            return 0;
        }

    }
    //std::cout << endl << max_key_2 << " " << minkey;
   /*while (1) {
        key = (max_key_2 + minkey) / 2;
        recreate_cable_count = 0;
        for (i = 0; i < k; ++i) {
            recreate_cable_count += arr[i] / key;// 800/120 + 500/120 + 400/120 + .... Ű������ ������ n�̶� ���ϱ�
        }
        #ifdef DEBUG
        std::cout << key << " " << recreate_cable_count << endl; //test
        Sleep(1000);
        #endif
        if (recreate_cable_count == n-1) {
            max_temp_size = key;
            break;
        }    //Ű������ �������� n�̶� ���ٸ� 
        else if (recreate_cable_count < n-1) {
            max_key_2 = key - 1;
        }
        else { minkey = key + 1; }
    } */
    //std::cout << min_temp_size << " " << max_temp_size; //test
    for(i = min_temp_size; i <= max_temp_size; ++i){ //min ~ max���� �ϳ��ϳ� �����ϸ鼭 n���� �ٲ�� �� �� n�϶� �ִ밪�� ã��
        temp_n = 0;
        for (j = 0; j < k; ++j) {           
            temp_n += arr[j] / i;// 800/120 + 500/120 + 400/120 + .... 
        }
        if (n != temp_n) { std::cout << i-1; return 0; } // ���� ��ȭ������ �� ���� -1�� ���� n�϶� �ִ��̴�.
        //std::cout << temp_n << endl; //test
    }

    delete[] arr;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
