#include "DoublyLinkedList.h"
//Inherit the Linked list class
class Stack : public DoublyLinkedList {
public:
    Node* top = NULL;
    int size = 0;

public:

    void push(int data); //push a value into stack
    auto pop(); //delete the top most value from stack
    void print_stack();
    void reverse();//reverse the stack
    int count(); //get the no of elements of the stack
    void delete_stack();

};

void Stack::push(int data) {
    DoublyLinkedList::insertBeg(data);
    top = start; // Update the top to the newly inserted element
    size++;
}

auto Stack::pop()
{
    auto x =top->data;
    DoublyLinkedList::deleteBeg();
    top = start; // Update the top to the new top element
    size--;
    return x;
}
void Stack::print_stack()
{
    DoublyLinkedList::print();
}
void Stack::reverse()
{
    //3 pointers to reverse the stack
     //pointing to previous node
    Node* prev = nullptr;
    //pointing to current node
    Node* current = top;
    //pointing to next node
    Node* next_node;

    //going untill current is equal to null
    while (current) {

        next_node = current->right;
        // current node updating using prev and next node
        current->right = prev;
        current->left = next_node;
        //prev and current pointers updating
        prev = current;
        current = next_node;
    }
    top = prev; // Update the top to the new top element
    start = top;
}
int Stack::count()
{
    return size;
}
void Stack::delete_stack() {
    for (int i = 0; i < size; i++) {
        DoublyLinkedList::deleteBeg();
    }
    top = nullptr;
    size = 0;
}