#include<iostream>
using namespace std;

template<typename T>
class LinkedList{
	public:
	class Node{
	friend LinkedList;
	private:
		T data;
		Node* next;
	public:
		Node(){
			this->next = NULL;
		}
	};
    private:
        Node* head;
    public:
	LinkedList(){
		this->head = NULL;
	}

	void add(T item){
		Node* node = new Node[1];
		node->data = item;
		if(head == NULL){
			head = node;
			return;
		}
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
	}

	void addFront(T item){
		Node* node = new Node[1];
		node->data = item;
		if(head == NULL){
			head = node;
			return;
		}
		node->next = head;
		head = node;
	}

	void add(int index, T item){
		if(index < 0){
		    throw "negative index";
		}
		Node* node = new Node[1];
		node->data = item;
		int count = 0;
		Node* temp = head;
		while(temp != NULL && count < index){
			if(count == index-1){
				if(temp->next != NULL){
					node->next = temp->next;
				}
				temp->next = node;
				return;
			}
			count++;
			temp = temp->next;
		}
		throw "out of bounds";
		
	}

	void remove(int index){
		if(head == NULL){
			return;
		}
		if(index < 0){
			return;
		}
		if(index == 0){
			removeFront();
			return;
		}

		int count = 0;
		Node* temp = head;
		while(temp != NULL){
			if(count == index - 1){
				temp->next = temp->next->next;
				return;
			}
			count++;
			temp = temp->next;
		}
		throw "out of bounds";
	}

	void removeFront(){
		if(head == NULL){
			return;
		}
		head = head->next;
	}

	T get(int index){
		if(head == NULL){
			throw "no such index";
		}
		if(index < 0){
			throw "no such index";
		}
		if(index == 0){
			return head->data;
		}
		int count = 0;
		T res;
		Node* temp = head;
		while(temp != NULL){
			if(count++ == index){
				res = temp->data;
				return res;
			}
			temp = temp->next;
		}
		throw "out of bounds";
	}
};

int main(){
    LinkedList<int> list;
    
    for(int i = 0; i< 10; ++i) {
        list.add(0, i);
    }
    
    for(int i = 0; i< 10; ++i) {
        std::cout<< list.get(i)<< " ";
    }
	
    return 0;
}