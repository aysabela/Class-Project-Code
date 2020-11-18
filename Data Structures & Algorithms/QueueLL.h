#pragma once
#include <algorithm>
#ifndef QUEUELL_H
#define QUEUELL_H


template <typename Type>
class QueueLL {
private:
	Single_list<Type> list;

public:
	bool empty();
	Type top() const;
	void push(Type const &);
	Type pop() const;

};


template<typename Type>
bool QueueLL<Type>::empty() {
	return list.empty();
}

template<typename Type>
Type QueueLL<Type>::pop() const {
	if (empty()) {
		throw underflow();
	}
	
	list.pop_front(obj);
	
}

template <typename Type>
Type QueueLL<Type>::push(Type const &obj) {
	if (empty()) {
		throw overflow();
	}

	list.push_back(obj);
}



template <typename Type>
void QueueLL<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}


#endif

