#include <iostream>
#include <cmath>
using namespace std;
// 获取翻转数
int get_reverse(int origin)
{
    int num[10] = {0};
    int reverse = 0, i = 0;
    while (origin > 0)
    {
        num[i] = origin % 10;
        if (num[i] == 0)
        {
            i--;
        }
        origin /= 10;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        reverse += num[j] * pow(10, i - 1 - j);
    }
    return reverse;
}
// 模拟加法
int main(int argc, char const *argv[])
{
    int a_reverse[10], b_reverse[10];
    int a, b;
    while (cin >> a >> b)
    {
        a = get_reverse(a);
        b = get_reverse(b);
        cout << a + b << endl;
    }
    return 0;
}
