#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string buff;
    cin >> buff;
    size_t pos = 0;
    while ((pos = buff.find("gzu")) != string::npos)
    {
        buff.erase(pos, 3);
    }
    cout << buff;
    return 0;
}
