#pragma once
#include "List.h"
#include <algorithm>
#ifndef DEQUEUEA_H
#define DEQUEUEA_H

template <typename Type>
class DeQueueA {
private:
	Single_list<Type> list;
	Type *array;
	int dequeue_size;
	int ifront;
	int iback;
	int array_capacity;
public:
	DeQueueA(int = 10);
	~DeQueueA();
	bool empty() const;
	Type top() const;
	void push_back(Type const &);
	Type pop_front() const;
	Type push_front(Type const &obj)

};

template<typename Type>
DeQueueA<Type>::DeQueueA(int n) :
	ifront(0),
	iback(-1),
	dequeue_size(0),
	array_capacity(std::max(1, n)),
	array(new Type[array_capacity]) {
	// empty constructor
}

template<typename Type>
DeQueueA<Type>::~DeQueueA() {
	delete[] array;
}

template<typename Type>
bool DeQueueA<Type>::empty() {
	return (dequeue_size == 0);
}

template<typename Type>
Type DeQueueA<Type>::pop_front() const {
	if (empty()) {
		throw underflow();
	}
	--dequeue_size;
	++ifront;
	return array[ifront - 1];
}

template <typename Type>
Type DeQueueA<Type>::push_back(Type const &obj) {
	if (dequeue_size == array_capacity) {
		throw overflow();
	}

	iback = ++iback % capacity();
	array[iback] = obj;
	++dequeue_size;
}

template <typename Type>
Type DeQueueA<Type>::push_front(Type const &obj) {
	if (dequeue_size == array_capacity) {
		throw overflow();
	}
	array[dequeue_size] = obj;
	++dequeue_size;
}

template <typename Type>
Type DeQueueA<Type>::pop_back(Type const &obj) {
	if (dequeue_size == array_capacity) {
		throw overflow();
	}
	--dequeue_size;
	

template <typename Type>
void double_capacity() {
	Type *tmp_array = new Type[2 * array_capacity];
	for (int i = 0; i < array_capacity; i++) {
		tmp_array[i] = array[i];
	}

	delete[] array;
	array = tmp_array;

	array_capacity *= 2;
}

template <typename Type>
bool DeQueueA<Type>::empty() const {
	return (dequeue_size == 0);
}

template <typename Type>
void DeQueueA<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return array[ifront];
}


#endif