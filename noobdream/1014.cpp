#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    char buff[102];
    // cin >> buff;
    cin.getline(buff, 102);
    for (size_t i = 0; i < strlen(buff); i++)
    {
        if (buff[i] >= 'a' && buff[i] <= 'w')
        {
            buff[i] += 3;
        }
        else if (buff[i] >= 'A' && buff[i] <= 'W')
        {
            buff[i] += 3;
        }
        else if (buff[i] == 'X' || buff[i] == 'x' || buff[i] == 'Y' || buff[i] == 'y' || buff[i] == 'Z' || buff[i] == 'z')
        {
            buff[i] -= 23;
        }
    }
    cout << buff << endl;
    return 0;
}
