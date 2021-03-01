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
#include <unordered_set>
#include <functional>
#define MAX 10001
using namespace std;

class Point2D
{
public:
    int x, y;
public:
    Point2D():x(0), y(0) {}
    Point2D(const int &_x, const int &_y):x(_x), y(_y){}
};

bool operator==(const Point2D& a, const Point2D& b)
{
    return a.x == b.x && a.y == b.y;
}

struct HashFunc
{
    size_t operator() (const Point2D &data) const 
    {
        size_t h1 = hash<int>()(data.x);
        size_t h2 = hash<int>()(data.y);
        return h1 ^ (h2 << 1);
    }
};

Point2D buff[MAX];

int main(int argc, char const *argv[])
{
    unordered_set<Point2D, HashFunc> hashset;
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
            temp.x = buff[i].x << 1;
            temp.y = buff[i].y << 1;
            hashset.insert(temp);
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
                if (hashset.find(point1) != hashset.end() && hashset.find(point2) != hashset.end())
                {
                    count++;
                }
            }
        }
        hashset.clear();
        cout << (count >> 1) << endl;
    }
    
    return 0;
}
