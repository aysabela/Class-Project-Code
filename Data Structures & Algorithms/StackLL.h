#pragma once
#ifndef STACKLL_H
#define STACKLL_H


template <typename Type>
class StackLL {
private:
	Single_list<Type> list;
public:
	bool empty() const;
	Type top() const;
	void push(Type const &);
	Type pop();

};

template <typename Type>
bool StackLL<Type>::empty() const {
	return list.empty();
}

template <typename Type>
void StackLL<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}

template <typename Type>
void StackLL<Type>::push(Type const &) {
	list.push_front(obj);
}

template <typename Type>
void StackLL<Type>::pop() {
	if (empty()) {
		throw underflow();
	}
	list.pop_front(obj);
}

#endif
