#include "AVL_tree.h"
#include <algorithm>
using namespace std;

AVL_tree::AVL_tree() 
{
    root = nullptr;
}

AVL_tree::~AVL_tree() {}

int AVL_tree::GetHeight(Node* p) 
{
    if (p == nullptr) return 0;
    return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}

int AVL_tree::CheckBal(Node* p) 
{
    if (p == nullptr) return 0;
    int a = GetHeight(p->Getleft());
    int b = GetHeight(p->Getright());
    return GetHeight(p->Getleft()) - GetHeight(p->Getright());
}

void AVL_tree::LeftRotate(Node*& x)
{
    Node* y = x->Getright();
    Node* T2 = y->Getleft();

    y->Setleft(x);
    x->Setright(T2);

    x->Setheight(1 + max(GetHeight(x->Getleft()), GetHeight(x->Getright())));
    y->Setheight(1 + max(GetHeight(y->Getleft()), GetHeight(y->Getright())));

    x = y;
}

void AVL_tree::RightRotate(Node*& y)
{
    Node* x = y->Getleft();
    Node* T2 = x->Getright();

    x->Setright(y);
    y->Setleft(T2);

    y->Setheight(1 + max(GetHeight(y->Getleft()), GetHeight(y->Getright())));
    x->Setheight(1 + max(GetHeight(x->Getleft()), GetHeight(x->Getright())));

    y = x;
}

bool AVL_tree::InsertNode(Node* newNode) 
{
    if (newNode == nullptr) return false;
    root = InsertNode(root, newNode);
    return true;
}

Node* AVL_tree::InsertNode(Node* node, Node* newNode) 
{
    if (node == nullptr)
        return newNode;

    if (newNode->Getkey() < node->Getkey())
        node->Setleft(InsertNode(node->Getleft(), newNode));
    else if (newNode->Getkey() > node->Getkey())
        node->Setright(InsertNode(node->Getright(), newNode));
    else
        return node;  // Duplicate keys not allowed

    node->Setheight(1 + max(GetHeight(node->Getleft()), GetHeight(node->Getright())));
    int bal = CheckBal(node);

    // LL
    if (bal > 1 && newNode->Getkey() < node->Getleft()->Getkey())
        RightRotate(node);

    // RR
    else if (bal < -1 && newNode->Getkey() > node->Getright()->Getkey())
        LeftRotate(node);

    // LR
    else if (bal > 1 && newNode->Getkey() > node->Getleft()->Getkey())
    {
        Node* leftChild = node->Getleft();
        LeftRotate(leftChild);
        node->Setleft(leftChild);
        RightRotate(node);
    }

    // RL
    else if (bal < -1 && newNode->Getkey() < node->Getright()->Getkey()) 
    {
        Node* rightChild = node->Getright();
        RightRotate(rightChild);
        node->Setright(rightChild);
        LeftRotate(node);
    }

    return node;
}

// Delete interface
void AVL_tree::DeleteKey(int key) {
    root = deleteNode(root, key);
}

// Delete with balancing
Node* AVL_tree::deleteNode(Node* node, int key) 
{
    if (node == nullptr) return node;

    if (key < node->Getkey())
        node->Setleft(deleteNode(node->Getleft(), key));
    else if (key > node->Getkey())
        node->Setright(deleteNode(node->Getright(), key));
    else 
    {
        // node to delete found
        if (node->Getleft() == nullptr || node->Getright() == nullptr) 
        {
            Node* temp = node->Getleft() ? node->Getleft() : node->Getright();
            if (!temp) 
            {
                temp = node;
                node = nullptr;
            }
            else 
            {
                *node = *temp;
            }
            delete temp;
        }
        else 
        {
            Node* temp = node->Getright();
            while (temp->Getleft() != nullptr)
                temp = temp->Getleft();
            node->Setkey(temp->Getkey());
            node->Setright(deleteNode(node->Getright(), temp->Getkey()));
        }
    }

    if (node == nullptr) return node;

    node->Setheight(1 + max(GetHeight(node->Getleft()), GetHeight(node->Getright())));
    int bal = CheckBal(node);

    if (bal > 1 && CheckBal(node->Getleft()) >= 0)
        RightRotate(node);

    else if (bal > 1 && CheckBal(node->Getleft()) < 0) 
    {
        Node* leftChild = node->Getleft();
        LeftRotate(leftChild);
        node->Setleft(leftChild);
        RightRotate(node);
    }

    else if (bal < -1 && CheckBal(node->Getright()) <= 0)
        LeftRotate(node);

    else if (bal < -1 && CheckBal(node->Getright()) > 0) 
    {
        Node* rightChild = node->Getright();
        RightRotate(rightChild);
        node->Setright(rightChild);
        LeftRotate(node);
    }

    return node;
}

void AVL_tree::TravelNLR() 
{
    NLR(root);
    cout << endl;
}

void AVL_tree::TravelLNR()
{
    LNR(root);
    cout << endl;
}

void AVL_tree::TravelLRN()
{
    LRN(root);
    cout << endl;
}

void AVL_tree::NLR(Node* root) 
{
    if (root != nullptr)
    {
        cout << root->Getkey() << " ";
        NLR(root->Getleft());
        NLR(root->Getright());
    }
}

void AVL_tree::LNR(Node* root) 
{
    if (root != nullptr) 
    {
        LNR(root->Getleft());
        cout << root->Getkey() << " ";
        LNR(root->Getright());
    }
}

void AVL_tree::LRN(Node* root) 
{
    if (root != nullptr) 
    {
        LRN(root->Getleft());
        LRN(root->Getright());
        cout << root->Getkey() << " ";
    }
}

Node* AVL_tree::search_x(int k, int& compareCount)
{
    Node* p = this->root;

    while (p != nullptr)
    {
        compareCount++;
        if (p->Getkey() == k)
        {
            return p;
        }
        else if (k < p->Getkey())
        {
            p = p->Getleft();
        }
        else
        {
            p = p->Getright();
        }
    }

    return nullptr;
}
void AVL_tree::printAVL(Node* root, int iSpace)
{
    if (root == NULL)
        return;
    iSpace += 8;

    printAVL(root->Getright(), iSpace);
    cout << endl;

    for (int i = 8; i < iSpace; i++)
        cout << " ";
    cout << root->Getkey() << "\n";

    printAVL(root->Getleft(), iSpace);
}

void AVL_tree::printAVLTree()
{
    printAVL(this->root, 0);
}
