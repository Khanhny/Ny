#include "BST.h"
#include <iostream>

using namespace std;
BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}
bool BST::InsertNode(Node* n)
{
    Node* p = this->root;
    Node* T = new Node();
    if (root == nullptr)
    {
        this->root = n;
        return true;
    }
    while (p != nullptr) 
    {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }
    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    return true;
}
bool BST::InsertNodeRe(Node* root, Node* p) 
{
    if (root == nullptr)
    {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey())
        return false;
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}
void BST::NLR(Node* r) 
{
    if (r != nullptr) 
    {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

void BST::LNR(Node* r) 
{
    if (r != nullptr) 
    {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}
void BST::LRN(Node* r) 
{
    if (r != nullptr)
    {
        LRN(r->Getleft());
        cout << r->Getkey() << "\n";
        LRN(r->Getright());
    }
}
void BST::TravelNLR()
{
    NLR(this->root);
}
void BST::TravelLNR() 
{
    LNR(this->root);
}
void BST::TravelLRN()
{
    LRN(this->root);
}
Node* BST::search_x(int k) 
{
    Node* p = this->root;
    if (p != NULL)
    {
        if (k == p->Getkey()) return p;
        if (k < p->Getkey())
        {
            p = p->Getleft();
            return search_x(k);
        }
        if (k > p->Getkey())
        {
            p = p->Getright();
            return search_x(k);
        }
    }
    return NULL; //Khong tim dc nut nao co khoa x
}
void BST::deleteNode(Node* n)
{
    if (n == nullptr) return;

    // Case 1: Node is a leaf
    if (n->Getleft() == nullptr && n->Getright() == nullptr)
    {
        // Special case: n is root
        if (n == root)
        {
            delete n;
            root = nullptr;
            return;
        }

        // Replace parent's child pointer without parent:
        Node* current = root;
        while (current != nullptr)
        {
            if (current->Getleft() == n)
            {
                current->Setleft(nullptr);
                break;
            }
            else if (current->Getright() == n)
            {
                current->Setright(nullptr);
                break;
            }
            else if (n->Getkey() < current->Getkey())
                current = current->Getleft();
            else
                current = current->Getright();
        }

        delete n;
    }
    // Case 2: Node has only one child (left or right)
    else if (n->Getleft() == nullptr || n->Getright() == nullptr)
    {
        Node* child = (n->Getleft() != nullptr) ? n->Getleft() : n->Getright();

        if (n == root)
        {
            delete n;
            root = child;
            return;
        }

        Node* current = root;
        while (current != nullptr)
        {
            if (current->Getleft() == n)
            {
                current->Setleft(child);
                break;
            }
            else if (current->Getright() == n)
            {
                current->Setright(child);
                break;
            }
            else if (n->Getkey() < current->Getkey())
                current = current->Getleft();
            else
                current = current->Getright();
        }

        delete n;
    }
    // Case 3: Node has two children
    else
    {
        // Use inorder successor (smallest node in right subtree)
        Node* successor = n->Getright();
        while (successor->Getleft() != nullptr)
        {
            successor = successor->Getleft();
        }

        int successorKey = successor->Getkey();
        deleteNode(successor); // Now it will be Case 1 or 2
        n->Setkey(successorKey);
    }
}

Node* BST::findNode(int key) 
{
    Node* current = this->root; // Assuming root is the root of your BST
    while (current != nullptr)
    {
        if (key == current->Getkey()) 
        {
            return current;
        }
        else if (key < current->Getkey())
        {
            current = current->Getleft();
        }
        else 
        {
            current = current->Getright();
        }
    }
    return nullptr; // If the node with the key is not found
}
int BST::SumTree() 
{
    int totalSum = 0;
    SumNodeTree(this->root, totalSum);
    return totalSum;
}


void BST::SumNodeTree(Node* r, int& totalSum)
{
    if (r != nullptr) 
    {
        totalSum += r->Getkey(); 
        SumNodeTree(r->Getleft(), totalSum);
        SumNodeTree(r->Getright(), totalSum);
    }
}
Node* BST::FindMin()
{
    return FindMinNode(this->root);
}
Node* BST::FindMinNode(Node* r)
{
    if ( r->Getleft()== nullptr)
    {
       return r;
    }
    FindMinNode(r->Getleft());
}
Node* BST::FindMax()
{
    return FindMaxNode(this->root);
}
Node* BST::FindMaxNode(Node* r)
{
    if (r->Getright() == nullptr)
    {
        return r;
    }
    FindMaxNode(r->Getright());
}
int BST::CountAllNode()
{
    int countNode = 0;
    CountNode(this->root, countNode);
    return countNode;
}

void BST::CountNode(Node* r, int& countNode)
{
    if (r != nullptr)
    {
        countNode++;
        CountNode(r->Getleft(), countNode);
        CountNode(r->Getright(), countNode);
    }
}
