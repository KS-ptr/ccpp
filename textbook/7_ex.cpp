#include<iostream>
using namespace std;

// int square(int x);
// double square(double x);
// inline int square(int x){return x * x;};
// inline double square(double x){return x * x;};

template <class T>
double square(T x) {
    return x * x;
}

int main() {
    int x;
    cout << "整数を入力してください。" << endl;
    cin >> x;
    cout << x << "の2乗は" << square(x) << "です。" << endl;

    double y;
    cout << "小数を入力してください。" << endl;
    cin >> y;
    cout << y << "の2乗は" << square(y) << "です。" << endl;

}

// int square(int x) {
//     return x * x;
// }

// double square(double x) {
//     return x * x;
// }