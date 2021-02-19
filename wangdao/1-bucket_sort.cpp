/*
 * @Author: xuzf
 * @Date: 2021-01-29 21:22:32
 * @LastEditTime: 2021-01-29 21:44:47
 * @LastEditors: Please set LastEditors
 * @Description: 桶排序得出记录的 n 个数据中前 m 大的数，
 * @FilePath: \algorithm\wdjs\1.3hash\bucket_sort.cpp
 */
#include <iostream>
#include <string.h>
#define OFFSET 500000
using namespace std;

int bucket[1000001];
int main(int argc, char *argv[])
{
    int n, m, d;
    while (cin >> n >> m)
    {
        memset(bucket, 0, sizeof(bucket));
        int count = m, max_num = -500000;
        for (int i = 0; i < n; i++)
        {
            cin >> d;
            max_num = max_num > d ? max_num : d;
            bucket[d + OFFSET] += 1;
        }
        int i = max_num + OFFSET;
        while (count > 0)
        {
            if (bucket[i] > count)
            {
                count = 0;
                for (int j = 0; j < count; j++)
                    cout << i - OFFSET << ' ';
            }
            else
            {
                count -= bucket[i];
                for (int j = 0; j < bucket[i]; j++)
                    cout << i - OFFSET << ' ';
            }
            i--;
        }
        cout << endl;
    }
    return 0;
}
