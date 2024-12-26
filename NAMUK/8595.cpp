// baekjoon_8595.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>


using namespace std;

int power_of_10(int power) {
    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= 10;
    }
    return result;
}
int main()
{
    int size_of_string = 0;
    int sum = 0;
    string origin_str;
    string sum_string;
    scanf("%d", &size_of_string);
    cin.ignore();
    getline(cin, origin_str);
    //c 방식으로 fgets를 할 수도 있음 아니면 string형식을 지원하는 cin으로
    
    if (origin_str.size() < size_of_string) {
        size_of_string = origin_str.size();
    }
    for(int i =0; i< size_of_string; ++i)
    {
        if ('0' <= origin_str[i] && origin_str[i] <='9') {
            sum_string += origin_str[i];
        }
        else {
            if (sum_string.size() < 6) {
                for (int j = 0; j < sum_string.size(); ++j) {
                    sum += (sum_string[sum_string.size() - j-1] - '0') * power_of_10(j);
                }
            }
            sum_string = "";
        }
    }
    if (sum_string.size() < 6) {
        for (int j = 0; j < sum_string.size(); ++j) {
            sum += (sum_string[sum_string.size() - j - 1] - '0') * power_of_10(j);
        }
    }
    cout << sum;
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
