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
    long long k, key, recreate_cable_count = 0; //k = 이미 가지고 있는 랜선의 개수 n = 필요한 랜선의 개수
    long long n;
    unsigned int max_key = ~0u, minkey = 0, max_key_2;  //모든비트1
    
    long long min_temp_size = 0 , max_temp_size = 0;
    int temp_n;

    cin >> k >> n;
    long* arr = new long[k]; //각각의 케이블 길이 입력받을 배열선언
    int i, j;
    for (i = 0; i < k; ++i) {
        cin >> *(arr + i);  //케이블 길이 입력받기
    }

    for (i = 0; i < k; ++i) {
        recreate_cable_count = 0;
        for (j = 0; j < k; ++j) {
            recreate_cable_count += arr[j] / arr[i];// 800/120 + 500/120 + 400/120 + ....  
        }
        
        if (recreate_cable_count < n) { //나누었을때 n보다 작게 나오는것들 중에서 가장 작은놈 찾기
            if (max_key > arr[i])
                max_key = arr[i];
        }
        else if (recreate_cable_count == n) {//나누었을때 n이면 그때의 나눈값 출력, 이때 나눈값보다 큰 값으로 나눴으면 무조건 n보다 작아지기 때문
            cout << arr[i];
            return 0;
        }

    }

    max_temp_size = max_key;
    while (1) {
        key = (max_key + minkey) / 2; //0 1
        if (key == 0) { //전선의 길이가 1cm일때 key가 0이됨 이때 처리해주기
            cout << 1; return 0;
        }
        recreate_cable_count = 0;
        //std::cout << 1; //test
        for (i = 0; i < k; ++i) {
            recreate_cable_count += arr[i] / key;// 800/120 + 500/120 + 400/120 + .... 의 결과값
        }
        #ifdef DEBUG //디버그
        std::cout << key << " " << recreate_cable_count << endl; //test
        Sleep(1000);
        #endif

        if (recreate_cable_count == n) { //나눈값의 합이 n과 같다면, 빠져나오고 그 값을 n이 될 수 있는 최솟값으로 설정
            min_temp_size = key;
            break;
        }    //키값으로 나눴을떄 n이랑 같다면 
        else if (recreate_cable_count < n) { //이진탐색
            max_key = key-1;
        }
        else { minkey = key+1; } //이진탐색

        if (key == (max_key + minkey) / 2){ //탐색에 n이 없을때, 이진 탐색의 특징상, 오른쪽에 있는 값, 즉 n보다 큰 값을 가져오게 된다.
            cout << key;
            return 0;
        }

    }
    //std::cout << endl << max_key_2 << " " << minkey;
   /*while (1) {
        key = (max_key_2 + minkey) / 2;
        recreate_cable_count = 0;
        for (i = 0; i < k; ++i) {
            recreate_cable_count += arr[i] / key;// 800/120 + 500/120 + 400/120 + .... 키값으로 나눈뒤 n이랑 비교하기
        }
        #ifdef DEBUG
        std::cout << key << " " << recreate_cable_count << endl; //test
        Sleep(1000);
        #endif
        if (recreate_cable_count == n-1) {
            max_temp_size = key;
            break;
        }    //키값으로 나눴을떄 n이랑 같다면 
        else if (recreate_cable_count < n-1) {
            max_key_2 = key - 1;
        }
        else { minkey = key + 1; }
    } */
    //std::cout << min_temp_size << " " << max_temp_size; //test
    for(i = min_temp_size; i <= max_temp_size; ++i){ //min ~ max까지 하나하나 조사하면서 n값이 바뀌는 곳 즉 n일때 최대값을 찾기
        temp_n = 0;
        for (j = 0; j < k; ++j) {           
            temp_n += arr[j] / i;// 800/120 + 500/120 + 400/120 + .... 
        }
        if (n != temp_n) { std::cout << i-1; return 0; } // 값이 변화했을때 그 값의 -1한 값이 n일때 최댓값이다.
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
