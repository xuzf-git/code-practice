/*
 * @Author: xuzfS
 * @Date: 2021-01-29 21:08:19
 * @LastEditTime: 2021-01-29 21:18:18
 * @LastEditors: Please set LastEditors
 * @Description: 统计某个成绩出现的次数
 * @FilePath: \algorithm\wdjs\1.3hash\grade_count.cpp
 */

#include <iostream>
#include <string.h>
using namespace std;
int grade_bucket[101];
int main(int argc, char const *argv[])
{
    int n, grade;
    while (true)
    {
        memset(grade_bucket, 0, sizeof(grade_bucket));
        cin >> n;
        if (n == 0)
            break;
        // 输入并将相应的分数堆计数加 1
        for (int i = 0; i < n; i++)
        {
            cin >> grade;
            grade_bucket[grade] += 1;
        }
        cin >> grade;
        cout << grade_bucket[grade] << endl;
    }
    return 0;
}
