#include<iostream>
#include<vector>
using namespace std;

int main() {
    const int sub = 2;
    const int num = 5;

    int test[sub][num] = {
        {61, 17, 26, 31, 74}, 
        {48, 63, 82, 20, 48}
    };

    for (int i = 0; i < num; i++) {
        cout << i + 1 << "人目の国語の点数は" << test[0][i] << endl;
        cout << i + 1 << "人目の数学の点数は" << test[1][i] << endl;
    }

}