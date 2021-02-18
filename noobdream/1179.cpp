#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
                str[i] += 1;
            else if (str[i] == 'z')
                str[i] = 'a';
            else if (str[i] == 'Z')
                str[i] = 'A';
        }
        cout << str << endl;
    }
    return 0;
}
