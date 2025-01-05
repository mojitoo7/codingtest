// 2839.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int kg;
    std::cin >> kg;
    
    if (kg % 5 == 0) {
        std::cout << kg / 5; return 0;
    }
    else if (kg % 5 == 1 && kg > 5) cout << kg / 5 + 1;
    else if (kg % 5 == 2 && kg > 10) cout << kg / 5 + 2;
    else if (kg % 5 == 3) cout << kg / 5 +1 ;
    else if (kg % 5 == 4 && kg > 5) cout << kg / 5 + 2;
    else cout << -1;
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
