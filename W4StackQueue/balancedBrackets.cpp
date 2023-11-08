#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string brackets = "(5+3) *() ((-1))()";
    bool valid = true;
    
    stack<char> bs;
    int brackets_len = brackets.length();
    for(int i = 0; i< brackets_len; ++i)
    {
        if(brackets[i] == '(')
            bs.push(brackets[i]);
        else if(brackets[i] == ')')
        {
            if(bs.empty())
            {
                valid = false;
                break;
            }
            bs.pop();
        }
    }
    
    if(!bs.empty())
        valid = false;
    
    cout<< valid;

    return 0;
}
