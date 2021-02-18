#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, book, fnum;
    int matrix[200][200];
    while (cin >> n >> m)
    {
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < n; i++)
        {
            cin >> book;
            matrix[i][book] = 1;
            matrix[i][0] = book;
        }
        for (int i = 0; i < n; i++)
        {
            fnum = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[j][matrix[i][0]] == 1)
                {
                    fnum++;
                }
            }
            fnum--;
            if (fnum == 0)
                cout << "BeiJu" << endl;
            else
                cout << fnum << endl;
        }
    }
    return 0;
}
