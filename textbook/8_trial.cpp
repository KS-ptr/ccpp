#include<iostream>
using namespace std;

void swap(int x, int y);
void swap2(int* x, int* y);

int main() {
    // int a;
    // a = 5;

    // cout << "変数aの値は" << a << endl;
    // cout << "変数aのアドレスは" << &a << endl;

    // int b;
    // int* pB;
    // b = 5;
    // pB = &b;
    // cout << "変数bの値は" << b << endl;
    // cout << "変数bのアドレス(&b)は" << &b << endl;
    // cout << "ポインタpBの値は" << pB << endl;

    int c = 5;
    int d = 8;
    int* pC;
    pC = &c;

    cout << "変数cの値は" << c << endl;
    //cout << "変数cのアドレス(&c)は" << &c << endl;
    cout << "ポインタpCの値は" << pC << endl;
    cout << "*pCの値は" << *pC << endl;

    pC = &d;
    cout << "変数dの値は" << d << endl;
    cout << "ポインタpCの値は" << pC << "に変更された" << endl;
    cout << "*pCの値は" << *pC << endl;

    int a = 5, b = 7;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int e = 8, f = 12;
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;
    swap2(&e, &f);
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;

    return 0;
}

void swap(int x, int y) {
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

void swap2(int* px, int* py) {
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}