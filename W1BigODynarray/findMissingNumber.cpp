#include <iostream>

int main() {
    // Write C++ code here
    int n;
    int arr[10000];
    bool exists[10000];
    std::cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        std::cin>> arr[i];
        exists[arr[i]-1] = true;
    }
    
    /*int result = 1;
    for(int i = 1; i < n; ++i)
    {
        result += i+1;
        result -= arr[i-1];
    }*/
    /*int result = (n*(n+1)) / 2;
    for(int i = 0; i < n-1; ++i)
    {
        result -= arr[i];
    }*/
    for(int i = 0; i<n; ++i)
    {
        if(!exists[i])
        {
            std::cout << i+1;
            break;
        }
    }
    

    return 0;
}