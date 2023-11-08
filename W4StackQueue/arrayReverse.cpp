#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);    
    }
    
    std::stack<int> st;
    for(int i = 0; i < 10; i++){
        st.push(v[i]);
    }
    v.clear();
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(st.top());  
        st.pop();
    }
    
    
    for(int i = 0; i < 10; ++i)
    {
        cout<< v[i] << " ";
    }

    return 0;
}
