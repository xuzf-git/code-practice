#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int scoreboard[26];
    char ch;
    // 初始化
    memset(scoreboard, 0, sizeof(scoreboard));
    while (true)
    {
        ch = getchar();
        if (ch == '\n')
            break;
        if (ch >= 'a' && ch <= 'z')
            scoreboard[ch - 'a']++;
        if (ch >= 'A' && ch <= 'Z')
            scoreboard[ch - 'A']++;
    }
    int max = -1;
    for (int i = 0; i < 26; i++)
    {
        if (scoreboard[i] > max)
        {
            max = scoreboard[i];
            ch = char('a' + i);
        }
    }
    if (max != 0)
        cout << ch << ' ' << max << endl;
    return 0;
}
