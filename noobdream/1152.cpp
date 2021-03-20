/*
 * @Description: 约数的个数 <http://www.noobdream.com/DreamJudge/Issue/page/1152/>
 * @Author: xuzf
 * @Date: 2021-03-20 17:07:43
 * @FilePath: \practice\noobdream\1152.cpp
 */

#include <iostream>
using namespace std;

int count_factor(int num)
{
    int pow_2, res = 1;
    for (int factor = 2; factor <= num; factor++)
    {
        pow_2 = 0;
        while (num % factor == 0)
        {
            pow_2++;
            num /= factor;
        }
        if (pow_2 > 0)
        {
            res *= (pow_2 + 1);
        }
    }
    if (num > 1)
    {
        res = 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int buff;
        for (size_t i = 0; i < n; i++)
        {
            cin >> buff;
            cout << count_factor(buff) << endl;
        }
    }

    return 0;
}
