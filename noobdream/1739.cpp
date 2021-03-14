#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, k;
    int *buff;
    while (cin >> n >> m >> k)
    {
        buff = new int[m];
        for (size_t i = 0; i < m; i++)
        {
            cin >> buff[i];
        }
        int res = 0, sigle_res;
        int cur_begin, last_end = 0, dis = 2 * k + 1;
        for (size_t i = 0; i < m; i++)
        {
            cur_begin = buff[i] - k;
            if (cur_begin >= last_end)
            {
                sigle_res = ceil(double(cur_begin - last_end) / dis);
                res += sigle_res;
            }
            else
            {
                sigle_res = 0;
            }
            last_end = max(last_end + sigle_res * dis, buff[i] + k);
        }
        if (last_end < n)
        {
            res += ceil(double(n - last_end) / dis);
        }

        cout << res << endl;
        // 释放内存
        delete[] buff;
    }
    return 0;
}
