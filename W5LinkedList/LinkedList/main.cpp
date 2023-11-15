#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
public:
    class Node {
        friend LinkedList;

    private:
        T data;
        Node* next;

    public:
        Node(T data) : data(data), next(nullptr) {}
    };

private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(T item) {
        Node* node = new Node(item);
        if (!head) {
            head = node;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void addFront(T item) {
        Node* node = new Node(item);
        node->next = head;
        head = node;
    }

    void add(int index, T item) {
        if (index < 0) {
            throw "negative index";
        }
        Node* node = new Node(item);
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node* temp = head;
        int count = 0;
        while (temp && count < index - 1) {
            temp = temp->next;
            count++;
        }
        if (temp) {
            node->next = temp->next;
            temp->next = node;
        }
        else {
            throw "out of bounds";
        }
    }

    void remove(int index) {
        if (index < 0 || !head) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        int count = 0;
        while (temp && count < index - 1) {
            temp = temp->next;
            count++;
        }
        if (temp && temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else {
            throw "out of bounds";
        }
    }

    T get(int index) {
        if (index < 0 || !head) {
            throw "no such index";
        }
        Node* temp = head;
        int count = 0;
        while (temp) {
            if (count == index) {
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
        throw "out of bounds";
    }
};

int main() {
    LinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(0, i);
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << list.get(i) << " ";
    }

    return 0;
}