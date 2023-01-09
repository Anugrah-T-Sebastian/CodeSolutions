#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void ReversePrint(Node* head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        ReversePrint(head->next);
        cout<<head->data<<"->";
    }
}