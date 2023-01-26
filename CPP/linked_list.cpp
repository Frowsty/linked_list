#include <iostream>
#include <typeinfo>

// this could / should probably be a struct instead since we're defaulting to public anyways
// difference between class and struct is none other than the default visibility
// class being private as default and struct being public
class Node
{
public:
    int data;
    Node* next = nullptr;

    // default constructor / destructor
    Node() = default;
    ~Node() = default;

    // constructor with data
    Node(int data) { this->data = data; }
};

class Storage
{
public:
    Node* head = nullptr;
    int index = 0;

    // default constructor / destructor
    Storage() = default;
    ~Storage() = default;

    // add item to the front of the list
    void push(int data)
    {
        Node* newNode = new Node(data);
        if (!head)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        index++;
    }

    // remove item from the front of the list and return the value of said item
    bool pop(int &data)
    {
        if (!this->head)
            return false;

        data = this->head->data;
        auto temp = this->head->next;
        delete this->head;
        this->head = temp;

        index--;

        return data;
    }

    // return the data of the current head of the list
    bool peek(int &data)
    {
        if (!this->head)
            return false;
 
        data = this->head->data;
        return data;
    }

    // checks if the linked list if empty or not by checking if we have a head object in the list
    // if a head is present the list is not empty, a list cannot have any items without the head
    bool isEmpty()
    {
        if (!this->head)
            return true;
        return false;
    }

    // Not necessary for the assignment but this function will loop the linked list and print the data
    bool printList()
    {
        if (!this->head)
            return false;

        auto temp = this->head;

        while (temp != nullptr)
        {
            std::cout << "Data: " << temp->data << "\n";

            temp = temp->next;
        }

        return true;
    }

    // This function will find the nodes of which index we want to swap
    // It then swaps the data between the nodes and returns true
    bool swap(int i, int j)
    {
        if (this->index <= i || this->index <= j && i != j)
            return false;

        Node* node1 = nullptr;
        Node* node2 = nullptr;

        auto temp = this->head;

        int k = 0;
        while (temp != nullptr)
        {
            if (k == i)
                node1 = temp;
            if (k == j)
                node2 = temp;

            k++;
            temp = temp->next;
        }

        auto tempNode = *node1;
        node1->data = node2->data;
        node2->data = tempNode.data;

        delete temp;

        return true;
    }
};
