#include <iostream>
#define MAX 100005

int buff[MAX];

template <typename T>
T media3(T *buff, int start, int end)
{
    int mid = start + (end - start) >> 1;
    if (buff[start] > buff[mid])
        std::swap(buff[start], buff[mid]);
    if (buff[mid] > buff[end])
        std::swap(buff[mid], buff[end]);
    if (buff[start] > buff[mid])
        std::swap(buff[start], buff[mid]);

    std::swap(buff[mid], buff[start]);
    return buff[start];
}

template <typename T>
void quick_sort(T *buff, int start, int end)
{
    if (start >= end)
        return;

    /* media3 算法获取快排中值 */
    T key = media3(buff, start, end);
    /* 根据中值划分数组 */
    int l = start, r = end + 1;
    while (true)
    {
        while (buff[++l] < key)
        {
            if (l == end)
                break;
        }
        while (buff[--r] > key)
        {
            if (r == start)
                break;
        }
        if (l >= r)
            break;
        std::swap(buff[l], buff[r]);
    }
    std::swap(buff[start], buff[r]);

    /* 分治求解 */
    quick_sort(buff, start, r - 1);
    quick_sort(buff, r + 1, end);
}

int main(int argc, char const *argv[])
{
    int size;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> buff[i];
    }
    quick_sort(buff, 0, size - 1);
    for (size_t i = 0; i < size - 1; i++)
    {
        std::cout << buff[i] << ' ';
    }
    std::cout << buff[size - 1] << std::endl;
    return 0;
}
