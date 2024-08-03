#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void sub1();
void sub2();
void sub3();

int main() {
    sub1();
    sub2();
    sub3();
}

void sub1() {
    int n;
    cout << "整数を入力してください。" << endl;
    cin >> n;
    if (n % 2 == 0) {
        cout << n << "は偶数です。" << endl;
    } else {
        cout << n << "は奇数です。" << endl;
    }
}

void sub2() {
    int n1, n2;
    cout << "2つの整数を入力してください。" << endl;
    cin >> n1 >> n2;
    if (n1 == n2) {
        cout << "2つの数は同じです。" << endl;
    } else {
        n1 < n2 ? cout << n1 << "より" << n2 << "の方が大きい値です。" << endl
                : cout << n2 << "より" << n1 << "の方が大きい値です。" << endl;
    }
}

void sub3() {
    int score;
    cout << "成績を入力してください。" << endl;
    cin >> score;
    switch (score) {
        case 1:
            cout << "成績は" << score << "です。もっと頑張りましょう。" << endl;
            break;
        case 2:
            cout << "成績は" << score << "です。もう少し頑張りましょう。" << endl;
            break;
        case 3:
            cout << "成績は" << score << "です。さらに上を目指しましょう。" << endl;
            break;
        case 4:
            cout << "成績は" << score << "です。たいへんよくできました。" << endl;
            break;
        case 5:
            cout << "成績は" << score <<"です。大変優秀です。" << endl;
            break;
        default:
            break;
    }
}