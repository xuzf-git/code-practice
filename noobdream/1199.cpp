#include <iostream>
using namespace std;

typedef unsigned short ushort;
const ushort HIGHT_BIT = 1 << 15; 

ushort left_move(ushort num)
{
    ushort res = num << 1;
    ushort high_bit = (num & HIGHT_BIT) >> 15;
    res += high_bit;
    return res;
}

int main(int argc, char const *argv[])
{
    ushort a, b;
    ushort ta, tb;
    int flag;
    while (cin >> a >> b)
    {
        ta = a;
        tb = b;
        flag = false;
        for (size_t i = 0; i < 16; i++)
        {
            if (ta == b)
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
            ta = left_move(ta);
        }
        if (flag)
            continue;
        for (size_t i = 0; i < 15; i++)
        {
            tb = left_move(tb);
            if (tb == a)
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
