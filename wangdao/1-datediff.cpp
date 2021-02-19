/*
 * @Author: xuzf
 * @Date: 2021-01-29 14:57:05
 * @LastEditTime: 2021-01-29 21:03:31
 * @LastEditors: Please set LastEditors
 * @Description: 计算两个日期之间相隔的天数
 * @FilePath: \algorithm\wdjs\datetime\1-datediff.cpp
 */
#include <iostream>
#include <stdio.h>
#define IS_LEAP_YEAR(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0;
using namespace std;

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
    date(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
        this->pass_day_num = -1;
        this->is_leap = IS_LEAP_YEAR(y);
    }
    void cal_pass_days();
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

int date::operator-(date &b)
{
    int diff = 0;
    for (int y = this->year; y < b.year; y++)   // 累加整年的天数（左闭右开）
        diff += this->is_leap ? 366 : 365;
    this->cal_pass_days();
    b.cal_pass_days();
    diff += this->pass_day_num; // 减去起始日期对应的该年天数
    diff -= b.pass_day_num;     // 添加终止日期对应的该年天数
    diff = diff < 0 ? -diff : diff;
    diff += 1;                  // 相邻两天间隔为 2 
    return diff;
}

int main(int argc, char const *argv[])
{
    int begin_y, begin_m, begin_d;
    int end_y, end_m, end_d;
    
    while (scanf("%4d%2d%2d", &begin_y, &begin_m, &begin_d) != EOF)
    {
        scanf("%4d%2d%2d", &end_y, &end_m, &end_d);
        date begin_date(begin_y, begin_m, begin_d);
        date end_date(end_y, end_m, end_d);
        cout << begin_date - end_date << endl;
    }
    return 0;
}


