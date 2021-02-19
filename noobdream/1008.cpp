#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int num, op, count1;
    cin >> num;
    op = 1;
    count1 = 0;
    for (int i = 0; i < 31; i++)
    {
        if (num & op)
        {
            ++count1;
        }
        op = op << 1;
    }
    cout << "count0=" << 32 - count1 << " count1=" << count1 << endl;
    
    return 0;
}
