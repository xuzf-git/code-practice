#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
#if 0

int longestWPI(vector<int> &hours)
{
    for (auto it = hours.begin(); it != hours.end(); it++)
    {
        *it = *it > 8 ? 1 : -1;
    }

    int head = 0, tail = 0, size = hours.size();
    int count = hours[0], res = 0;
    // -1 -1 1
    while (tail < size && head < size)
    {
        if (count <= 0)
        {
            count -= hours[head];
            head++;
            if (head > tail && head < size)
            {
                count = hours[head];
                tail = head;
            }
        }
        else
        {
            tail++;
            if (tail < size)
                count += hours[tail];
        }
        if (tail - head + 1 > res)
            res = tail - head;
    }
    tail = size - 1, head = size - 1, count = hours[head];
    while (tail >= 0 && head >= 0)
    {
        if (count <= 0)
        {
            count -= hours[head];
            head--;
            if (head > tail && head >= 0)
            {
                count = hours[head];
                tail = head;
            }
        }
        else
        {
            tail--;
            if (tail >= 0)
                count += hours[tail];
        }
        if (head - tail + 1 > res)
            res = head - tail;
    }

    return res;
}

#endif

int longestWPI(vector<int> &hours)
{
    int count = 0;
    int size = hours.size();
    // 计算前缀和
    vector<int> presum;
    presum.push_back(0); // 以0开头，做差时能把presum[1]包含
    for (int i = 0; i < size; i++)
    {
        hours[i] = hours[i] > 8 ? 1 : -1;
        count += hours[i];
        presum.push_back(count);
    }
    // 构造单调栈
    stack<int> istack;
    istack.push(0);
    for (int i = 1; i <= size; i++)
    {
        if (presum[i] < presum[istack.top()])
        {
            istack.push(i);
        }
    }
    // 逆序遍历数组，找到最长的上升span
    int res = 0;
    for (int i = size; i > res; i--)
    {
        // i为span的尾，单调栈的栈顶为span的头（由于最优解的头索引，肯定是在单调栈中）
        while (!istack.empty() && presum[istack.top()] < presum[i])
        {
            res = max(res, i - istack.top());
            istack.pop();
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> buff;
    int num;
    while (cin >> num)
    {
        buff.push_back(num);
    }
    int res = longestWPI(buff);
    cout << res << endl;

    return 0;
}
/*
9
9
6
0
6
6
9

*/