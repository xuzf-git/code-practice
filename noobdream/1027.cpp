#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    string buff, buff_low;
    cin >> buff;
    buff_low = buff;
    transform(buff_low.begin(), buff_low.end(), buff_low.begin(), ::tolower);
    size_t pos = 0;
    int count = 0;
    while ((pos = buff_low.find("gzu", pos)) != string::npos)
    {
        buff.erase(pos - 3 * count, 3);
        pos++;
        count++;
    }
    cout << buff;
    return 0;
}
