// Write a function to reverse a singly linked list.The function should take the head of the list and return the new head of the reversed list. 

#include <iostream>

class node
{
public:
    int value;
    node *next;
    node(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
private:
    node *head;

public:
    LinkedList() : head(nullptr) {}

    void add(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void reverse()
    {
        node *prev = nullptr;
        node *current = head;
        node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList obj;
    obj.add(6);
    obj.add(7);
    obj.add(8);

    obj.printList();
    obj.reverse();
    obj.printList();

    return 0;
}