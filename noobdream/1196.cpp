#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string buff;
    string old_substr, new_substr;
    while (true)
    {
        getline(cin, buff);
        if (buff == "")
            break;
        
        cin >> old_substr >> new_substr;
        getchar();
        // cin >> old_substr >> new_substr;
        buff.replace(buff.find(old_substr), old_substr.size(), new_substr);
        cout << buff << endl;
    }
    
    return 0;
}
