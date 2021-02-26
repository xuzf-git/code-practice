#include <iostream>
#define MAX 100005
using namespace std;

int buff[MAX], temp[MAX];
int count;

/* 归并排序 */
void merge_sort(int left, int right, int *buff)
{
    if (left >= right)
        return;
    int mid = left + ((right - left) >> 2);
    /* 分治 */
    merge_sort(left, mid, buff);
    merge_sort(mid + 1, right, buff);
    /* 合并 */
    int l, r, idx;
    l = left;
    r = mid + 1;
    idx = 0;
    while (l <= mid && r <= right)
    {
        if (buff[l] <= buff[r])
        {
            temp[idx++] = buff[l++];
        }
        else
        {
            temp[idx++] = buff[r++];
            // 记录跨越 mid 两端的逆序对
            ::count += (mid - l + 1);
        }
    }
    while (l <= mid)
        temp[idx++] = buff[l++];
    while (r <= right)
        temp[idx++] = buff[r++];
    /* 对原数组赋值 */
    for (size_t i = 0; i < idx; i++)
    {
        buff[left + i] = temp[i];
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        cin >> buff[i];
    }
    ::count = 0;
    merge_sort(0, size - 1, buff);
    cout << ::count << endl;
    return 0;
}
