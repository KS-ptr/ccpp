//挿入ソート
#include<iostream>
#include<algorithm>
#include<vector>

using std::cin; using std::cout; using std::vector;

int main()
{
    int n, a;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    int j,tmp;
    for(int i = 1; i < n; i++)
    {
        tmp = v[i];
        for(j = i - 1; j >= 0 && tmp < v[j]; j--)
        {
            v[j+1] = v[j];
        }
        v[j+1] = tmp;
    }
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}
