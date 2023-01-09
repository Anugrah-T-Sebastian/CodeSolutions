#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void Reverse()
{
    Node* current;
    Node* prev;
    Node* next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; 
}