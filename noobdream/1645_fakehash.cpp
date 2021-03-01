/* 
输入描述:
    多组测试数据。第一行输入一个整数n，表示有n（1 <= n <= 1000）个点。
    接下来n行，每一行有两个整数x（-5000<= x <= 5000）和y（-5000 <= y <= 5000），表示点的坐标。
    你可以假设这些点的坐标都是不同的。当n为0时程序结束。
输出描述:
    对于每个测试用例，在一行上打印出可以从给定坐标点形成的正方形的数量。

利用 hash 优化时间复杂度

*/

#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_NUM 1005
#define MAX_POS 5005
using namespace std;

struct Point2D
{
    int x, y;
};

Point2D buff[MAX_NUM];
bool hashset[MAX_POS << 1][MAX_POS << 1];

void insert(Point2D &data)
{
    hashset[data.x + MAX_POS][data.y + MAX_POS] = true;
}

bool find(Point2D &data)
{
    if (abs(data.x) >= MAX_POS || abs(data.y) >= MAX_POS)
        return false;

    return hashset[data.x + MAX_POS][data.y + MAX_POS];
}

void clear()
{
    memset(hashset, 0, sizeof(hashset));
}

int main(int argc, char const *argv[])
{
    int n;
    long long count;
    Point2D point1, point2, temp;
    while (true)
    {
        cin >> n;
        count = 0;
        if (n == 0)
            break;
        for (size_t i = 0; i < n; i++)
        {
            cin >> buff[i].x >> buff[i].y;
            insert(buff[i]);
        }

        // 遍历每个点对的组合，以该点对为对角线，通过hash查询另外两点是否存在
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                point1.x = buff[i].x + buff[j].x + buff[j].y - buff[i].y;
                point1.y = buff[i].y + buff[j].y + buff[i].x - buff[j].x;
                point2.x = buff[i].x + buff[j].x - buff[j].y + buff[i].y;
                point2.y = buff[i].y + buff[j].y - buff[i].x + buff[j].x;

                // 避免整数除法精度不够
                if (point1.x & 1 || point1.y & 1 || point2.x & 1 || point2.y & 1)
                    continue;

                point1.x >>= 1, point1.y >>= 1, point2.x >>= 1, point2.y >>= 1;

                // 正方形计数
                if (find(point1) && find(point2))
                    count++;
            }
        }
        // clear();
        for (size_t i = 0; i < n; i++)
        {
            hashset[buff[i].x + MAX_POS][buff[i].y + MAX_POS] = false;
        }

        cout << (count >> 1) << endl;
    }

    return 0;
}
