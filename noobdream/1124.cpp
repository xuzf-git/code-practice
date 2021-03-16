/*
 * @Description: 生化武器2 <http://www.noobdream.com/DreamJudge/Issue/page/1124/#>
 * @Author: xuzf
 * @Date: 2021-03-15 16:58:59
 * @FilePath: \practice\noobdream\1124.cpp
 */

#include <iostream>
#include <queue>
#define MAX 105
using namespace std;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char map[MAX][MAX];
int cases, row, col, t;

bool judge_S_dead()
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (map[i][j] == 'S')
                return false;
        }
    }
    return true;
}

void print()
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int gx, gy, sx, sy;
    queue<pair<int, int>> qg, qs;
    cin >> cases;
    while (cases--)
    {
        cin >> row >> col >> t;
        // 读入地图
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'G')
                    gx = i, gy = j;
                else if (map[i][j] == 'S')
                    sx = i, sy = j;
            }
            getchar();
        }
        // 初始化广搜队列
        qg.emplace(gx, gy); // 记录某个时刻G能到达的位置
        qs.emplace(sx, sy); // 记录某个时刻S能到达的位置
        bool dead = false;
        int rootx, rooty, x, y;
        int last_pos_num_g = 1, last_pos_num_s = 1;
        // 判断每个时刻S能活否？
        for (int i = 0; i < t; i++)
        {
            // 上一时刻的所有位置出队，保留本时刻可到达的位置
            last_pos_num_g = qg.size();
            while (last_pos_num_g--)
            {
                rootx = qg.front().first;
                rooty = qg.front().second;
                qg.pop();
                // 四个方向扩展
                for (size_t i = 0; i < 4; i++)
                {
                    x = rootx + dx[i];
                    y = rooty + dy[i];
                    if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] != 'G' && map[x][y] != 'X')
                    {
                        map[x][y] = 'G';
                        qg.emplace(x, y);
                    }
                }
            }
            // print();
            // 毒气G不能移动，搜索结束
            if (qg.empty())
            {
                dead = judge_S_dead();
                break;
            }
            // 当前map中没有S可走的位置，搜索结束
            if (judge_S_dead())
            {
                dead = true;
                break;
            }
            last_pos_num_s = qs.size();
            // 上一时刻的所有位置出队，保留本时刻可到达的位置
            while (last_pos_num_s--)
            {
                rootx = qs.front().first;
                rooty = qs.front().second;
                qs.pop();
                if (map[rootx][rooty] == 'G')
                    continue;
                // 四个方向扩展
                for (size_t i = 0; i < 4; i++)
                {
                    x = rootx + dx[i];
                    y = rooty + dy[i];
                    if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] != 'G' && map[x][y] != 'X' && map[x][y] != 'S')
                    {
                        map[x][y] = 'S';
                        qs.emplace(x, y);
                    }
                }
            }
            // print();
        }
        if (dead)
        {
            cout << "No" << endl;
        }
        else
        {
            print();
        }
        while (!qg.empty())
            qg.pop();
        while (!qs.empty())
            qs.pop();
    }

    return 0;
}
