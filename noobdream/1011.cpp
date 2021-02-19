#include <iostream>
using namespace std;

const int month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cal_diff_days(int m, int d)
{
    int days = 0;
    for (size_t i = 3; i < m - 1; i++)
    {
        days += month_days[i];
    }
    days = days + d - 12;
    return days;
}

int main(int argc, char const *argv[])
{
    int m, d;
    cin >> m >> d;
    int num = cal_diff_days(m, d);
    num %= 7;
    switch (num)
    {
    case 0:
        cout << "Thursday" << endl;
        break;
    case 1:
        cout << "Friday" << endl;
        break;
    case 2:
        cout << "Stateday" << endl;
        break;
    case 3:
        cout << "Sunday" << endl;
        break;
    case 4:
        cout << "Monday" << endl;
        break;
    case 5:
        cout << "Tuseday" << endl;
        break;
    case 6:
        cout << "Wednesday" << endl;
        break;
    }
    return 0;
}
