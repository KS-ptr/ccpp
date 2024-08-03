#include<iostream>
using namespace std;

void sub2();
void sub3();

int main() {
    cout << 0 - 4 << endl;
    cout << 3.14 * 2 << endl;
    cout << (double)5 / 3 << endl;
    cout << 30 % 7 << endl;
    cout << double((7 + 32) / 5) << endl;

    //sub2();
    sub3();

    return 0;
}

void sub2() {
    int height, bottom;

    cout << "三角形の高さを入力してください。" << endl;
    cin >> height;
    cout << "三角形の底辺を入力してください。" << endl;
    cin >> bottom;
    cout << "三角形の面積は" << height * bottom / 2 << "です。" << endl;
}

void sub3() {
    int score_1, score_2, score_3, score_4, score_5;
    int score;
    cout << "科目1の点数を入力してください。" << endl;
    cin >> score_1;
    score += score_1;
    cout << "科目2の点数を入力してください。" << endl;
    cin >> score_2;
    score += score_2;
    cout << "科目3の点数を入力してください。" << endl;
    cin >> score_3;
    score += score_3;
    cout << "科目4の点数を入力してください。" << endl;
    cin >> score_4;
    score += score_4;
    cout << "科目5の点数を入力してください。" << endl;
    cin >> score_5;
    score += score_5;

    cout << "5科目の合計点は" << score << "です。" << endl;
    cout << "5科目の平均点は" << (double)score / 5 << "です。" << endl;
}