//#include <iostream>
//#include <cassert>
//
//using namespace std;
//
//class DynamicSortedArray {
//private:
//    int* arr;
//    int size;
//    int cap;
//public:
//    DynamicSortedArray() {
//        size = 0;
//        cap = 4;
//        arr = new int[cap];
//    }
//    
//    DynamicSortedArray(const DynamicSortedArray& other) = delete;
//    
//    DynamicSortedArray& operator=(const DynamicSortedArray& other) = delete;
//    
//    ~DynamicSortedArray() {
//        delete[] arr;
//        arr = nullptr;
//    }
//    
//    int getAt(int index)
//    {
//        return arr[index];
//    }
//    
//    void push_back(int newElement)
//    {
//        if (size >= cap)
//        {
//            resize(cap*2);
//        }
//        arr[size++] = newElement;
//    }
//    
//    void resize(int newCap)
//    {
//        int* temp = new int[newCap];
//        for (int i = 0; i < size; ++i)
//        {
//            temp[i] = arr[i];
//        }
//        
//        delete[] arr;
//        arr = temp;
//        cap = newCap;
//    }
//};
//
//int main()
//{
//    DynamicSortedArray d;
//    for(int i=0; i< 10; ++i)
//    {
//        d.push_back(i);
//        std::cout<< d.getAt(i)<< " ";
//    }
//
//    return 0;
//}
