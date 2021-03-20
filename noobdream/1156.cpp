/*
 * @Description: 质因数个数  <http://www.noobdream.com/DreamJudge/Issue/page/1156/>
 * @Author: xuzf
 * @Date: 2021-03-20 18:21:34
 * @FilePath: \practice\noobdream\1156.cpp
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int buff, res;
    while (cin >> buff)
    {
        res = 0;
        for (int i = 2; i <= buff; i++)
        {
            while (buff % i == 0)
            {
                res++;
                buff /= i;
            }
            if (i * i > buff && res == 0)
            {
                res = 1;
                break;
            }
        }
        cout << res << endl;
    }

    return 0;
}
