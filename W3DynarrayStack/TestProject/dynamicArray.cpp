#include <iostream>
#include <cassert>

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int cap;
public:
    DynamicArray() {
        size = 0;
        cap = 4;
        arr = new int[cap];
    }
    
    DynamicArray(const DynamicArray& other) = delete;
    
    DynamicArray& operator=(const DynamicArray& other) = delete;
    
    ~DynamicArray() {
        delete[] arr;
        arr = nullptr;
    }
    
    int getAt(int index)
    {
        return arr[index];
    }
    
    void push_back(int newElement)
    {
        if (size >= cap)
        {
            resize(cap*2);
        }
        arr[size++] = newElement;
    }
    
    void resize(int newCap)
    {
        int* temp = new int[newCap];
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i];
        }
        
        delete[] arr;
        arr = temp;
        cap = newCap;
    }
};

int main()
{
    DynamicArray d;
    for(int i=0; i< 10; ++i)
    {
        d.push_back(i);
        std::cout<< d.getAt(i)<< " ";
    }

    return 0;
}
