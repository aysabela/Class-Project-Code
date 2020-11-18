/***************************************************************
Problem: Basic ADTs
Question: Turn in your ADT code!
Name: Alyssa Ysabela Flores
ID: 1662110
Date: 9/30/2018
Status: not done, haven't fully compiled but generally functions should be fine
****************************************************************/

#pragma once
#ifndef LIST_H
#define LIST_H


class List
{
private:
	struct Node
	{
		int value;
		struct Node *next;

		Node() {
			value = 0;
			next = nullptr;
		}

		Node(int obj, Node* ptr) {
			value = obj;
			next = ptr;
		}
	};

	Node *head;

public:
	List()
	{
		head = nullptr;
	}

	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;
	double operator[](int pos);

	List(const List &list)
	{
		head = nullptr;
		Node *nodePtr = list.head;
		while (nodePtr)
		{
			appendNode(nodePtr->value);
			nodePtr = nodePtr->next;
		}
	}

	void reverse(List &list);
	int search(double);
	void insertNodeAt(int, double);
	void deleteNodeByPosition(int);

	bool empty() const;

	int front() const;

	Node*end() const;

	Node*begin() const;

	void push_front(int);

	int pop_front(int);

	int push_back(int);
	
	int pop_back(int);

	int count(int) const;

	class underflow {

	};


	~List();
};

void List::appendNode(double num)
{
	Node *newNode;  // To point to a new node
	Node *nodePtr;  // To move through the list
	newNode = new Node;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}


void List::displayList() const
{
	Node *nodePtr;  // To move through the list

					// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.

	cout << endl << endl << "List is" << endl;
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}


void List::insertNode(double num)
{
	Node *newNode;					// A new node
	Node *nodePtr;					// To traverse the list
	Node *previousNode = nullptr;	// The previous node

									// Allocate a new node and store num there.
	newNode = new Node;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node

	/*if (!head || (head->value < num))*/
	if (!head || (head->value > num))
	{
		newNode->next = head;
		head = newNode;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNode->next = newNode;
		newNode->next = nodePtr;
	}

}



void List::deleteNode(double num)
{
	Node *nodePtr;       // To traverse the list
	Node *previousNode;  // To point to the previous node

						 // If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}


List::~List()
{
	Node *nodePtr;   // To traverse the list
	Node *nextNode;  // To point to the next node

					 // Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}


double List::operator[](int pos)
{
	Node *nodePtr = head;  // To move through the lis // Position nodePtr at the head of the list.

	for (int i = 0; i < pos&&nodePtr; i++, nodePtr = nodePtr->next);

	return nodePtr ? nodePtr->value : -1.1;
}



void List::reverse(List &list)
{

	Node* prev = NULL;
	Node* current = list.head;
	Node* next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list.head = prev;
}

int List::search(double number)
{
	Node *nodePtr = head;
	Node* next = new Node;
	int position = -1;
	bool found = false;
	while (nodePtr && !found)
	{
		if (nodePtr->value == number)
		{
			found = true;
		}
		nodePtr = nodePtr->next;
		position++;

		if (!nodePtr)
		{
			position = string::npos; //-1;
		}
	}
	return position;
}


void List::insertNodeAt(int index, double num)
{
	Node *newNode;					// A new node
	Node *nodePtr;					// To traverse the list
	Node *previousNode = nullptr;	// The previous node

									// Allocate a new node and store num there.
	newNode = new Node;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head || !index)
	{
		newNode->next = head;
		head = newNode;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;
		for (int i = 0; i < index&&nodePtr; i++)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNode->next = newNode;
		newNode->next = nodePtr;

	}
}


void List::deleteNodeByPosition(int pos)
{
	Node *nodePtr;       // To traverse the list
	Node *previousNode = nullptr;  // To point to the previous node

								   // Initialize nodePtr to head of list
	if (head)
	{
		nodePtr = head;
		if (!pos)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			for (int i = 0; i < pos&&nodePtr; i++)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}


bool List::empty() const {
	return !head;
}


List::Node* List::begin() const {
	return head;
}


List::Node* List::end() const {
	return nullptr;
}


int List::front() const {
	if (head == nullptr) {
		throw underflow();
	}
	return head->value;
}


void List::push_front(int n) {
	head = new Node(n, begin());
}


int List::pop_front(int n) {
	if (empty()) {
		throw underflow();
	}

	int e = front();
	Node *nodePtr = begin();
	head = begin()->next;
	delete nodePtr;
	return e;
}

int List::push_back(int n) {
	if (empty()) {
		throw underflow();
	}

	appendNode(n);

}

int List::pop_back(int n) {
	if (empty()) {
		throw underflow();
	}

	Node *nodePtr;
	nodePtr->next = head;

	while (nodePtr != nullptr)
	{
		return nodePtr == nullptr ? delete nodePtr : nodePtr = nodePtr->next;

	}


}


int List::count(int n) const {
	int node_count = 0;
	for (Node *nodePtr = begin(); nodePtr != end(); nodePtr->next) {
		node_count += (nodePtr->value == n);
	}
	return node_count;
}


//copy constructor - THINK ABOUT TRAVERSING 
List::List(List const &list) :head(nullptr) {
	//make a copy of list
	for (Node *nodePtr = begin(); nodePtr != end(); nodePtr->next) {
		push_back(nodePtr->value);
	}
}

#endif