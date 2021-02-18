#include <iostream>
#include <string>
using namespace std;

const int pos[2][26] = {{1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8},
                        {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4}};

int main(int argc, char const *argv[])
{
    string sentence;
    int time;
    while (cin >> sentence)
    {
        time = pos[1][sentence[0] - 'a'];
        for (size_t i = 1; i < sentence.size(); i++)
        {
            // 计算按压时间
            time += pos[1][sentence[i] - 'a'];
            // 计算等待时间
            if (pos[0][sentence[i - 1] - 'a'] == pos[0][sentence[i] - 'a'])
                time += 2;
        }
        cout << time << endl;
    }
    return 0;
}
