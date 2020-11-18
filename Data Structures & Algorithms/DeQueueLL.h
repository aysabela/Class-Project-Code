#pragma once
#include <algorithm>
#include "List.h"
#ifndef DEQUEUELL_H
#define DEQUEUELL_H



template <typename Type>
class DeQueueLL {
private:
	Single_list<Type> list;

public:
	bool empty();
	Type top() const;
	void push_front(Type const &);
	Type pop_front() const;
	Type push_back(Type const &obj);
	Type pop_back(Type const &obj);
};


template<typename Type>
bool DeQueueLL<Type>::empty() {
	return list.empty();
}

template<typename Type>
Type DeQueueLL<Type>::pop_front() const {
	if (empty()) {
		throw underflow();
	}

	list.pop_front(obj);

}

template <typename Type>
void DeQueueLL<Type>::push_front(Type const &) {
	list.push_front(obj);
}

template <typename Type>
Type DeQueueLL<Type>::push_back(Type const &obj) {
	list.push_back(obj);
}

template <typename Type>
Type DeQueueLL<Type>::pop_back(Type const &obj) {
	if (empty()) {
		throw overflow();
	}

	list.pop_back(obj);
}


template <typename Type>
void DeQueueLL<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}


#endif









#endif