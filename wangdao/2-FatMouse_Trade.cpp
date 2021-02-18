/* 
FatMouse prepared M pounds of cat food, ready beg o trade wit h the catsguarding the warehouse containing his favorite food, JavaBean.
The warehouse has N rooms. The i-th room contains J[i) pounds of JavaBeans and requires F[i) pounds of cat food. 
FatMouse does not have to trade for all the JavaBeans in the room, instead, 
he may get J[i)* a felt pounds of JavaBeans if he pays (F[i] * a %)   pounds of cat food. Here a is a real number.
Now he is assigning this homework to you: te11 him the maximum amount of JavaBeans he can obtain.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct room
{
    int j, f;
    double unit_price;  // 每 pounds 猫粮能换取的 javabean
    bool operator<(const room &a) const
    {
        return unit_price > a.unit_price;
    }
} buff[1002];

int main(int argc, char const *argv[])
{
    int n, m;
    double javabean;
    while (true)
    {
        cin >> m >> n;
        if (m == -1 && n == -1)
            break;
        
        // javabean 归零
        javabean = 0;

        // 输入数据
        for (size_t i = 0; i < n; i++)
        {
            cin >> buff[i].j >> buff[i].f;
            buff[i].unit_price = (double)buff[i].j / buff[i].f;
        }

        // 按照性价比从大到小排序
        sort(buff, buff + n);

        // 计算能得到的总数
        for (size_t i = 0; i < n; i++)
        {
            if (m <= 0)
                break;
            if (m >= buff[i].f)
            {
                m -= buff[i].f;
                javabean += buff[i].j;
            }
            else
            {
                javabean += double(m) * buff[i].unit_price;
                m = 0;
            }
        }
        printf("%.3lf\n", javabean);
    }
    return 0;
}
