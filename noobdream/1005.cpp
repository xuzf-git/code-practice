#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t, n, pre, cur, res;
    int floor[101];
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        cin >> n;
        res = 0;    // 结果清零
        pre = 1;    // 初始在一楼
        for (size_t j = 0; j < n; j++)
        {
            cin >> cur;
            if (cur > pre)
            {
                res += (cur - pre) * 6;
            }
            else if (cur < pre)
            {
                res += (pre - cur) * 4;
            }
            // 停留时间
            res += 3;
            // 更新 pre
            pre = cur;
        }
        cout << res << endl;
    }
    
    return 0;
}
