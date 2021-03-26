/*
 * @Description: 堆的判断 <http://www.noobdream.com/DreamJudge/Issue/page/1127/>
 * @Author: xuzf
 * @Date: 2021-03-26 20:57:24
 * @FilePath: \practice\noobdream\1127.cpp
 */
#include <iostream>
using namespace std;

/* 小根堆的父节点 <= 子节点 */
bool judgeMinHeap(const int *data, int size)
{
    for (size_t i = 0; 2 * i + 2 < size; i++)
    {
        if (data[i] > data[2 * i + 1] || data[i] > data[2 * i + 2])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    int *data = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        cin >> data[i];
    }
    if (judgeMinHeap(data, size))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
