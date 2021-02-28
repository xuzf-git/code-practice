#include <iostream>
#include <limits.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int buff[102];
    cin >> n;
    int max = -INT_MAX, min = INT_MAX;
    for (size_t i = 0; i < n; i++)
    {
        cin >> buff[i];
        if (buff[i] > max)
        {
            max = buff[i];
        }
        if (buff[i] < min)
        {
            min = buff[i];
        }
    }
    bool flag_max = false, flag_min = false;
    for (size_t i = 0; i < n; i++)
    {
        if (buff[i] == max && !flag_max)
        {
            // cout << buff[i] << ' ';
            flag_max = true;
            continue;
        }
        if (buff[i] == min && !flag_min)
        {
            // cout << buff[i] << ' ';
            flag_min = true;
            continue;
        }
        cout << buff[i] << ' ';

    }
    cout << endl;    
    return 0;
}
