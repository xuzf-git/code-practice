#include <iostream>
using namespace std;
void add_one(int *data)
{
    int additional = 1;
    for (int i = 5; i >= 0; i--)
    {
        if (data[i] == 1 && additional == 1)
        {
            data[i] = 0;
            additional = 1;
        }
        else if (data[i] == 0 && additional == 1)
        {
            data[i] = 1;
            additional = 0;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int data[6] = {0};
    for (int i = 0; i < 64; i++)
    {
        // 输出结果
        for (int j = 0; j < 6; j++)
        {
            cout << data[j];
        }
        cout << endl;
        add_one(data);
    }
    return 0;
}