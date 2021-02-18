#include <iostream>
using namespace std;

void bubble_sort(int *data, int num)
{
    int temp;
    for (size_t i = 0; i < num; i++)
    {
        for (size_t j = num - 1; j > i; j--)
        {
            if (data[2 * j + 1] < data[2 * (j - 1) + 1] || (data[2 * j + 1] == data[2 * (j - 1) + 1] && data[2 * j] < data[2 * (j - 1)]))
            {
                // 交换分数
                temp = data[2 * j + 1];
                data[2 * j + 1] = data[2 * (j - 1) + 1];
                data[2 * (j - 1) + 1] = temp;
                // 交换学号
                temp = data[2 * j];
                data[2 * j] = data[2 * (j - 1)];
                data[2 * (j - 1)] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int data[200];
    int num;
    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> data[2 * i] >> data[2 * i + 1];
    }
    bubble_sort(data, num);
    for (size_t i = 0; i < num; i++)
    {
        cout << data[2 * i] << ' ' << data[2 * i + 1] << endl;
    }
    return 0;
}