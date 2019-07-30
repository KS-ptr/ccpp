#include<iostream>
#include<string>

using namespace std;

bool isValid(string);

int main()
{
    string input = "{[]}";
    cout << to_string(isValid(input)) << endl;
    int c = getchar();
    return 0;
}

bool isValid(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] == '(' && s[i+1] == ')') || (s[i] == '{' && s[i+1] == '}') || (s[i] == '[' && s[i+1] == ']'))
        {
            s.erase(i,1);
            s.erase(i,1);
            if(s.length() < 2 || i < 2)
                i = -1;
            else
                i -= 2;
        }
    }
    return s.length() == 0;
}