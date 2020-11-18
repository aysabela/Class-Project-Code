#pragma once
#ifndef STACKA_H
#define STACKA_H

template<typename Type>
class StackA {
private:
	int stack_size;
	int array_capacity;
	Type *array;
public:
	StackA(int = 10);
	~StackA();
	bool empty();
	Type top const()
	void push() (Type const &);
	Type pop() const;
};

template<typename Type>
StackA<Type>::StackA(int n) :
	StackA_size(0),
	array_capacity(std::max(1, n)),
	array(new Type[array_capacity]) {
	// empty constructor
}

template<typename Type>
StackA<Type>::~StackA() {
	delete[] array;
}

template<typename Type>
bool StackA<Type>::empty() {
	return (stack_size == 0);
}

template<typename Type>
Type StackA<Type>::top() const {
	if (empty()) {
		throw underflow();
	}
	return array[stack_size - 1];
}

template<typename Type>
Type StackA<Type>::pop() const {
	if (empty()) {
		throw underflow();
	}
	--StackA_size;
	return array[stack_size];
}

template <typename Type>
Type StackA<Type>::push(Type const &obj) {
	if (stack_size == array_capacity) {
		throw overflow();
	}
	array[stack_size] = obj;
	++stack_size;
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

#endif