#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char buff[100];
    scanf("%s", buff);
    for (int i = strlen(buff) - 1; i >= 0; i--)
    {
        printf("%c", buff[i]);
    }
    printf("\n");
    return 0;
}

