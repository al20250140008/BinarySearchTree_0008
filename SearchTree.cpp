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
    Node *ROOT;

    BinaryTree()
    {
        ROOT = NULL;
    }

    void insert(string element)
    {
        Node *newnode = new Node(element, NULL, NULL);

        newnode->info = element;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;

        Node *parent = NULL;
        Node *currentNode = NULL;

        search(element, parent, currentNode);

        if (parent == NULL)
        {
            ROOT = newnode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftchild = newnode;
        }
        else if (element > parent->info)
        {
            parent->rightchild = newnode;
        }
    }

    void search(string element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = NULL;

        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;

            if (element < currentNode->info)
                currentNode = currentNode->leftchild;

            else
                currentNode = currentNode->rightchild;
            
        }
    }

    void inorder(Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node *ptr)
    {
        // performs the postorder traversal of the tree
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        