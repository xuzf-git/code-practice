#include <iostream>
#include <string.h>
using namespace std;
int buff[7];

void add_one()
{
    bool carry = true;  // 进位
    for (size_t i = 0; i < 6; i++)
    {
        if (!carry)
            break;
        
        if (buff[i] == 9)
        {
            buff[i] = 0;
            carry = true;
        }
        else
        {
            buff[i]++;
            carry = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    int l, r, count;
    while (cin >> l >> r)
    {
        // 初始化
        count = 0;
        memset(buff, 0, sizeof(buff));
        for (size_t i = 0; i < l; i++)
            add_one();
        // 模拟
        for (size_t i = l; i <= r; i++)
        {
            for (size_t j = 0; j < 6; j++)
            {
                if (buff[j] == 2)
                    count++;
            }
            add_one();
        }
        cout << count << endl;
    }
    return 0;
}
