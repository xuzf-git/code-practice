#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<pair<int, int>> factors; // pair 的第一个数字表示因数，第二个数字表示前面连续的因数个数
    pair<int, int> last;
    int num;
    int max_len = 0, factor_end = 0;
    // factors.emplace_back(0, -1);    // 防止 last 取 NULL
    last = make_pair(0, -1);
    // 读取数据
    cin >> num;
    // 获取所有的因数，及其连续数
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            if (last.first == i - 1)
                factors.emplace_back(i, last.second + 1);
            else
                factors.emplace_back(i, 1);

            last = factors.back();

            // 记录当前出现的最长连续因数
            if (last.second > max_len)
            {
                max_len = last.second;
                factor_end = i;
            }
        }
    }
    // 输出结果
    for (int i = factor_end - max_len + 1; i <= factor_end; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
