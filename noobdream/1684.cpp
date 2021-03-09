#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    string std_str = "abcdefghijklmnopqrstuvwxyz";
    queue<char, list<char>> cqueue;
    stack<char> cstack;
    bool flag;
    while (cin >> str)
    {
        flag = true;
        for (size_t i = 0; i < 26; i++)
            cqueue.push('a' + i);

        for (size_t i = 0; i < 26; i++)
        {
            if (cqueue.empty())
            {
                flag = false;
                break;
            }
            if (str[i] > cqueue.front()) // 当前字符小于队列头，则将队列中字母入栈
            {
                while (!cqueue.empty() && cqueue.front() < str[i])
                {
                    cstack.push(cqueue.front());
                    cqueue.pop();
                }
                if (cqueue.empty())
                {
                    flag = false;
                    break;
                }
                else
                {
                    cqueue.pop();
                }
            }
            else if (str[i] == cqueue.front()) // 当前字母等于队列头，直接出队列
            {
                cqueue.pop();
            }
            else // 当前字母小于队列头，去栈中找合适的字母
            {
                if (cstack.top() != str[i])
                {
                    flag = false;
                    break;
                }
                else
                {
                    cstack.pop();
                }
            }
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        while (!cqueue.empty())
            cqueue.pop();

        while (!cstack.empty())
            cstack.pop();
    }

    return 0;
}
