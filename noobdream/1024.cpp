#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, data;
    int buff[35];

    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> buff[i];

    // 排序
    sort(buff, buff + n);
    // 遍历
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << '(' << buff[i] << ',' << buff[j] << ')' << endl;
                while (buff[j + 1] == buff[j])
                    j++;
            }
        }
        while (buff[i + 1] == buff[i])
            i++;
    }
    
    return 0;
}
