/*
desc: 一次探测再散列，求查找失败的平均查找长度
*/

#include <iostream>
#include <cstdio>
using namespace std;

void insertHash(int buff, int *hash_table, const int &m, const int &tsize)
{
    int h_steps = buff % m;
    while (hash_table[h_steps] != -1)
    {
        h_steps = (h_steps + 1) % tsize;
    }
    hash_table[h_steps] = buff;
}

int search_fail(const int &num, const int &tsize, const int &m, int *hash_table)
{
    int h0 = num % m;
    int h_steps = h0;
    int steps = 0;
    while (hash_table[h_steps] != -1 && steps < tsize)
    {
        steps++;
        h_steps = (h0 + steps) % tsize;
    }
    return steps + 1;
}

int main(int argc, char const *argv[])
{
    int tsize, m, n, buff, res = 0;
    cin >> tsize >> m >> n;
    int *hash_table = new int[tsize];
    for (size_t i = 0; i < tsize; i++)
    {
        hash_table[i] = -1;
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> buff;
        insertHash(buff, hash_table, m, tsize);
    }
    for (int i = 0; i < m; i++)
    {
        res += search_fail(i, tsize, m, hash_table);
    }

    printf("%.1f\n", (float)res / m);

    delete[] hash_table;
    return 0;
}
