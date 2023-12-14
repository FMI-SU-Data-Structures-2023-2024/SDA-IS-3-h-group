#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class LinkedList {
public:
    class Node {
        friend LinkedList;

    private:
        T data;
        Node* prev;
        Node* next;

    public:
        Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
            : data(data), prev(prev), next(next) {}
    };

private:
    Node* sentinel;
    int size;

    Node* getNode(int index) {
        if (index < 0) {
            throw "negative index";
        }
        if (index > size) {
            throw "out of bounds";
        }

        Node* temp = getHead();
        while (temp != sentinel && index != 0) {
            temp = temp->next;
            --index;
        }

        return temp;
    }

public:
    LinkedList() : sentinel(new Node()), size(0) {
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
        while (size > 0) {
            popBack();
        }

        delete sentinel;
    }

    Node* getHead() { return sentinel->next; }
    Node* getTail() { return sentinel->prev; }

    void addFront(T item) {
        add(0, item);
    }

    void add(int index, T item) {
        Node* temp = getNode(index);
        Node* newNode = new Node(item, temp->prev, temp);        
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
        size++;
    }

    void remove(int index) {
        Node* temp = getNode(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        size--;
    }

    T get(int index) {
        Node* temp = getNode(index);
        return temp->data;
    }

    void popBack() {
        remove(size - 1);
    }
};

int main() {
    LinkedList<int> list;
    int n = 10;

    for (int i = 0; i < n; ++i) {
        list.add(0, i);
    }

    for (int j = 0; j < n; ++j) {
        std::cout << list.get(j) << " ";
    }

    return 0;
}