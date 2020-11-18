#pragma once
#include <algorithm>
#ifndef QUEUEA_H
#define QUEUEA_H


template <typename Type>
class QueueA {
private:
	Single_list<Type> list;
	Type *array;
	int queue_size;
	int ifront;
	int iback;
	int array_capacity;
public:
	QueueA(int = 10);
	~QueueA();
	bool empty() const;
	Type top() const;
	void push(Type const &);
	Type pop() const;

};

template<typename Type>
QueueA<Type>::QueueA(int n) :
	ifront(0),
	iback(-1),
	queue_size(0),
	array_capacity(std::max(1, n)),
	array(new Type[array_capacity]) {
	// empty constructor
}

template<typename Type>
QueueA<Type>::~QueueA() {
	delete[] array;
}

template<typename Type>
bool QueueA<Type>::empty() {
	return (queue_size == 0);
}

template<typename Type>
Type QueueA<Type>::pop() const {
	if (empty()) {
		throw underflow();
	}
	--queue_size;
	++ifront;
	return array[ifront - 1];
}

template <typename Type>
Type QueueA<Type>::push(Type const &obj) {
	if (queue_size == array_capacity) {
		throw overflow();
	}

	iback = ++iback % capacity();
	array[iback] = obj;
	++queue_size;
}

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
bool QueueA<Type>::empty() const {
	return (queue_size == 0);
}

template <typename Type>
void QueueA<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return array[ifront];
}


#endif
