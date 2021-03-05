#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int size;
    vector<int> buff;
    while (cin >> size)
    {
        if (size == 0)
            break;
        
        buff.push_back(0), buff.push_back(1), buff.push_back(2), buff.push_back(4);
        for (size_t i = 4; i <= size; i++)
        {
            buff.push_back(buff[i - 1] + buff[i - 2] + buff[i - 3]);
        }
        cout << buff[size] << endl;
        buff.clear();
    }

    return 0;
}
