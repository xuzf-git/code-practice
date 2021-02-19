#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int count = 0;
    for (int i = 1; i < 21; i++)
    {
        count += i;
    }
    cout << count << endl;
    return 0;
}
