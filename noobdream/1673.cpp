#include <iostream>
#include <algorithm>
#define MAX 10005
using namespace std;

int x[MAX], y[MAX];

int main(int argc, char const *argv[])
{
    int size, total;
    while (cin >> size)
    {
        total = 0;
        for (size_t i = 0; i < size; i++)
            cin >> x[i] >> y[i];

        sort(x, x + size);
        for (size_t i = 0; i < size; i++)
            x[i] -= i;

        sort(x, x + size);
        sort(y, y + size);
        for (int i = 0; i < size - 1 - i; i++)
        {
            total += y[size - 1 - i] - y[i];
            total += x[size - 1 - i] - x[i];
        }
        cout << total << endl;
    }

    return 0;
}
