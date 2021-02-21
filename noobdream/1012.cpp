#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    queue<char> character, num;
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            num.push(str[i]);
        else 
            character.push(str[i]);
    }
    while (!character.empty())
    {
        cout << character.front();
        character.pop();
    }
    while (!num.empty())
    {
        cout << num.front();
        num.pop();
    }
    cout << endl;
    
    return 0;
}
