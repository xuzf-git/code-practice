/*
 * @Description: 二叉树的遍历 <http://www.noobdream.com/DreamJudge/Issue/page/1161/>
 * @Author: xuzf
 * @Date: 2021-03-26 21:16:07
 * @FilePath: \practice\noobdream\1161.cpp
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode;

class BiTree
{
private:
    BiNode *root;
    BiNode *create(const string &str, int &pos);
    void inOrder(BiNode *node);

public:
    BiTree(){root = NULL;}
    void createByPrestr(const string &str);
    void inOrderRoot();
};

BiNode *BiTree::create(const string &str, int &pos)
{
    pos++;
    if (pos >= str.size() || str[pos] == '#')
    {
        return NULL;
    }
    BiNode *node = new BiNode;
    node->data = str[pos];
    node->lchild = create(str, pos);
    node->rchild = create(str, pos);
    return node;
}

void BiTree::createByPrestr(const string &str)
{
    int pos = -1;
    root = create(str, pos);
}

void BiTree::inOrder(BiNode *node)
{
    if (node == NULL)
    {
        return ;
    }
    inOrder(node->lchild);
    delete node->lchild;
    cout << node->data << ' ';
    inOrder(node->rchild);
    delete node->rchild;
}

void BiTree::inOrderRoot()
{
    inOrder(this->root);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    string str;
    while (cin >> str)
    {
        BiTree tree;
        tree.createByPrestr(str);
        tree.inOrderRoot();
    }
    
    return 0;
}
