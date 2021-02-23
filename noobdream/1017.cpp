#include <iostream>
using namespace std;

typedef long long ll;

ll cal_pow(int num, int idx)
{
    if (idx == 0)
        return 1;
    if (idx == 1)
        return num;
    ll temp = 0;
    temp = cal_pow(num, idx / 2) % 233333;
    if (idx % 2 == 0)
        return (temp * temp) % 233333;
    else
        return (temp * temp * num) % 233333;
}

int main(int argc, char const *argv[])
{
    int  num, idx;
    cin >> num >> idx;
    cout << cal_pow(num % 233333, idx) << endl;
    return 0;
}
