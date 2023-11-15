#include<iostream>
using namespace std;

template<typename T>
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
	LinkedList() {
		this->head = nullptr;
	}

	void add(T item) {
		Node* node = new Node(item);
		if (head == nullptr) {
			head = node;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = node;
	}

	void addFront(T item) {
		Node* node = new Node(item);
		if (head == nullptr) {
			head = node;
			return;
		}
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

		int count = 0;
		Node* temp = head;
		while (temp != nullptr && count < index - 1) {
			count++;
			temp = temp->next;
		}

		if (temp != nullptr) {
			node->next = temp->next;
			temp->next = node;
		}
		else {
			throw "out of bounds";
		}
	}

	void remove(int index) {
		if (head == nullptr) {
			return;
		}
		if (index < 0) {
			return;
		}
		if (index == 0) {
			removeFront();
			return;
		}

		int count = 0;
		Node* temp = head;
		while (temp != nullptr) {
			if (count == index - 1) {
				temp->next = temp->next->next;
				return;
			}
			count++;
			temp = temp->next;
		}
		throw "out of bounds";
	}

	void removeFront() {
		if (head == nullptr) {
			return;
		}
		head = head->next;
	}

	T get(int index) {
		if (head == nullptr) {
			throw "no such index";
		}
		if (index < 0) {
			throw "no such index";
		}
		if (index == 0) {
			return head->data;
		}
		int count = 0;
		T res;
		Node* temp = head;
		while (temp != nullptr) {
			if (count++ == index) {
				res = temp->data;
				return res;
			}
			temp = temp->next;
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