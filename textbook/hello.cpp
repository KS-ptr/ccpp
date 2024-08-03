#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    cout << "Hello, C++!\n";
    cout << "Let's study C++!\n";
    cout << 0b10101 << "\n";

    int num1 = 3.14;
    float num2 = 3.14;

    // cout << num1 << endl;
    // cout << num2;

    const float pi = 3.1415;
    cout << pi << endl;

    string str = "The World Belongs to No One.";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;

    return 0;
} 