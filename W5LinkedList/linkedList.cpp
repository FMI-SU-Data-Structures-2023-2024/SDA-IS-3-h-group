#include<iostream>
using namespace std;

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
    public:
	
	class Node{
	private:
		T data;
		Node<T>* next;
		template<typename U>friend class LinkedList;
	public:
		Node(){
			this->next = NULL;
		}
	};
	LinkedList(){
		this->head = NULL;
	}

	void add(T item){
		Node<T>* node = new Node<T>[1];
		node->data = item;
		if(head == NULL){
			head = node;
			cout<<"new node added(firstnode) !"<<endl;
			return;
		}
		Node<T>* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
		cout<<"new node added at back!"<<endl;
	}

	void addFront(T item){
		Node<T>* node = new Node<T>[1];
		node->data = item;
		if(head == NULL){
			head = node;
			cout<<"new node added(firstnode) !"<<endl;
			return;
		}
		node->next = head;
		head = node;
		cout<<"new node added at front !"<<endl;
	}

	void add(int index, T item){
		if(index > length() || index < 0){
			cout<<"index out of bound !"<<endl;
			return;
		}
		Node<T>* node = new Node<T>[1];
		node->data = item;
		int count = 0;
		Node<T>* temp = head;
		while(temp != NULL && count < index){
			if(count == index-1){
				if(temp->next != NULL){
					node->next = temp->next;
				}
				temp->next = node;
				cout<<"new node added at index "<<index<<" !"<<endl;
				break;
			}
			count++;
			temp = temp->next;
		}
		
	}

	int length(){
		int len = 0;
		Node<int>* temp = head;
		while(temp != NULL){
			len++;
			temp = temp->next;
		}
		return len;
	}

	void displayAll(){
		if(head == NULL){
			cout<<"linked list is empty"<<endl;
			return;
		}
		cout<<endl<<"----link list items------"<<endl;
		Node<T>* temp = head;
		while(temp != NULL){
			cout<<temp->data<<" | ";
			temp = temp->next;
		}
		cout<<endl<<"--------------------------"<<endl;
	}

	void remove(){
		if(head == NULL){
			cout<<"linked list is empty !"<<endl;
			return;
		}
		if(head->next == NULL){
			head = NULL;
			cout<<"last item removed"<<endl;
			return;
		}

		Node<T>* temp = head;
		while(temp != NULL){
			if(temp->next->next == NULL){
				temp->next = NULL;
				cout<<"last item removed"<<endl;
				break;
			}
			temp = temp->next;
		}
		
	}

	void remove(int index){
		if(head == NULL){
			cout<<"linked list is empty !"<<endl;
			return;
		}
		if(index >= length() || index < 0){
			cout<<"index out of bound !"<<endl;
			return;
		}
		if(index == 0){
			removeFront();
			cout<<"item removed at index "<<index<<endl;
			return;
		}

		int count = 0;
		Node<T>* temp = head;
		while(temp != NULL){
			if(count == index - 1){
				temp->next = temp->next->next;
				cout<<"item removed at index "<<index<<endl;
				break;
			}
			count++;
			temp = temp->next;
		}
	}

	void removeFront(){
		if(head == NULL){
			cout<<"linked list is empty !"<<endl;
			return;
		}
		head = head->next;
		cout<<"front item removed"<<endl;
	}

	T get(int index){
		if(head == NULL){
			cout<<"linked list is empty !"<<endl;
			return -9999;
		}
		if(index >= length() || index < 0){
			cout<<"index out of bound !"<<endl;
			return -9999;
		}
		if(index == 0){
			return head->data;
		}
		int count = 0;
		T res;
		Node<T>* temp = head;
		while(temp != NULL){
			if(count++ == index){
				res = temp->data;
				break;
			}
			temp = temp->next;
		}
		return res;
	}
};

int main(){
    LinkedList<int> list;
	
    return 0;
}