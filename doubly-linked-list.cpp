#include "doubly-linked-list.h"
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if(size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DoublyLinkedList::full() const
{
    if(size_ == CAPACITY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node* temp;
    if(index > size_-1)
    {
        return tail_->value;
    }
    else
    {
        temp = getNode(index);
        return temp->value;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* temp = head_;
    for(int i = 0; i < size_; i++)
    {
        if(temp->value == value)
        {
            return i;
        }
        temp = temp->next;
    }
    return size_;
}

void DoublyLinkedList::print() const
{
    Node* temp = head_;
    for(int i = 0; i < size_; i++)
    {
        temp = temp->next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* temp = head_;
    int count = 0;
    while(temp->next != NULL)
    {
        if(count == index)
        {
            return temp;
        }
        count++;
        temp = temp->next;
    }
    return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node* any = new Node(value);
    if(index == 0)
    {
        if(size_ == 0)
        {
            head_ = any;
            tail_ = any;
        }
        else
        {
            head_->prev = any;
            any->next = head_;
            head_ = any;
        }
        size_++;
        return true;
    }
    else if(index == size_)
    {
        any->prev = tail_;
        tail_->next = any;
        tail_ = any;
        size_++;
        return true;
    }
    else if(index > size_)
    {
        return false;
    }
    else
    {
        Node* N1 = getNode(index - 1);
        Node* N2 = getNode(index);

        any->prev = N1;
        N1->next = any;
        N2->prev = any;
        any->next = N2;        
        size_++;
        return true;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node* front = new Node(value);
    if(size_ == 0)
    {
        head_ = front;
        tail_ = front;
    }
    else
    {
        head_->prev = front;
        front->next = head_;
        head_ = front;
    } 
   
    size_++;
    return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    Node* back = new Node(value);
    if(size_ == 0)
    {
        head_ = back;
        tail_ = back;
    }
    else
    {
        tail_->next = back;
        back->prev = tail_;
        tail_ = back;
    } 
    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if(size_ == 0)
    {
        return false;
    }
    else if(index >= size_)
    {
        return false;
    }
    else
    {
        if(index == 0)
        {
            remove_front();
        }
        else
        {
            Node* N1 = getNode(index - 1);
            Node* N2 = getNode(index + 1);

            N1->next = N2;
            N2->prev = N1;
        }
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if(size_ == 0)
    {
        return false;
    }
    else if(size_ == 1)
    {
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return true;
    }
    else
    {
        Node* temp = head_;
        temp = temp->next;
        head_ = temp;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_back()
{
    if(size_ == 0)
    {
        return false;
    }
    else if(size_ == 1)
    {
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return true;
    }
    else
    {
        Node* last = getNode(size_ - 2);
        tail_ = last;
        last->next = NULL;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(size_ == 0 || index >= size_)
    {
        return false;
    }
    else
    {
        Node* N1 = getNode(index);
        N1->value = value;
        return true;
    }
}

