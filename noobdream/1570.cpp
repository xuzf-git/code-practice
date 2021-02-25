#include <iostream>
#include <cstring>
#define MAX 100002

int data[MAX], sum[MAX];

int main(int argc, char const *argv[])
{
    int n, s, t, res;

    std::cin >> t;

    while (t--)
    {
        // 初始化
        sum[0] = 0;
        std::cin >> n >> s;
        for (size_t i = 1; i <= n; i++)
        {
            std::cin >> data[i];
            sum[i] = sum[i - 1] + data[i];
        }
        if (sum[n] < s)
        {
            std::cout << 0 << std::endl;
            continue;
        }

#if 1 // O(2n)
        int l = 0, r = 1;
        res = n;
        while (l <= n && r <= n)
        {
            if (sum[r] - sum[l] >= s)
            {
                res = std::min(res, r - l);
                l++;
            }
            else
            {
                r++;
            }
        }
        std::cout << res << std::endl;
#endif

#if 0 // O(n^3)
        bool flag = false;
        for (size_t len = 1; len <= n; len++)
        {
            for (size_t i = 1; i + len <= n; i++)
            {
                if ((sum[i + len - 1] - sum[i - 1]) >= s)
                {
                    std::cout << len << std::endl;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
#endif
    }

    return 0;
}
