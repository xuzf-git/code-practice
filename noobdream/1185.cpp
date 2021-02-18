/* 回溯法：实现全排列 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool flag[6];
char buff[7];
int len;

void backtrack(vector<vector<char>> &res, vector<char> &seq, int idx)
{
    if (idx == len)
    {
        res.push_back(seq);
        return;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (flag[i] == false)
        {
            // 尝试路径
            flag[i] = true;
            seq.push_back(buff[i]);
            // 递归
            backtrack(res, seq, idx + 1);
            // 恢复现场
            seq.pop_back();
            flag[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%s", buff);
    len = strlen(buff);
    memset(flag, false, sizeof(flag));
    vector<vector<char>> res;
    vector<char> seq;
    backtrack(res, seq, 0);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j]; 
        }
        cout << endl;
    }
    
    return 0;
}
