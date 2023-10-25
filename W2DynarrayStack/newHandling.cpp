#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int* p = new (std::nothrow) int[100000000000000005];
    //assert(p != nullptr);
    //assert(p != nullptr);
    //cout<<"Exception";
    /*try
    {
        int* p = new int[16];
    }
    catch (...)
    {
        cout<< "Exception";
    }*/
    if (p == nullptr) {
        cout << "Exception";
    }

    return 0;
}
