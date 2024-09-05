#include<iostream>
using namespace std;

void add1(int* x, int* y);
void add2(int& x, int& y);

int main() {
    int score1, score2;
    cout << "2科目分の点数を入力してください。" << endl;
    cin >> score1;
    cin >> score2;
    
    int addscore;
    cout << "加算する点数を入力してください。" << endl;
    cin >> addscore;

    cout << addscore << "点加算したので" << endl;

    add1(&score1, &addscore);
    add1(&score2, &addscore);
    cout << "科目1は" << score1 << "点になりました。" << endl;
    cout << "科目2は" << score2 << "点になりました。" << endl;

    // add2(score1, addscore);
    // add2(score2, addscore);
    // cout << "科目1は" << score1 << "点になりました。" << endl;
    // cout << "科目2は" << score2 << "点になりました。" << endl;

    return 0;
}

void add1(int* x, int* y) {
    *x += *y;
}

void add2(int& x, int& y) {
    x += y;
}