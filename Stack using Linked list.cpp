#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        int key;
        Node* next;
    
        Node()
        {
            data = 0;
            key = 0;
            next = NULL; 
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
            next = NULL;
        }
};

class Stack
{
    public:
        Node* top = NULL;

        //To check if the stack is empty
        bool isEmpty()
        {
            if(top == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        //To check if a node with given key exists
        Node* nodeExists(Node *n)
        {

            Node* ptr = top;
            while(ptr->next != NULL)
            {
                if(ptr->key == n->key)
                {
                    return ptr;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            return NULL;
        }

        //Push value into the stack
        void push(Node *n)
        {
            if(isEmpty())
            {
                top = n;
            }
            else if(nodeExists(n) != NULL)
            {
                cout<<"Node already exists of key value: "<<n->key<<"\n";
            }
            else
            {
                Node* temp = top;
                top = n;
                n->next = temp;
                cout<<"Node pushed\n";
            }
        }

        //Pop the top value from the stack
        Node* pop()
        {
            Node* temp = NULL;
            if(isEmpty())
            {
                cout<<"Stack underflow\n";
                return temp;
            }
            else
            {
                temp = top;
                top = top->next;

                cout<<"Value "<<temp->data<<" poped\n";
            }

            return temp;
        }

        //Count thel number of elements in the stack
        int count()
        {
            Node* temp = top;
            int count = 0;
            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }

        //Display the stack
        void display()
        {
            Node* temp = top;
            while(temp != NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")\n";
                temp = temp->next;
            }
        }

        //Peek at the data member when a key is provided
         void peek(int k)
        {
            Node* temp = top;
            bool flag = false;

            while(temp != NULL)
            {
                if(temp->key == k)
                {
                    cout<<"For KEY = "<<k<<", DATA = "<<temp->data<<"\n";
                    flag = true;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }

            if(flag = false)
            {
                cout<<"The given key value "<<k<<" is not present in the stack\n";
            }
        }
};