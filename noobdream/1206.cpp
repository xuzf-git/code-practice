#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_set<char> hashset;
    list<char> buff;
    char ch;
    int flag = 0;
    bool is_over = false;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            ++flag;
            // flag %= 2;
            if (flag != 2)
                continue;
        }

        if (flag == 0)
            buff.push_back(ch);
        else if (flag == 1)
            hashset.insert(ch);
        
        if (flag != 2)
            continue;

        flag = 0;        

        auto iter = buff.begin();
        while (iter != buff.end())
        {
            if (hashset.count(*iter) > 0)
                iter = buff.erase(iter);
            else
                ++iter;
        }
        iter = buff.begin();
        while (iter != buff.end())
        {
            cout << *iter;
            iter = buff.erase(iter);
        }
        cout << endl;
        hashset.clear();
    }

    return 0;
}
