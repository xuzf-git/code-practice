#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int line_flag = 0;
    vector<int> res;
    for (size_t i = 100; i < 1001; i++)
    {
        if (i % 5 == 0 && i % 6 == 0)
        {
            res.push_back(i);
        }
    }
    int len = res.size();
    for (size_t i = 0; i < len; i++)
    {
        line_flag++;
        cout << res[i];
        if (line_flag == 10 || i == len - 1)
        {
            cout << endl;
            line_flag = 0;
        }
        else
        {
            cout << ' ';
        }
    }
    
    return 0;
}
