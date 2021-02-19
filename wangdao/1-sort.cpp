#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @description: 冒泡排序: 交换排序的一种，每次循环通过将最小（最大）的数
 *               交换到数组的未排序部分的最左端；以确定一个位置的值。算法的复杂度为 O(n^2);
 * @param {int} *arr
 * @param {int} n
 * @param {bool} reverse
 * @return {*}
 */
void bubble_sort(int *arr, int n, bool reverse)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1] == reverse)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

/**
 * @description: 比较函数，当发返回 true 时，i 会排在 j 前面
 * @param {int} i
 * @param {int} j
 * @return {*}
 */
bool cmp(int i , int j)
{
    return (i > j);
}

int main(int argc, char const *argv[])
{
    int n;    // 一次排序的个数
    int temp; // 用于数据交换的临时变量
    int data[101];
    while (cin >> n)
    {
        // 读入数据
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        // 冒泡排序
        bubble_sort(data, n, false);
        // 快排
        sort(data, data + n);
        // 输出结果
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
