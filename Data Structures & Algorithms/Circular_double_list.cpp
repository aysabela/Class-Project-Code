#include "Circular_double_list.h"
#include "Exception.h"

template <typename Type>
Circular_double_list<Type>::Circular_double_list() :
	list_head(nullptr),
	list_size(0) {
	// empty constructor
}

template <typename Type>
Circular_double_list<Type>::Circular_double_list(Circular_double_list<Type> const &list) :
	list_head(nullptr),
	list_size(0) {
	for (node*ptr = begin(); ptr != end(); ptr->next()) {
		push_back(ptr->value());
	}
}

template <typename Type>
Circular_double_list<Type>::~Circular_double_list() {
	{
		ListNode *nodePtr;   
		ListNode *nextNode;  
	
		nodePtr = head;

		while (nodePtr != nullptr)
		{
			nextNode = nodePtr->next;

			delete nodePtr;

			nodePtr = nextNode;
		}
}

template <typename Type>
int Circular_double_list<Type>::size() const {
	if (empty()) {
		throw Exception();
	}
	nodePtr = head;
	nextNode = nodePtr->next;
	while (nextNode != head) {
		int count++; 
	}
	return count;
}

template <typename Type>
bool Circular_double_list<Type>::empty() const {
	!head = true;
	return true;
}

template <typename Type>
Type Circular_double_list<Type>::front() const {
	if (empty()) {
		throw underflow();
	}
	return head->value = Type();
}

template <typename Type>
Type Circular_double_list<Type>::back() const {
	if (empty()) {
		throw underflow();
	}

	nodePtr = head;
	nextNode = nodePtr->next;
	while (nextNode != head) {
		nextNode = tail;
	}
	return Type();
}

template <typename Type>
Double_node<Type> *Circular_double_list<Type>::head() const {
	return head;
}

template <typename Type>
int Circular_double_list<Type>::count(Type const &obj) const {
	int node_count = 0;
	for (node*ptr = begin(); ptr != end(); ptr->next()) {
		node_count += (ptr->value == n);
	}
	return node_count;
	return 0;
}

template <typename Type>
void Circular_double_list<Type>::swap(Circular_double_list<Type> &list) {
	std::swap(list_head, list.list_head);
	std::swap(list_size, list.list_size);
}

template <typename Type>
Circular_double_list<Type> &Circular_double_list<Type>::operator=(Circular_double_list<Type> const &rhs) {
	Circular_list<Type> copy(rhs);

	swap(copy);

	return *this;
}

template <typename Type>
void Circular_double_list<Type>::push_front(Type const &obj) {
	//head = new Node(n, begin());
	Double_node *nodePtr;
	Double_node *nextNode;
	Double_node *prevNode;
	Double_node *currentNode;
	Double_node *newNode;
	
	nextNode = currentNode;
	prevNode = last->next;
	newNode->head;


	nodePtr = head;

	if (empty()) {
		throw underflow();
	}

	while(nextNode)
		//while (nodePtr->next)
		//	nodePtr = nodePtr->next;

		//// Insert newNode as the last node.
		//nodePtr->next = newNode;
	}
}

template <typename Type>
void Circular_double_list<Type>::push_back(Type const &obj) {
	// enter your implementation here
}

template <typename Type>
Type Circular_double_list<Type>::pop_front() {
	if (empty()) {
		throw underflow();
	}

	int e = front();
	node *ptr = begin();
	head = begin()->next();
	delete ptr;
	return e;
	return Type();
}

template <typename Type>
Type Circular_double_list<Type>::pop_back() {
	// enter your implementation here
	return Type();
}

template <typename Type>
int Circular_double_list<Type>::erase(Type const &obj) {
	// enter your implementation here
	return 0;
}

// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator<<(std::ostream &out, Circular_double_list<T> const &list) {
	if (list.empty()) {
		out << "->0";
		return out;
	}

	Double_node<T> *ptr = list.head();

	for (int i = 0; i <= list.size(); ++i) {
		out << "->" << ptr->retrieve();
		ptr = ptr->next();
	}

	out << std::endl;

	ptr = list.head();

	for (int i = 0; i <= list.size(); ++i) {
		out << "->" << ptr->retrieve();
		ptr = ptr->previous();
	}

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?