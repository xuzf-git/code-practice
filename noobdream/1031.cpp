#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string buff;
    char ch;
    bool flag = true, have_dot = false;
    // cin >> buff;
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '\n')
        {
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            flag = true;
            have_dot = false;
        }
        else if (ch == '.' && !have_dot)
        {
            have_dot = true;
        }
        else if (ch == '.' && have_dot)
        {
            flag = false;
        }
        else if (ch != '0' && have_dot)
        {
            flag = false;
        }
        else if ((ch < '0' || ch > '9') && flag)
        {
            flag = false;
        }
    }
    
    return 0;
}
