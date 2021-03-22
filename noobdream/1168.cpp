/*
 * @Description: 特殊算法 <http://www.noobdream.com/DreamJudge/Issue/page/1168/>
 * @Author: xuzf
 * @Date: 2021-03-22 23:25:16
 * @FilePath: \practice\noobdream\1168.cpp
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int special_cal(string &str1, string &str2)
{
    int res = 0;
    for (size_t i = 0; i < str1.length(); i++)
    {
        for (size_t j = 0; j < str2.length(); j++)
        {
            res += (str1[i] - '0') * (str2[j] - '0');
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    int res;
    while (cin >> str1 >> str2)
    {
        cout << special_cal(str1, str2) << endl;
    }

    return 0;
}
