#include<iostream>
#include<string>
using namespace std;

void sub1();
void sub2();

int main() {
    cout << "1から10までの偶数を出力します。" << endl;
    for (int i = 2; i <= 10; i += 2) {
        cout << i << endl;
    }
    
    sub1();
    sub2();

    return 0;
}

void sub1() {
    cout << "テストの点数を入力してください。(0で終了)" << endl;
    int score = -1;
    int sum = 0;
    
    while(true) {
        cin >> score;
        if(score == 0)
            break;
        sum += score;
    }

    cout << "テストの合計点は" << sum << "点です。" << endl;
    return;
}

void sub2() {
    string str = "";
    for(int i = 0; i < 5; i++) {
        str += "*";
        cout << str << endl;
    }
}