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

int precendence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPrefix(stack <char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());
    for(int i=0; i<infix.length(); ++i)
    {
        if(infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for(int i=0; i<infix.length(); i++)
    {
        if((infix[i] >= 'a' && infix[i]  <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix += infix[i];
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                prefix += temp;
                s.pop();
            }
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if(precendence(infix[i])>precendence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if((precendence(infix[i]) == precendence(s.top())) && (infix[i] == '^'))
                {
                    while ((precendence(infix[i]) == precendence(s.top())) && (infix[i] == '^'))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if(precendence(infix[i]) == precendence(s.top()))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precendence(infix[i]) < precendence(s.top())))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                    
                }
                
            }
            
        }
    }
    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int main()
{
    string infix_exp, prefix_exp;
    cout<<"Enter a Infix Expression: \n";
    cin>>infix_exp;
    stack <char> s;
    cout<<"\nINFIX EXPRESSION: "<<infix_exp<<"\n";
    prefix_exp = InfixToPrefix(s, infix_exp);
    cout<<"\nPREFIX EXPRESSION: "<<prefix_exp;

    return 0;
}