#include<iostream>
#include<stack>
#include<algorithm>

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

string PrefixToInfix(string prefix)
{
    stack <string> s;

    reverse(prefix.begin(), prefix.end());

    for(int i=0; i<prefix.length(); i++)
    {
        if((prefix[i] >= 'a' && prefix[i]  <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))
        {
            cout<<"Processing OPERAND...\n";
            string op(1, prefix[i]);
            s.push(op);
        }
        else if(isOperator(prefix[i]))
        {
            cout<<"Processing OPERATOR...\n";
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string exp = "(" + op1 + prefix[i] + op2 + ")";
            s.push(exp);
        }
    }

    return s.top();
}

int main()
{
    string infix_exp, prefix_exp;
    cout<<"Enter a Prefix Expression:";
    cin>>prefix_exp;
    cout<<"\nPREFIX EXPRESSION: "<<prefix_exp<<"\n";
    infix_exp = PrefixToInfix(prefix_exp);
    cout<<"\nINFIX EXPRESSION: "<<infix_exp;

    return 0;
}