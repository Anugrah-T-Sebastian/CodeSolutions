#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct BSTNode
{
    public:
        int data;
        BSTNode* left;
        BSTNode* right;
};

BSTNode* GetNewNode(int data)
{
    BSTNode* newNode =  new BSTNode();

    newNode->data = data;
    newNode->left = newNode->right =  NULL;
    
    return newNode;
}

/*--------------------------------------------------------------------------------------------------------------------------*/

BSTNode* Insert(BSTNode* root, int data)
{
    //This method is used if the root node is not a global variable
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }

    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
        

    else
    {
        root->right = Insert(root->right, data);
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

bool Search(BSTNode* root, int data)
{
    if(root == NULL)
        return false;

    else if(data < root->data)
        return Search(root->left, data);

    else if(data > root->data)
        return Search(root->right, data);

    else
        return true;
}

BSTNode* Find(BSTNode* root, int data)
{
    if(root == NULL)
    {
        cout<<"\nElement is not present in the BST";
        return NULL;
    }

    else if(data < root->data)
        return Find(root->left, data);

    else if(data > root->data)
        return Find(root->right, data);

    else
        return root;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int FindMin(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError: The BST is empty";
        return -1;
    }

    else if(root->left != NULL)
        return FindMin(root->left);

    else if(root->left == NULL)
        return root->data;
}

BSTNode* FindMinAddress(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError: The BST is empty";
        return NULL;
    }

    else if(root->left != NULL)
        return FindMinAddress(root->left);

    else if(root->left == NULL)
        return root;
}

int FindMax(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError: The BST is empty";
        return -1;
    }

    else if(root->right != NULL)
        return FindMax(root->right);

    else if(root->right == NULL)
        return root->data;
}

BSTNode* FindMaxAddress(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError: The BST is empty";
        return NULL;
    }

    else if(root->right != NULL)
        return FindMaxAddress(root->right);

    else if(root->right == NULL)
        return root;
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

int FindHeight(BSTNode* root)
{
    if(root == NULL)
        return -1;

    int leftheight = FindHeight(root->left);
    int rightheight = FindHeight(root->right);

    int height = max(leftheight,rightheight);

    return height + 1;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------*/

void LevelOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;


    queue <BSTNode*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        BSTNode* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);

        Q.pop();
    }
}

/*-----------------------------------------------------------------------------------------------------------------*/

void PreOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PostOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

bool IsSubTreeLesserMethod1(BSTNode* root, int value)
{
    if(root = NULL) return true;
    if(root->data < value
        && IsSubTreeLesserMethod1(root->left, value)
        && IsSubTreeLesserMethod1(root->right, value))
            return true;

    else
        return false;
}

bool IsSubTreeGreaterMethod1(BSTNode* root, int value)
{
    if(root = NULL) return true;
    if(root->data > value
        && IsSubTreeGreaterMethod1(root->left, value)
        && IsSubTreeGreaterMethod1(root->right, value))
            return true;

    else
        return false;
}

bool IsBSTMethod1(BSTNode* root)
{
    if(root == NULL) return true;

    else if(IsBSTMethod1(root->left)
        && IsBSTMethod1(root->right)
        && IsSubTreeLesserMethod1(root->left, root->data)
        && IsSubTreeGreaterMethod1(root->right, root->data));

    else
        return false;
}

//Second Method

bool IsBSTchecking(BSTNode* root, int minvalue, int maxvalue)
{
    if (root ==  NULL)
        return true;

    else if(root->data > minvalue
        && root->data < maxvalue
        && IsBSTchecking(root->left, minvalue, root->data)
        && IsBSTchecking(root->right, root->data, maxvalue));

    else
        return false;
}

bool IsBSTMethod2(BSTNode* root)
{
    return IsBSTchecking(root, -999, 999);
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

BSTNode* Delete(BSTNode* root, int data)
{
    if(root ==  NULL)
        return root;

    else if(data <  root->data)
        return Delete(root->left, data);

    else if(data > root->data)
        return Delete(root->right, data);

    else
    {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
        }

        //Case 2: One Child
        else if(root->left == NULL)
        {
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            BSTNode* temp = root;
            root= root->left;
            delete temp;
        }

        else
        {
            BSTNode* temp = FindMinAddress(root->right);
            root->data =  temp->data;
            root->right =  Delete(root->right, temp->data);
        }

        return root;
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

BSTNode* GetSuccessor(BSTNode* root, int data)
{
    BSTNode* current = Find(root, data);
    if(current == NULL) return NULL;

    //Case 1: Node has a right subtree
    if(current->right != NULL)
    {
        return FindMinAddress(current->right);
    }

    //Case 2: No right subtree
    else
    {
        //The successor while be the deepest ancestor of the node
        BSTNode* successor = NULL;
        BSTNode* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                //This condition will be satisfied only when ancestor reaches the deepest ancestor
                //Then put successor to ancestor, and ancestor will become equal to current node & end loop in next iteration
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }

        return successor;
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    BSTNode* root = NULL;

    cout<<"Test";

    //Creating an empty
    root = Insert(root, 15);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 4);
    root = Insert(root, 89);
    root = Insert(root, 10);
    root = Insert(root, 32);
    root = Insert(root, 28);
    root = Insert(root, 73);
    root = Insert(root, 38);
    cout<<"Test";
    root = Insert(root, 41);

    //Searching for a data value
    int num;
    cout<<"\nEnter number to be searched:";
    cin>>num;

    if(Search(root, num) == true) cout<<"\nFound!!";
    else cout<<"\nNot Found";

    //Finding minimum
    cout<<"\nThe minimum value in the tree is:"<<FindMin(root);

    //Finding height
    cout<<"\nThe height of the Tree is:"<<FindHeight(root);

    //Level Order Traversal
    cout<<"\nThe Level Order Traversal of the Tree is:";
    LevelOrderTraversal(root);

    //PreOrder Traversal
    cout<<"\nThe PreOrder Traversal of the Tree is:";
    PreOrderTraversal(root);

    //Checking to see if Tree is BST
    if(IsBSTMethod2(root))
        cout<<"\nThe Given tree is a BST";
    else
        cout<<"\nThe Given tree is not a BST";

    //Get Successor
    cout<<"\nEnter the value whose successor is to be found:";
    cin>>num;
    cout<<"\nThe successor of "<<num<<" is:"<<GetSuccessor(root, num);

    return 0;
}