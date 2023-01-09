#include <iostream>
#include <string>

using namespace std;

char caesar(char);
int main()
{
    string input;
    cout << "Enter cipertext and press enter to continue." << endl;
    getline(cin, input);
    string output = "";
    for (int x = 0; x < input.length(); x++)
    {
        output += caesar(input[x]);
    }
    cout << output << endl;

    return 0;
  
}
 
char caesar(char c)
{
    if (isalpha(c))
    {
        c = toupper(c); 
        c = (((c - 65) + 13) % 26) + 65;
    }
    return c;
}