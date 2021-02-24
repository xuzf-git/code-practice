#include <iostream>
using namespace std;

typedef struct Node
{
    int id;
    struct Node *next;
} Node, *List;

List erase(List g)
{
    List erase_one = g->next->next;
    List next_begin = erase_one->next;
    g->next->next = next_begin;
    free(erase_one);
    return next_begin;
}

int main(int argc, char const *argv[])
{
    int num;
    List head, tail;
    cin >> num;
    // 初始化循环链表
    head = (Node *)malloc(sizeof(Node));
    head->id = 1;
    head->next = head;
    tail = head;
    // 添加节点
    for (size_t i = 2; i <= num; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->id = i;
        // temp->next = head;
        tail->next = temp;
        tail = temp;
    }
    tail->next = head;
    // 循环遍历删除
    tail = head;
    while (tail != tail->next)
    {
        tail = erase(tail);
    }
    cout << tail->id << endl;
    free(tail);
    return 0;
}
