#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct StuInfo
{
    int id;
    string name;
    int age;
} StuInfo;

bool cmp(const StuInfo &a, const StuInfo &b)
{
    return a.id < b.id;
}

int binary_search(StuInfo *list, int id, int num)
{
    int begin = 0, end = num - 1;
    int mid;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (list[mid].id == id)
            return mid;
        else if (list[mid].id > id)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n, m, id, idx;
    string sex;
    StuInfo stu_list[1002];
    // 读入数据，构架信息列表
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> stu_list[i].id >> stu_list[i].name >> sex >> stu_list[i].age;
    }
    // 信息排序
    sort(stu_list, stu_list + n, cmp);
    // 开始查询
    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        cin >> id;
        idx = binary_search(stu_list, id, n);
        if (idx < 0)
        {
            cout << "No Answer!" << endl;
        }
        else
        {
            cout << stu_list[idx].id << ' '<< stu_list[idx].name << ' ' << stu_list[idx].age;
            cout << endl;
        }
    }
    return 0;
}


// 4
// 01 李江 男 21
// 02 刘唐 男 23
// 03 张军 男 19
// 04 王娜 女 19
// 5
// 02
// 03
// 01
// 04
// 03