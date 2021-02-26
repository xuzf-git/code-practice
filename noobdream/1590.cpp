#include <iostream>
#define MAX 100005

int buff[MAX];

template <typename T>
void select_sort(T *buff, int start, int end)
{
    int min;
    for (size_t i = start; i < end; i++)
    {
        min = i;
        for (size_t j = i + 1; j <= end; j++)
        {
            if (buff[j] < buff[min])
            {
                min = j;
            }
        }
        std::swap(buff[min], buff[i]);
    }
}

template <typename T>
T media3(T *buff, int start, int end)
{
    int mid = start + (end - start) >> 2;
    if (buff[start] > buff[mid])
        std::swap(buff[start], buff[mid]);
    if (buff[mid] > buff[end])
        std::swap(buff[mid], buff[end]);
    if (buff[start] > buff[mid])
        std::swap(buff[start], buff[mid]);
    
    std::swap(buff[mid], buff[end]);
    return buff[end];
}

template <typename T>
void quick_sort(T *buff, int start, int end)
{
    // if (end - start <= 10)
    // {
    //     select_sort(buff, start, end);
    //     return;
    // }

    if (start >= end)
        return;

    /* media3 算法获取快排中值 */
    T key = media3(buff, start, end);
    /* 根据中值划分数组 */
    int l = start, r = end;
    while (l < r)
    {
        while (l < r && buff[l] <= key) l++;
        while (l < r && buff[r] >= key) r--;
        if (l < r)
        {
            std::swap(buff[l], buff[r]);
            // l++, r--;
        }
    }
    if (l == r && buff[l] > key)
    {
        std::swap(buff[l], buff[end]);
    }
    else if (l == r && buff[l] < key)
    {
        l++;
        std::swap(buff[l], buff[end]);
    }
    
    /* 分治求解 */
    quick_sort(buff, start, l - 1);
    quick_sort(buff, l + 1, end);
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
