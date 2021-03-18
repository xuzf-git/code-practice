/*
 * @Description: 石油储藏 <http://www.noobdream.com/DreamJudge/Issue/page/1564/>
 * 计算网格上的连通域个数
 * @Author: xuzf
 * @Date: 2021-03-18 19:23:40
 * @FilePath: \practice\noobdream\1564.cpp
 */

#include <iostream>
#include <queue>
#define MAX 105
using namespace std;

int row, col;
char map[MAX][MAX];
const int direction[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void bfs_merge(int rootx, int rooty)
{
    queue<pair<int, int>> bfs_queue;
    bfs_queue.emplace(rootx, rooty);
    int x, y;
    while (!bfs_queue.empty())
    {
        rootx = bfs_queue.front().first;
        rooty = bfs_queue.front().second;
        bfs_queue.pop();
        for (size_t i = 0; i < 8; i++)
        {
            x = rootx + direction[i][0];
            y = rooty + direction[i][1];
            if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '@')
            {
                map[x][y] = '*';
                bfs_queue.emplace(x, y);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    while (cin >> row >> col)
    {
        if (row == 0)
            break;
        // 读入地图
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                cin >> map[i][j];
            }
            getchar();
        }
        // 遍历每个网格（如果是@，则将其联通的节点全部置为 *）
        int res = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (map[i][j] == '@')
                {
                    res++;
                    bfs_merge(i, j);
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
