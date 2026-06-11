#include <iostream>
#include <string>
using namespace std;

class Node 
{
public :
    string info;
    Node *leftchild;
    Node *rightchild;

    Node(string i, Node *l, Node *r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    void insert(string elemnt)
    {
        Node *newnode = new Node(elemnt, NULL, NULL);

        newNode->info = elemnt;
        newNode->leftchild = NULL;
        newNode->rightchild = NULL;

        Node *parent = NULL;
        Node *currentNode = NULL;

        search(elemnt, parent, currentNode);

        if (parent == NULL)
        {
            root = newNode;
            return
        }
        else if (elemnt < parent->info)
        {
            parent->leftchild = newNode;
        }
        else
        {
            parent->rightchild = newNode;
        }