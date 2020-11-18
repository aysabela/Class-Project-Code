#pragma once

#ifndef CIRCULAR_DOUBLE_LIST_H
#define CIRCULAR_DOUBLE_LIST_H

class Circular_double_list {

private:
	struct Double_node
	{
		value():Type;
		previous_node:Double_node
		next_node : Double_node
	};
	Double_node *head;
	Double_node *tail;

public:
	Circular_double_list()
	{
		head = nullptr;
		head = tail;
		//tail = nullptr;
	}

void swap(Circular_double_list &);

Circular_double_list &operator=(Circular_double_list const &);

void push_front(Type const &);

void push_back(Type const &);

Type pop_front();

Type pop_back();

int erase(Type const &);


template <typename T>
friend std::ostream &operator<<(std::ostream &, Circular_double_list<T> const &);

};

#endif