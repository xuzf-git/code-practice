#include <iostream>
#include <cstdio>
using namespace std;
float cal(int x)
{
    if (x >= 0 && x < 2)
        return -1.0 * x + 2.5;
    if (x >= 2 && x < 4)
        return 2 - 1.5 * (x - 3.0) * (x - 3.0);
    if (x >= 4 && x < 6)
        return x / 2.0 - 1.5;
}
int main()
{
    int m, x;
    double y;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        // y = cal(x);
        printf("y=%.1f\n", cal(x));
    }
    return 0;
}