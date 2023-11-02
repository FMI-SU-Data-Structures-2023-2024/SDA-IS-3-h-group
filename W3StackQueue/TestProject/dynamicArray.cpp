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

    class Iterator
    {
    public:
        Iterator(DynamicArray& arr, int index) : arr(arr), index(index) {}
        int operator*() { return arr[index]; }
        void operator++() { ++index; }
        bool operator!=(const Iterator& other) const { return arr[index] != other.arr[other.index]; }

    private:
        DynamicArray& arr;
        int index = -1;
    };
    
    int getAt(int index)
    {
        return arr[index];
    }

    int operator[](int index) 
    {  
        return getAt(index);
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

    Iterator begin()
    {
        return Iterator(*this, 0);
    }

    Iterator end()
    {
        return Iterator(*this, size);
    }
};

int main()
{
    DynamicArray d;
    for(int i=0; i< 10; ++i)
    {
        d.push_back(i);
    }

    for (DynamicArray::Iterator it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
