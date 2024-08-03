#include<iostream>
using namespace std;

void sub();
void sub2();

int main() {
    int inum = 160;
    double dnum;

    cout << "身長は" << inum << "cmです。" << endl;

    dnum = inum;

    cout << "身長は" << dnum << "cmです。" << endl;

    sub();sub2();

    return 0;
}

void sub() {
    int inum;
    double dnum = 160.5;

    cout << "身長は" << dnum << "cmです。" << endl;

    inum = dnum;

    cout << "身長は" << inum << "cmです。" << endl;

    return;
}

void sub2() {
    int d = 2;
    const double pi = 3.14;

    cout << "直径が" << d << "cmの円の";
    cout << "円周は" << d * pi << "cm^2となる。" << endl;
}