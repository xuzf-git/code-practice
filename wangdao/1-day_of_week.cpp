/*
 * @Author: xuzf
 * @Date: 2021-01-29 20:15:40
 * @LastEditTime: 2021-01-29 21:04:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm\wdjs\datetime\2_day_of_week.cpp
 */
#include <iostream>
#include <string>
#include <map>
#define IS_LEAP_YEAR(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0;
using namespace std;

map<string, int> month_name = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}};
string week_name[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"};

class date
{
private:
    int year;
    int month;
    int day;
    int is_leap;
    const static int day_of_month[12][2];

public:
    int pass_day_num;
    int week_day;
    date(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
        this->pass_day_num = -1;
        this->week_day = -1;
        this->is_leap = IS_LEAP_YEAR(y);
    }
    void cal_pass_days();
    void cal_week_day();
    int operator-(date &b);
};

const int date::day_of_month[12][2] = {
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31};

void date::cal_pass_days()
{
    pass_day_num = 0;
    for (int i = 0; i < month - 1; i++)
    {
        pass_day_num += date::day_of_month[i][this->is_leap];
    }
    pass_day_num += this->day;
}

void date::cal_week_day()
{
    date flag(2001, 10, 14);
    flag.week_day = 0;
    int diff = *(this) - flag;
    cout << "hhhhh" << diff << endl;;
    diff %= 7;
    diff += 7;
    diff %= 7;
    this->week_day = diff;    
}

int date::operator-(date &b)
{
    int diff = 0;
    for (int y = this->year; y < b.year; y++) // 累加整年的天数（左闭右开）
        diff += this->is_leap ? 366 : 365;
    this->cal_pass_days();
    b.cal_pass_days();
    diff += this->pass_day_num; // 减去起始日期对应的该年天数
    diff -= b.pass_day_num;     // 添加终止日期对应的该年天数
    // diff += 1;                  // 相邻两天间隔为 2
    return diff;
}

int main(int argc, char const *argv[])
{
    int y, m, d;
    string month_str;
    while (cin >> d >> month_str >> y)
    {
        m = month_name[month_str];
        date t(y, m, d);
        t.cal_week_day();
        cout << week_name[t.week_day] << endl;
    }
    
    return 0;
}
