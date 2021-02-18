#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[610];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        for (size_t i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        // 从小到大排序
        sort(num, num + n);
        // 构造最简真分数
        int count = 0;
        for (size_t i = 0; i < n; i++)
        {
            // if (num[i] == num[i + 1])
            // continue;
            for (size_t j = i + 1; j < n; j++)
            {
                // if (num[j] == num[j - 1])
                // continue;

                if (gcd(num[i], num[j]) == 1)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
