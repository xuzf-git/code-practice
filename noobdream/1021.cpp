#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
    float a1, b1, a2, b2;
    char op;
    cin >> a1 >> b1 >> a2 >> b2 >> op;
    if (op == '+')
    {
        // cout << a1 + a2 << ' ' << b1 + b2 << endl;
        printf("%.1f %.1f\n", a1 + a2, b1 + b2);
    }
    else if (op == '*')
    {
        // cout << a1 * a2 - b1 * b2 << a1 * b2 + a2 * b1 << endl;
        printf("%.1f %.1f\n", a1 * a2 - b1 * b2, a1 * b2 + a2 * b1);
    }

    return 0;
}
