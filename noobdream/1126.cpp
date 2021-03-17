/*
 * @Description: 生化武器 <http://www.noobdream.com/DreamJudge/Issue/page/1126/>
 * @Author: xuzf
 * @Date: 2021-03-17 19:54:56
 * @FilePath: \practice\noobdream\1126.cpp
 */

#include <iostream>
#include <queue>
#define MAX 35
using namespace std;

char map[MAX][MAX];
const int direction[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(int argc, char const *argv[])
{
    int row, col, t;
    int sx, sy;
    bool flag;
    queue<pair<int, int>> bfs_queue;
    while (cin >> row >> col >> t)
    {
        getchar();
        for (size_t i = 0; i < row; i++)
        {
            flag = true;
            for (size_t j = 0; j < col; j++)
            {
                map[i][j] = getchar();
                if (map[i][j] == '*')
                    sx = i, sy = j;
                else if (map[i][j] == '\n')
                {
                    map[i][j] = '\0';
                    flag = false;
                    break;
                }
            }
            if (flag)
                getchar();
        }
        // bfs
        bfs_queue.emplace(sx, sy);
        map[sx][sy] = '#';
        int size, rootx, rooty, x, y;
        int steps = 0;
        bool dead = false;

        while (true)
        {
            size = bfs_queue.size();
            while (size--)
            {
                rootx = bfs_queue.front().first;
                rooty = bfs_queue.front().second;
                bfs_queue.pop();
                for (size_t i = 0; i < 4; i++)
                {
                    x = rootx + direction[i][0];
                    y = rooty + direction[i][1];
                    if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '.')
                    {
                        map[x][y] = '#';
                        bfs_queue.emplace(x, y);
                    }
                }
            }
            // 搜索深度 ++
            steps++;
            if (bfs_queue.empty() && steps < t)
            {
                dead = true;
                break;
            }
            else if (steps == t)
            {
                break;
            }
        }
        if (dead)
        {
            cout << "No" << endl;
        }
        else
        {
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < col; j++)
                {
                    cout << map[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        // 情况队列
        while (!bfs_queue.empty())
            bfs_queue.pop();
    }

    return 0;
}
