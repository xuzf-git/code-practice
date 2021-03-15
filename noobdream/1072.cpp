#include <iostream>
#include <queue>
#define MAX 202
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, b;
    int k[MAX];
    bool visited[MAX]; // 记录某层是否到达过,避免搜索陷入死循环
    cin >> n >> a >> b;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> k[i];
        visited[i] = false;
    }
    /* 解空间是一个二叉树 ： 求最短路径需要用BFS */
    queue<pair<int, int>> iqueue;
    iqueue.emplace(a, 0);
    visited[a] = true;
    int root, depth;
    while (!iqueue.empty())
    {
        root = iqueue.front().first;
        depth = iqueue.front().second;
        if (root == b)
            break;
        iqueue.pop();
        // 向下走的节点入队列
        if (root - k[root] > 0)
        {
            if (!visited[root - k[root]])
            {
                iqueue.emplace(root - k[root], depth + 1);
                visited[root - k[root]] = true;
            }
        }
        // 向上走的节点入队
        if (root + k[root] <= n)
        {
            if (!visited[root + k[root]])
            {
                iqueue.emplace(root + k[root], depth + 1);
                visited[root + k[root]] = true;
            }
        }
    }
    if (visited[b])
        cout << depth << endl;
    else
        cout << -1 << endl;
    /* 清空队列 */
    while (!iqueue.empty())
        iqueue.pop();
    return 0;
}
