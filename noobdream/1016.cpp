#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string buff;
    cin >> buff;
    queue<char> character, num, others;
    for (auto ch : buff)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            character.push(ch);
        else if (ch >= '0' && ch <='9')
            num.push(ch);
        else
            others.push(ch);
    }
    while (!character.empty())
    {
        cout << character.front();
        character.pop();
    }
    cout << endl;
    while (!num.empty())
    {
        cout << num.front();
        num.pop();
    }
    cout << endl;
    while (!others.empty())
    {
        cout << others.front();
        others.pop();
    }   
    cout << endl;
    return 0;
}
