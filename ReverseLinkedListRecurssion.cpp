#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void Reverse(Node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}