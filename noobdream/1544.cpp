#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    ll cost = 0, num, weight, cluster1, cluster2;
    priority_queue<ll, vector<ll>, greater<ll> > clusters;
    
    // 读入数据并初始化小根堆
    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> weight;
        clusters.push(weight);
    }

    // 每次合并最小的两个堆（类似于构造 Huffman树）
    while (clusters.size() > 1)
    {
        cluster1 = clusters.top();
        clusters.pop();
        cluster2 = clusters.top();
        clusters.pop();
        // 合并出新果子堆
        clusters.push(cluster1 + cluster2);
        // 记录消耗的体力
        cost = cost + cluster1 + cluster2;
    }
    cout << cost << endl;    
    return 0;
}
