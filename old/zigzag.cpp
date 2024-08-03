#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

string zigzag(int, int, string);

int main()
{
    int height;
    string input;
    cin >> height;
    cin >> input;
    if(height == 1)
        cout << input;
    else
    {
        for(int i = 0; i < height; i++)
            cout << zigzag(height, i, input);
    }
    int c = getchar();
    return 0;
}

string zigzag(int h, int i, string str)
{
    string rstr = "";
    for(int a = 0; a < str.length() ; a++)
    {
        if(a % (2 * (h - 1)) == i || a % (2 * (h - 1)) == (2 * (h - 1)) - i)
        {
            rstr += str[a];
        }
    }
    return rstr;
}