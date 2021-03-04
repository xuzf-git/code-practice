#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX 5005
using namespace std;

struct pos
{
    double x, y, z;
};

pos buff[MAX];
pos mid_af;

double dist(const pos &star)
{
    return sqrt((star.x - mid_af.x) * (star.x - mid_af.x) + (star.y - mid_af.y) * (star.y - mid_af.y) + (star.z - mid_af.z) * (star.z - mid_af.z));
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> buff[i].x >> buff[i].y >> buff[i].z;
    }
    cin >> buff[n].x >> buff[n].y >> buff[n].z;
    cin >> buff[n + 1].x >> buff[n + 1].y >> buff[n + 1].z;
    mid_af.x = (buff[n].x + buff[n + 1].x) / 2;
    mid_af.y = (buff[n].y + buff[n + 1].y) / 2;
    mid_af.z = (buff[n].z + buff[n + 1].z) / 2;
    double min_dist = 300000.0;
    double tmp_dist;
    int record;
    for (size_t i = 0; i < n; i++)
    {
        tmp_dist = dist(buff[i]);
        if (tmp_dist < min_dist)
        {
            min_dist = tmp_dist;
            record = i;
        }
    }
    // cout << buff[record].x << ' ' << buff[record].y << ' ' << buff[record].z << endl;
    printf("%.3lf %.3lf %.3lf\n", buff[record].x, buff[record].y, buff[record].z);
    return 0;
}