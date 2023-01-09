#include<iostream>
#include<queue>

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

BSTNode* Insert(BSTNode* root, int data)
{
    //Since we are taking root as a local variable of the main function
    //When the pointer toroot is NULL, the pointer must changed to point to new root address
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

bool Search(BSTNode* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(root->data > data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right,  data);
    }
}

BSTNode* Find(BSTNode* root, int data)
{
    if(root == NULL) return NULL;
    else if(root->data == data) return root;
    else if(root->data > data)
    {
        return Find(root->left, data);
    }
    else
    {
        return Find(root->right,  data);
    }
}

int FindMin(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }

    else
        return FindMin(root->left);
}

BSTNode* FindMinAddress(BSTNode* root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty\n";
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }

    else
        return FindMinAddress(root->left);
}

int FindHeight(BSTNode* root)
{
    if(root == NULL) return -1;
    
    //Height of the tree is the maximum of the height of the left-subtree and the right-subtree
    int leftheight = FindHeight(root->left);
    int rightheight = FindHeight(root->right);

    int max = leftheight>rightheight?leftheight:rightheight;

    return max + 1;
}

void LevelOrderTreversal(BSTNode*root)
{
    if(root == NULL) return;

    queue <BSTNode*> Q;
    Q.push(root);

    //while there is at least one discovered node
    while(!Q.empty())
    {
        BSTNode* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop(); //removing the element at front
    }
}
/*---------------------------------------------------------------------------------------------------------*/

void PreOrderTraversal(BSTNode* root)
{
    if(root == NULL) return;
    
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(BSTNode* root)
{
    if(root == NULL) return;

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

bool IsSubtreeLesserMethode1(BSTNode* root, int value) //TAKES O(n^2)
{
    if(root == NULL) return true;
    if(root->data < value
        && IsSubtreeLesserMethode1(root->left, value)
        && IsSubtreeLesserMethode1(root->right, value))
        return true;
    else
        return false;

}

bool IsSubtreeGreaterMethode1(BSTNode* root, int value)
{
    if(root == NULL) return true;
    if(root->data > value
        && IsSubtreeGreaterMethode1(root->left, value)
        && IsSubtreeGreaterMethode1(root->right, value))
        return true;

    else
        return false;

}

bool IsBinarySearchTreeMethode1(BSTNode* root)
{
    //return true if BST, false if negative

    if(root == NULL) return true;

    else if(IsSubtreeLesserMethode1(root->left, root->data)
        && IsSubtreeGreaterMethode1(root->right, root->data)
        && IsBinarySearchTreeMethode1(root->left)
        && IsBinarySearchTreeMethode1(root->right))
        {
            return true;
        }

    else 
        return false;
}

/*------------------------------------------------------------------------------------------------------------------------------------------*/

bool IsBinarySearchTreeUtil(BSTNode* root, int minValue, int maxValue)
{
    if(root == NULL) return true;

    if(root->data > minValue
        && root->data < maxValue
        && IsBinarySearchTreeUtil(root->left, minValue, root->data)
        && IsBinarySearchTreeUtil(root->right, root->data, maxValue))
            return true;
    
    else
     return false;
}

bool IsBinarySearchTreeMethode2(BSTNode* root)      //TAKES O(n)
{
    return IsBinarySearchTreeUtil(root, -999, 999);
}
    
/*-----------------------------------------------------------------------------------------------------------------------*/
BSTNode* Delete(BSTNode* root, int data)
{
    if(root == NULL)
        return root;

    else if (data < root->data)
        root->left = Delete(root->left, data);

    else if(data > root->data)
        root->right = Delete(root->right, data);

    else
    {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
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
            root = root->left;
            delete temp;
        }


        //Case 3: 2 Children
        else
        {
            //Find the minimum in the right subtree
            //Replace that value with the value to be deleted
            //Remove the duplicate value node
            BSTNode* temp = FindMinAddress(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

        return root;
    }

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/

BSTNode* GetSuccessor(BSTNode* root, int data)
{
    //Search the Node - O(h)
    BSTNode* current = Find(root, data);
    if(current == NULL) return NULL;

    //Case 1: Node has right subtree
    if(current->right != NULL)
    {
        return FindMinAddress(current->right);
    }

    //Case 2: No right subtree
    else
    {
        //The succcessor while be the deepest ancestor of the node
        BSTNode* successor = NULL;
        BSTNode* ancestor = root;
        while (ancestor != current)
        {
            if(current->data <ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }

        return successor;
        
    }
}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    BSTNode* root = NULL;
    //Creating an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    //Searching for a data value
    int num;
    cout<<"Enter number to be searched:";
    cin>>num;

    if(Search(root, num) == true) cout<<"\nFound!!";
    else cout<<"\nNot Found!!";
    
    //Finding minimum
    cout<<"\nThe minimum value in tree is:"<<FindMin(root);

    //Finding height
    cout<<"\nThe height of the Tree is:"<<FindHeight(root);

    //Level Order Traversal
    cout<<"\nThe level order traversal of the tree is:\n";
    LevelOrderTreversal(root);

    //PreOrder Traversal
    cout<<"\nThe PreOrder traversal of the tree is:\n";
    PreOrderTraversal(root);

    //InOrder Traversal
    cout<<"\nThe InOrder traversal of the tree is:\n";
    InOrderTraversal(root);

    //Checking to see if Tree if BST
    if(IsBinarySearchTreeMethode1(root))
        cout<<"\nThe Given tree is a BST";
    else
        cout<<"\nThe Given tree is not a BST";  
    
    return 0;
}
