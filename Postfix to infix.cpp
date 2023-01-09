#include<iostream>
#include<stack>

using namespace std;

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string PostfixToInfix(string postfix)
{
    stack <string> s;
    for(int i=0; i<postfix.length(); i++)
    {
        if((postfix[i] >= 'a' && postfix[i]  <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            cout<<"Processing OPERAND...\n";
            string op(1, postfix[i]);
            s.push(op);
        }
        else if(isOperator(postfix[i]))
        {
            cout<<"Processing OPERATOR...\n";
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string exp = "(" + op2 + postfix[i] + op1 + ")";
            s.push(exp);
        }
    }

    return s.top();
}

int main()
{
    string infix_exp, postfix_exp;
    cout<<"Enter a Postfix Expression:";
    cin>>postfix_exp;
    cout<<"\nPOSTFIX EXPRESSION: "<<postfix_exp<<"\n";
    infix_exp = PostfixToInfix(postfix_exp);
    cout<<"\nINFIX EXPRESSION: "<<infix_exp;

    return 0;
}