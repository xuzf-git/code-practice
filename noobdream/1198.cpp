#include <iostream>
using namespace std;

bool is_seven(int num)
{
    if (num % 7 == 0)
    {
        return true;
    }
    while (num > 0)
    {
        if (num % 10 == 7) 
            return true;
        else
            num /= 10;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, res;
    while (cin >> n)
    {
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!is_seven(i))
            {
                res += i * i;
            }
        }
        cout << res << endl;
    }

    return 0;
}
