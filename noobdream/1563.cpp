/*
 * @Description: 迷宫 <http://www.noobdream.com/DreamJudge/Issue/page/1563/>
 * @Author: xuzf
 * @Date: 2021-03-17 20:34:17
 * @FilePath: \practice\noobdream\1563.cpp
 */

#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX 105
using namespace std;

char map[MAX][MAX];
int row, col;
int sx, sy, rootx, rooty, x, y;
const int direction[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(queue<pair<int, int>> &bfs_queue)
{
    int size;
    int steps = 0;
    while (true)
    {
        size = bfs_queue.size();
        if (size == 0)
            return -1;
        steps++;
        while (size--)
        {
            rootx = bfs_queue.front().first;
            rooty = bfs_queue.front().second;
            bfs_queue.pop();

            for (size_t i = 0; i < 4; i++)
            {
                x = rootx + direction[i][0];
                y = rooty + direction[i][1];
                if (map[x][y] == 'E')
                    return steps;
                if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '*')
                {
                    bfs_queue.emplace(x, y);
                    map[x][y] = 'S';
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    queue<pair<int, int>> bfs_queue;
    while (true)
    {
        cin >> row >> col;
        if (row == 0 || col == 0)
            break;

        for (size_t i = 0; i < row; i++)
        {
            scanf("%s", map[i]);
            for (size_t j = 0; map[i][j] != '\0'; j++)
            {
                if (map[i][j] == 'S')
                    sx = i, sy = j;
            }
        }
        bfs_queue.emplace(sx, sy);
        cout << bfs(bfs_queue) << endl;
        while (!bfs_queue.empty())
            bfs_queue.pop();
    }

    return 0;
}
