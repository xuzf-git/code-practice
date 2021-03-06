#include <iostream>
#include <algorithm>
// #include <cmath>
#define MAX 105
using namespace std;

struct entry
{
    double rate;
    double utmost;
} buff[MAX];

bool cmp(const entry &a, const entry &b)
{
    return a.rate < b.rate;
}

int main(int argc, char const *argv[])
{
    int size;
    double total, count, pay;
    while (cin >> size >> total)
    {
        count = 0;
        for (size_t i = 0; i < size; i++)
        {
            cin >> buff[i].rate >> buff[i].utmost;
        }
        // 按照折扣率排序（贪心算法，折扣最大的券先用掉）
        sort(buff, buff + size, cmp);
        // 依次付钱
        for (size_t i = 0; i < size && total > 0; i++)
        {
            pay = min(total, buff[i].utmost);
            count += pay * buff[i].rate;
            total -= pay;
        }
        count += total;
        cout << (int)count << endl;
    }

    return 0;
}
