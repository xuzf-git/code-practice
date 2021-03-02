#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

int convert_num(const string &ip_num)
{
    int num = 0;
    if (ip_num.size() <= 3)
    {
        for (size_t i = 0; i < ip_num.size(); i++)
        {
            if (ip_num[i] >= '0' && ip_num[i] <= '9')
            {
                num *= 10;
                num += ip_num[i] - '0';
            }
            else
                return -1;
        }
        if (num < 256 && num >= 0)
            return num;
        else
            return -1;
    }
    return -1;
}

bool judge_ip(const string &buff, int *ip)
{
    size_t pos = 0, last_pos = 0;
    string sub_str;
    int count = 0;
    size_t end_pos = buff.rfind('.');
    while ((pos = buff.find('.', last_pos)) != string::npos)
    {
        count++;
        if (count > 4 || (count == 3 && pos != end_pos))
            return false;
        // 如果是最后一个 dot, 则记录
        if (count == 3 && pos == end_pos)
        {
            sub_str = buff.substr(pos + 1);
            ip[3] = convert_num(sub_str);
            if (ip[3] < 0)
                return false;
        }
        // 获取子串
        sub_str = buff.substr(last_pos, pos - last_pos);
        // 转换成数字
        ip[count - 1] = convert_num(sub_str);
        if (ip[count - 1] < 0)
            return false;
        // 更新查找范围
        last_pos = pos + 1;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string buff;
    cin >> buff;
    int ip[4];
    if (judge_ip(buff, ip))
        printf("0x%02X%02X%02X%02X\n", ip[0], ip[1], ip[2], ip[3]);
    else
        cout << "Error" << endl;
    return 0;
}
