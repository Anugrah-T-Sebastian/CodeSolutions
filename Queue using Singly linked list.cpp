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

class Queue
{
    public:
        Node* front = NULL;
        Node* rear = NULL;

        //To check if the Queue is empty
        bool isEmpty()
        {
            if((front == NULL) && (rear == NULL))
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
            Node* ptr = front;
            while(ptr != NULL)
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

        //To enqueue values into the Queue
        void enqueue(Node *n)
        {
            if(isEmpty())
            {
                front = n;
                rear = n;
                cout<<"Node enqueued\n";
            }
            else
            {
                if(nodeExists(n) != NULL)
                {
                    cout<<"Node already exists for the key value:"<<n->key<<"\n";
                }
                else
                {
                    rear->next = n;
                    rear = n;
                    cout<<"Node enqueue\n";
                }
            }
        }

        //To dequeue elements from the Queue
        Node* dequeue()
        {
            Node* temp = NULL;
            if(isEmpty())
            {
                cout<<"Queue underflow\n";
                return temp;
            }
            else
            {
                if(rear == front)
                {
                    temp = front;
                    int x = front->data;
                    front = NULL;
                    rear = NULL;
                    cout<<"Node value:"<<x<<" dequeued\n";
                    return temp;
                }
                else
                {
                    int x = front->data;
                    temp = front;
                    front = front->next;
                    cout<<"Node value:"<<x<<" dequeued\n";
                    return temp;
                }
                
            }          
        }

        //To count the number of elements in the count
        int count()
        {
            int count = 0;
            Node* temp = front;
            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }

        //Display the Queue
        void display()
        {
            Node* temp = front;
            while(temp != NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")\n";
                temp = temp->next;
            }
        }

        //Peek at the data member when a key is provided
         void peek(int k)
        {
            Node* temp = front;
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