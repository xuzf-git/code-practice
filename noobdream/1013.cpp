#include <iostream>
using namespace std;
bool is_zhishu(int n)
{
    if (n < 3)
        return true;
    
    for (size_t i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << 2 << endl;
    }
    else
    {   
        while (true)
        {
            if (is_zhishu(n))
            {
                cout << n << endl;
                break;
            }
            n++;
        }
    }
    return 0;
}
