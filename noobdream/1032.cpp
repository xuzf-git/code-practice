#include <iostream>
#include <map>
using namespace std;

void build_map(const string &str, map<char, int> &str_map)
{
    map<char, int>::iterator it;
    for (size_t i = 0; i < str.size(); i++)
    {
        it = str_map.find(str[i]);
        if (it != str_map.end())
            (it->second)++;
        else
            str_map[str[i]] = 1;
    }
}

bool cmp_map(const map<char, int> &map1, const map<char, int> &map2)
{
    if (map1.size() != map2.size())
        return false;
    auto it = map1.begin();
    while (it != map1.end())
    {
        auto find_res = map2.find(it->first);
        if (find_res == map2.end())
        {
            return false;
        }
        else if (find_res->second != it->second)
        {
            return false;
        }
        it++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int num;
    string stra, strb;
    map<char, int> mapa, mapb;
    cin >> num;
    while (num--)
    {
        cin >> stra >> strb;
        build_map(stra, mapa);
        build_map(strb, mapb);
        if (cmp_map(mapa, mapb))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        mapa.clear();
        mapb.clear();
    }

    return 0;
}
