/*
 * @Description: n的阶乘 <http://www.noobdream.com/DreamJudge/Issue/page/1167/>
 * @Author: xuzf
 * @Date: 2021-03-21 16:58:31
 * @FilePath: \practice\noobdream\1167.cpp
 */

#include <iostream>
using namespace std;

#define ll long long

ll factorial(ll data)
{
    ll res = 1;
    for (ll i = 2; i <= data; i++)
    {
        res *= i;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ll data, res;
    while (cin >> data)
    {
        cout << factorial(data) << endl;
    }

    return 0;
}
