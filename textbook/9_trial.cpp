#include<iostream>
using namespace std;

int main() {
    const int num = 5;
    int test[num];

    cout << num << "人の点数を入力してください。" << endl;
    for (int i = 0; i < num; i++) {
        cin >> test[i];
    }

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if(test[j] > test[i]) {
                int tmp = test[j];
                test[j] = test[i];
                test[i] = tmp;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        cout << i + 1 << "人目の点数は" << test[i] << "です。" << endl;
    }

    return 0;
}