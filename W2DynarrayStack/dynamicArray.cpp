#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
class DynamicArray
{
private:
    T* data;
    std::size_t sz;
    std::size_t capacity;

    static const std::size_t REALLOC_STEP = 2;

public:
    DynamicArray() : data(nullptr), sz(0), capacity(0) {}
    DynamicArray(const DynamicArray &other) {
        copy(other);
    }

    DynamicArray& operator= (const DynamicArray &other) {
        if (this != &other) {
            free();
            copy(other);
        }

        return *this;
    }

    ~DynamicArray() {
        free();
    }

    void push_back(const T &elem) {
       if (sz == capacity) {
            reserve(capacity == 0 ? 1 : capacity * REALLOC_STEP);
       }

       data[sz] = elem;
       ++sz;
    }

    void pop_back() {
        --sz;
    }

    std::size_t size() const {
        return sz;
    }

    T& operator[] (std::size_t idx) {
        return data[idx];
    }

    const T& operator[] (std::size_t idx) const {
        return data[idx];
    }

private:
    void free() {
        delete[] data;
        data = nullptr;
        sz = 0;
        capacity = 0;
    }

    void copy(const DynamicArray &other) {
        if (other.capacity == 0) {
            *this = DynamicArray();

            return;
        }

        data = new T[other.capacity];
        capacity = other.capacity;
        for (sz = 0; sz < other.sz; ++sz) {
            data[sz] = other[sz];
        }
    }

    void reserve(std::size_t n) {
        T* buffer = new T[n];

        for (std::size_t i = 0; i < sz; ++i) {
            buffer[i] = data[i];
        }

        delete[] data;
        data = buffer;
        capacity = n;
    }

};

int main() {
    DynamicArray<int> v;
    
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); ++i) {
        std::cout<< v[i]<< " ";
    }

    return 0;
}