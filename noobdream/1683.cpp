#include <iostream>
#include <algorithm>
#define MAX 55
using namespace std;

int buff[MAX];

int main(int argc, char const *argv[])
{
    int n, k, res;
    char temp;

    while (cin >> n >> k)
    {
        res = 0;

        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            buff[i] = temp - 'a' + 1;
        }
        sort(buff, buff + n);
        int i = 0, count = 0, last;
        while (i < n && count < k)
        {
            res += buff[i];
            count++;
            last = buff[i];

            while (buff[i] - last < 2 && i < n)
                i++;
        }
        if (count == k)
            cout << res << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
