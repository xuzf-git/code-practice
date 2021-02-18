#include <iostream>
#include <algorithm>
using namespace std;

struct show
{
    int s, e;
    bool operator<(const show &a) const
    {
        return e < a.e;
    }
} schedule[100];

int main(int argc, char const *argv[])
{
    int n, count, now;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        // 读入数据
        for (size_t i = 0; i < n; i++)
            cin >> schedule[i].s >> schedule[i].e;
        // 按照结束时间排序
        sort(schedule, schedule + n);
        
        count = 1; // 观看完整节目计数
        now = schedule[0].e; // 记录当前时间

        // 满足最优子结构 & 贪心选择性质
        for (size_t i = 1; i < n; i++)
        {
            if (schedule[i].s >= now) // 节目还没开始
            {
                count++;
                now = schedule[i].e;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
