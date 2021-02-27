#include <iostream>
#include <map>
#define MAX_LEN 200000
using namespace std;

int buff[MAX_LEN];

int main(int argc, char const *argv[])
{
    int n, c, res = 0;
    map<int, int> count;
    map<int, int>::iterator iter;

    cin >> n >> c;

    for (size_t i = 0; i < n; i++)
    {
        cin >> buff[i];

        iter = count.find(c + buff[i]);
        if (iter == count.end())
            count[c + buff[i]] = 1;
        else
            iter->second++;
    }

    for (size_t i = 0; i < n; i++)
        res += count[buff[i]];

    cout << res << endl;
    return 0;
}
