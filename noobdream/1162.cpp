#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// 判断是否结束
bool judge(const string &str)
{
    return str.find("2012") != string::npos;
}
// 广搜暴力求解
int sovle(char *str, int len, int steps)
{
    char temp;
    int step_res;
    if (steps > 30)
        return -1;
    
    for (size_t i = 0; i < len - 1; i++)
    {
        /* temp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = temp; */
        swap(str[i], str[i + 1]);
        if (judge(str))
            return steps;
        swap(str[i], str[i +1]);
    }
    for (size_t i = 0; i < len - 1; i++)
    {
        swap(str[i], str[i + 1]);
        step_res = sovle(str, len, steps + 1);
        if (step_res != -1)
            return step_res;
        swap(str[i], str[i + 1]);
    }
}

int main(int argc, char const *argv[])
{
    char buff[13];
    int len;
    int zero, one, two;
    while (scanf("%d", &len) != EOF)
    {
        getchar();
        zero = 0;
        one = 0;
        two = 0;
        // 读入数据
        for (size_t i = 0; i < len; i++)
        {
            scanf("%c", &buff[i]);
            if (buff[i] == '0')
                zero++;
            else if (buff[i] == '1')
                one++;
            else if (buff[i] == '2')
                two++;
        }
        // 简化判断
        if (zero < 1 || one < 1 || two < 2)
        {
            cout << -1 << endl;
            continue;
        }
        if (judge(buff))
        {
            cout << 0 << endl;
            continue;
        }
        cout << sovle(buff, len, 1) << endl;
    }
    return 0;
}
