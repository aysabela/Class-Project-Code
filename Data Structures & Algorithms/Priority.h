#pragma once
#include <algorithm>
#ifndef PRIORITY_H
#define PRIORITY_H


template <typename Type, int bork>
class Priority {
private:
	queue<Type> queue_Array[bork]
		int queue_size;

public:
	Priority(int = 10);
	~Priority();
	bool empty() const;
	Type top() const;
	void push(Type const &);
	Type pop() const;

};

template<typename Type>
Priority<Type>::Priority(int n) :
	queue_size(0) {
	// empty constructor
}

template<typename Type>
Priority<Type>::~Priority() {
	delete[] array;
}

template<typename Type>
bool Priority<Type>::empty() {
	return (queue_size == 0);
}

template<typename Type>
Type Priority<Type>::pop() const {
	if (empty()) {
		throw underflow();
	}
	--queue_size;

	for loop if not empty
		return queue_array[pri].pop();
}

template <typename Type>
Type Priority<Type>::push(Type const &obj, int pri) {
	if (pri > 0 || pri >= bork) {
		throw overflow();
	}

	queue_array[pri].push(obj);
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
bool Priority<Type>::empty() const {
	return (queue_size == 0);
}

//first item in queue thats not empty
template <typename Type>
void Priority<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	for (int i = pri; pri < M; i++) {
		(!queue_array[pri])*return that.(front);
	}
}


#endif