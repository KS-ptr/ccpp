#include<iostream>

#define NUM 5
using namespace std;

double avg(int t[]);

int main() {

    int test[5] = {36, 48, 56, 92, 38};

    cout << "test[0] = " << test[0] << endl;
    cout << "&test[0] = " << &test[0] << endl;
    cout << "test = " << test << endl;
    cout << "(test + 1) = " << test + 1 << endl;
    cout << "*(test + 1) = " << *(test + 1) << endl;
    // cout << "*test = " << *test << endl;

    double mean = avg(test);

    cout << "5人の平均点は" << mean << endl;
    return 0;
}

double avg(int t[]) {
    double sum = 0;

    for (int i = 0; i < NUM; i++) {
        sum += t[i];
    }
    return sum / NUM;
}