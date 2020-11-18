#include <iostream>
using namespace std;

class LinkedList {

private:
	struct Node {
		int data;
	    Node* next;
	};
	
	Node* head;			    //Node pointing to head
	Node* tail;				//Node pointing to tail
	int size = 0;


public: 
	LinkedList() {			//constructor
		head = nullptr;		//initialize with nullptr
		tail = nullptr;		//same here
	}

	void push(int n) {
		Node* temp = new Node;
		temp->data = n;
		temp->next = nullptr;

		if (isEmpty()) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = tail->next;
			size++;
		}
	}

	void insert(int index, int n) {
		Node* temp = new Node;
		temp->data = n;
		Node* current = head;
		Node* prev = new Node;

		if (isEmpty() || index > size){
			push(n);
		}
		else if (index == 0) {
			temp->next = head;
			head = temp;
			size++;
		}
		else {
			for (int i = 0; i < index; i++) {
				prev = current;						
				current = current->next;			
			}
			temp->next = current;
			prev->next = temp;
			size++;
		}
		
	}

	void removeByIndex(int index) {   
		Node* temp = new Node;
		Node* current = head;

		if (index == 0) {		
			temp = head->next;
			delete head;
			head = temp;
			size--;
		}
		else {
			for (int i = 1; i < index-1; i++) { 
					current = current->next;
	
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}

	bool removeByValue(int n) { 
		Node* temp = new Node;
		Node* current = head;
		Node* prev = new Node;
		
		if (head->data == n) {
			temp = head->next;
			delete head;
			head = temp;
			size--;
		}
		else {
			while (current != nullptr) {
				if (current->data == n) {
					prev->next = current->next;
					delete current;
					return true;
					size--;
				}
				else {
					prev = current;
					current = current->next;
				}
				if (current == nullptr) {
					return false;
			}
			}
		}
	}

	void print() {
		Node* current = head;
		int count = 0;
		while (current != nullptr) {
			cout << current->data << " "; 
			current = current->next;
			
		}
	}

	bool isEmpty() {
		return (head == nullptr);
	}

	 ~LinkedList() {
		Node* current = head;
		Node* temp = new Node;

		if (!isEmpty()) {
			while (current != nullptr) {
				temp = current->next;
				delete current;
				current = temp;

			}
		}
	}
};

int main() {
	LinkedList boop;
	boop.push(5);
	boop.push(6);
	boop.push(4);
	boop.insert(2,3);
	boop.removeByIndex(0);
	boop.removeByValue(5);
	boop.print();
}