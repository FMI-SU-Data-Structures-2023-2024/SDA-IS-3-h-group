#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    pair<int, int> p(1,2);
    pair<pair<int, int>, int> p2(p, 3);
    
    cout<< p2.first.first;

    return 0;
}
