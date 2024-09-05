#include<iostream>
using namespace std;

void swap(int& x, int& y);

int main() {
    int a = 5;
    int& ra = a;

    cout << "aの値は" << a << endl;
    cout << "参照raの値は" << ra << endl;

    ra = 50;

    cout << "raに50を代入" << endl;
    cout << "参照raの値は" << ra << "に変更された" << endl;
    cout << "aの値は" << a << "に変更された" << endl;
    cout << "aのアドレスは" << &a << endl;
    cout << "参照raのアドレスは" << &ra << endl;

    int b;
    int& rb = b;

    cout << "rbの値は" << rb << endl;

    int c = 3, d = 8;
    // int& rc = c; 
    // int& rd = d;

    cout << "cの値は" << c << endl;
    cout << "dの値は" << d << endl;
    swap(c, d);
    cout << "swapを実行" << endl;
    cout << "cの値は" << c << endl;
    cout << "dの値は" << d << endl;

    return 0;
}

void swap(int& x, int& y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}