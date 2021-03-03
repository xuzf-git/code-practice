#include <iostream>
using namespace std;

struct node
{
    int num;
    node *next;
};

int main(int argc, char const *argv[])
{
    node *l1, *t1;
    node *l2, *t2;
    l1 = (node *)malloc(sizeof(node));
    l2 = (node *)malloc(sizeof(node));
    l1->next = NULL, l2->next = NULL;
    t1 = l1, t2 = l2;
    int s1, s2, buff;

    cin >> s1;
    for (size_t i = 0; i < s1; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        cin >> temp->num;
        temp->next = NULL;
        t1->next = temp;
        t1 = temp;
    }

    cin >> s2;
    for (size_t i = 0; i < s2; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        cin >> temp->num;
        temp->next = NULL;
        t2->next = temp;
        t2 = temp;
    }

    node *res, *tres;
    res = (node *)malloc(sizeof(node));
    res->next = NULL;
    tres = res;
    // l1 = l1->next, l2 = l2->next;
    while (l1->next != NULL && l2->next != NULL)
    {
        if (l1->next->num > l2->next->num)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->num = l2->next->num;
            temp->next = NULL;
            tres->next = temp;
            tres = temp;
            l2 = l2->next;
        }
        else
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->num = l1->next->num;
            temp->next = NULL;
            tres->next = temp;
            tres = temp;
            l1 = l1->next;
        }
    }
    while (l1->next != NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->num = l1->next->num;
        temp->next = NULL;
        tres->next = temp;
        tres = temp;
        l1 = l1->next;
    }
    while (l2->next != NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->num = l2->next->num;
        temp->next = NULL;
        tres->next = temp;
        tres = temp;
        l2 = l2->next;
    }
    while (res->next->next != NULL)
    {
        cout << res->next->num << ' ';
        res = res->next;
    }
    cout << res->next->num << endl;

    return 0;
}
