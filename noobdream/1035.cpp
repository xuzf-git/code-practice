/*
 * @Description: 简单背包问题 <http://www.noobdream.com/DreamJudge/Issue/page/1035/>
 * @Author: xuzf
 * @Date: 2021-03-19 17:52:43
 * @FilePath: \practice\noobdream\1035.cpp
 */

#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int s, n;
    while (cin >> s >> n)
    {
        int *weight = new int[n];
        bool *dp = new bool[s + 1];
        for (size_t i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (size_t i = 0; i < n; i++)
        {
            for (int j = s; j >= weight[i]; j--)
            {
                if (dp[j - weight[i]])
                {
                    dp[j] = true;
                }
            }
        }
        if (dp[s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        delete[] weight;
        delete[] dp;
    }

    return 0;
}
