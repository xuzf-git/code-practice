#include <iostream>
using namespace std;

typedef struct Node {
    int Element;
    struct Node *Next;
} Node;

void bubble_sort(Node *list)
{
    int temp;
    Node *p = NULL;
    for (size_t i = 0; i < 5; i++)
    {
        p = list->Next;
        while (p->Next != NULL)
        {
            if (p->Element > p->Next->Element)
            {
                temp = p->Element;
                p->Element = p->Next->Element;
                p->Next->Element = temp;
            }
            p = p->Next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int num;
    Node *list = (Node *)malloc(sizeof(Node));
    list->Next = NULL;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> num;
        Node *p = (Node *)malloc(sizeof(Node));
        p->Element = num;
        p->Next = list->Next;
        list->Next = p;
    }
    bubble_sort(list);
    Node *p = list;
    while (p->Next != NULL)
    {
        cout << p->Next->Element << ' ';
        p = p->Next;
    }
    cout << endl;
    return 0;
}
