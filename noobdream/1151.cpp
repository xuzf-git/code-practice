#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct grad_entry
{
    string name;
    int grads;
    int id;
} grad_entry;

bool cmp1(grad_entry a, grad_entry b)
{
    if (a.grads == b.grads)
        return a.id < b.id;
    return a.grads < b.grads;
}

bool cmp0(grad_entry a, grad_entry b)
{
    if (a.grads == b.grads)
        return a.id < b.id;
    return b.grads < a.grads;
}

int main(int argc, char const *argv[])
{
    vector<grad_entry> data;
    int num, flag;
    grad_entry entry;
    
    cin >> num;
    cin >> flag;
    for (size_t i = 0; i < num; i++)
    {
        cin >> entry.name >> entry.grads;
        entry.id = i;
        data.push_back(entry);
    }
    // 排序
    if (flag == 0)
        sort(data.begin(), data.end(), cmp0);
    else
        sort(data.begin(), data.end(), cmp1);

    for (auto entry : data)
    {
        cout << entry.name << " " << entry.grads << endl;
    }
    return 0;
}