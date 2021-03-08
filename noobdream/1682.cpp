#include <iostream>
#include <algorithm>
#define MAX 30
#define MAX_LL 100000000000010 // Fake Ans

#if 0
#define MAX_LL 9223372036854775806
#endif

using namespace std;

struct kele
{
    int price, volume;
    double uprice;
} buff[MAX];

bool cmp(const kele &a, const kele &b)
{
    return a.uprice < b.uprice;
}

int main(int argc, char const *argv[])
{
    int num, require, volume;
    while (cin >> num >> require)
    {
        volume = 1;
        for (size_t i = 0; i < num; i++)
        {
            cin >> buff[i].price;
            buff[i].volume = volume;
            buff[i].uprice = (double)buff[i].price / (double)volume;
            volume <<= 1;
        }
        sort(buff, buff + num, cmp);
        long long int res = 0;          // 当前解
        long long int min_res = MAX_LL; // 当前最优解
        int num_i;
        // (贪心算法) 搜索可行解
        for (size_t i = 0; i < num; i++)
        {
            num_i = require / buff[i].volume;
            res += (long long)num_i * (long long)buff[i].price;
            require %= buff[i].volume;

            if (require == 0)
            {
                min_res = res < min_res ? res : min_res;
                break;
            }

            if (res + buff[i].price < min_res)
                min_res = res + buff[i].price;
        }
        cout << min_res << endl;
    }

    return 0;
}
