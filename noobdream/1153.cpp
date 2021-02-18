#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, num;
    int min, max;
    while (cin >> n)
    {
        min = 1000001;
        max = -1000001;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            if (num < min)
                min = num;
            if (num > max)
                max = num;
        }
        cout << max << " " <<  min << endl;
    }
    return 0;
}
