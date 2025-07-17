///File: main.cpp

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    linkedlist* list_ = new linkedlist();
    element* e;
    e = new element(9);
    list_->InsertTail(e);
    e = new element(10);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTailNotDulicate(e);
    e = new element(8);
    list_->InsertTail(e);
    e = new element(20);
    list_->InsertTail(e);
    cout << "List: \n";
    list_->Travel();

    list_->DeleteFirst();
    cout << "\nList: \n";
    list_->Travel();
    cout << "\n";

    cout << "Sum: " << list_->SumList();
    cout << "\n";
    list_->removeAll();
    list_->Travel();

    cout << "Max number: " << list_->MaxList();
    cout << "\n";

    element* e1 = new element(20);
    list_->InsertAfterP(e1, e);
    cout << "List: \n";
    list_->Travel();

    list_->DeleteP(e1);
    cout << "\nList xoa 20: \n";
    list_->Travel();

    cout << "\nDuplicate:" << list_->CountDuplicate(8);
    cout << "\nDuplicate:" << list_->CountDuplicate(10);
    cout << "\nDuplicate:" << list_->CountDuplicate(20);

    linkedlist* list1 = new linkedlist();
    linkedlist* list2 = new linkedlist();

    list_->Split2List(8, list1, list2);
    cout << "\nList 1:";
    list1->Travel();
    cout << "\nList 2:";
    list2->Travel();

    return 0;
}
