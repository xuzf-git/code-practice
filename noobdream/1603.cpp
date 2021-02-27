#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    set<string> string_set;
    string temp;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        string_set.insert(temp);
    }
    cout << string_set.size() << endl;
    return 0;
}
