#include <iostream>
using namespace std;

bool judge(int num)
{
    int a = num % 10;        // 个位
    int b = num / 100;       // 百位
    int c = (num / 10) % 10; // 十位
    return num == (a * a * a) + (b * b * b) + (c * c * c);
}

int main(int argc, char const *argv[])
{
    int m, n;
    bool flag;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
            break;
        flag = true;
        for (int i = m; i <= n; i++)
        {
            if (judge(i))
            {
                cout << i << ' ';
                flag = false;
            }
        }
        if (flag)
            cout << "no" << endl;
        else
            cout << endl;
    }

    return 0;
}
