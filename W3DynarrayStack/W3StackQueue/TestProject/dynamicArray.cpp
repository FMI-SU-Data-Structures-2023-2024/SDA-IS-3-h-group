#include <iostream>
#include <cassert>

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int cap;
public:
    class Iterator {
        DynamicArray& d;
        int index;

    public:
        Iterator(DynamicArray& d, int i) : d(d), index(i) {}
        int getIndex() { return index; }
    };

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

    Iterator begin() {
        return Iterator(*this, 0);
    }

    int getSize()
    {
        return size;
    }
    
    int& getAt(int index)
    {
        return arr[index];
    }
    
    void insert(int newElement, int index)
    {
        if (0 > index || index > size)
        {
            throw "out of bounds";
        }

        if (size >= cap)
        {
            resize(cap*2);
        }

        ++size;
        for (int i = size-1; i > index; --i)
        {
            arr[i] = arr[i-1];
        }
        arr[index] = newElement;
    }

    void pushBack(int newElement)
    {
        if (size >= cap)
        {
            resize(cap * 2);
        }

        arr[size++] = newElement;
    }

    void removeAt(int index)
    {
        --size;
        for (; index < size; ++index)
        {
            arr[index] = arr[index + 1];
        }
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

    int& operator[](int index)
    {
        return getAt(index);
    }
};

class SortedDynamicArray {
private:
    DynamicArray arr;
public:
    int getAt(int index)
    {
        return arr[index];
    }
    int getSize()
    {
        return arr.getSize();
    }

    void removeAt(int index)
    {
        arr.removeAt(index);
    }

    void insert(int newElement)
    {
        int index = 0;
        for (; index < arr.getSize() && newElement > arr[index]; ++index);
        arr.insert(newElement, index);
    }
};

int main()
{
    /*DynamicArray d;
    for(int i = 0; i< 10; ++i)
    {
        d.insert(i, d.getSize());
    }

    d.removeAt(3);
    for (int i = 0; i < d.getSize(); ++i)
    {
        std::cout << d[i] << " ";
    }*/

    SortedDynamicArray sa;
    sa.insert(16);
    sa.insert(9);
    sa.insert(7);
    sa.insert(8);
    sa.insert(1);
    sa.insert(3);
    sa.insert(18);
    sa.insert(87);
    for (int i = 0; i < sa.getSize(); ++i)
    {
        std::cout << sa.getAt(i) << " ";
    }

    return 0;
}
