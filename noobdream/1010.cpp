#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    if (a % 2 == b % 2)
    {
        return a < b;
    }
    if (a % 2 == 1 && b % 2 == 0)
    {
        return true;
    }
    if (a % 2 == 0 && b % 2 == 1)
    {
        return false;
    }
}
int main(int argc, char const *argv[])
{
    int num;
    int buff[1001];
    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> buff[i];
    }
    sort(buff, buff + num, cmp);
    for (size_t i = 0; i < num; i++)
    {
        cout << buff[i] << ' ';
    }
    cout << endl;
    return 0;
}

