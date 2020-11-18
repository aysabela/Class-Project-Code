#pragma once
// FILE: table2.h
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data_field type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return value is the total number of records in the
//     Table.
//
// VALUE SEMANTICS for the Table<RecordType> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the Table<RecordType> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include "node2.h"    // Provides the node type, from Figure 6.5 on page 306
#include <cassert>

using namespace std;
using namespace main_savitch_6B;

namespace main_savitch_12B {
    template <class RecordType>
    class table {
    public:
        // MEMBER CONSTANT -- See Appendix E if this fails to compile.
        static const std::size_t TABLE_SIZE = 811;
        // CONSTRUCTORS AND DESTRUCTOR
        table();
        table(const table& source);
        ~table();
		void clear();
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const RecordType& entry);
        void remove(int key);
        void operator =(const table& source);
        // CONSTANT MEMBER FUNCTIONS
        void find(int key, bool& found, RecordType& result) const;
        bool is_present(int key) const;
		void print(int index) const;
        std::size_t size() const { return total_records; }
    private:
        main_savitch_6B::node<RecordType>* data_field[TABLE_SIZE];
        std::size_t total_records;
        // HELPER MEMBER FUNCTION
        std::size_t hash(int key) const;
    };

	template <class RecordType>
	table<RecordType>::table() { //constructor
		total_records = 0;

		for (int i = 0; i < TABLE_SIZE; i++)
		{ //initialize linked lists as null head ptr
			data_field[i] = NULL;
		}

		//test memory leakage
	//	node<RecordType> *test = new node<RecordType>;
	//	test->link_field = NULL;
	}

	template <class RecordType>
	table<RecordType>::table(const table& source) {
		node<RecordType>* tempTail;

		//initialize and copy values
		for (int i = 0; i < TABLE_SIZE; i++)
		{ //list_copy(source, head, tail)
			list_copy(source.data_field[i], data_field[i], tempTail);
			//this->data_field[i] = tempHead; //set head for data_field set
		}
		this->total_records = source.total_records;
	}

	template <class RecordType>
	table<RecordType>::~table() {
		for (int i = 0; i < TABLE_SIZE; i++)
		{ //clear via toolkit function
			list_clear(data_field[i]);
		}
	}

	template <class RecordType>
	void table<RecordType>::insert(const RecordType& entry) {
		if (is_present(entry.key) == false) //ensure no duplicate keys
		{
			node<RecordType>* cursor = data_field[hash(entry.key)]; //set cursor to head chain node

			if (cursor == NULL)
			{
				//create new head pointer (and set cursor to it)
				cursor = data_field[hash(entry.key)] = new node<RecordType>;
				cursor->data_field = entry;
				cursor->link_field = NULL;
			}
			else
			{
				//first, find insert point
				while (cursor->link_field != NULL && cursor->data_field.key != entry.key)
				{
					cursor = cursor->link_field;
				} //cursor now contains last node in list

				cursor->link_field = new node<RecordType>;
				//create new ptr, set values for new entry
				cursor = cursor->link_field;
				cursor->link_field = NULL;
				cursor->data_field = entry;
				//else - duplicate key - do not insert
			}

			total_records++; //new entry added -- increment count
		}
	}	//else, key already exists in table -- no duplicates allowed

	template <class RecordType>
	void table<RecordType>::remove(int key) {
		node<RecordType>* cursor = data_field[hash(key)],
			* precursor = NULL;

		/* find node for deletion
		(cant use is_present since we need the node address) */
		bool found = false;
		while (cursor != NULL)
		{ //search for node containing key
			if (cursor->data_field.key == key)
			{ //node found -- time to delete
				found = true;
				break;
			}
			precursor = cursor;
			cursor = cursor->link_field;
		}
		if (found == true)
		{
			//unwanted node found -- time to delete
			//cursor contains node to be deleted
			list_remove(precursor);
			total_records--;
		}
		//else - no node to delete - do nothing
	}

	template <class RecordType>
	void table<RecordType>::print(int index) const {
		node<RecordType>* cursor = data_field[index];
		//print header
		cout << "[< " << index << " >]----> ";
		while (cursor != NULL) { //traverse nodes, printing each data_field key
			cout << "[" << cursor->data_field.key << "]-->";
			cursor = cursor->link_field;
		}
		cout << " NULL" << endl; //end node
	}

	template <class RecordType>
	void table<RecordType>::operator =(const table& source) {
		if (this == &source) //handle self-assignment case
			return;

		clear(); //reset object -- prevent leaks
		node<RecordType>* tempTail;

		//initialize and copy values
		for (int i = 0; i < TABLE_SIZE; i++)
		{ //list_copy(source, head, tail)
			list_copy(source.data_field[i], data_field[i], tempTail);
			//this->data_field[i] = tempHead; //set head for data_field set
		}
		this->total_records = source.total_records;
	}

	template <class RecordType>
	void table<RecordType>::find(int key, bool& found, RecordType& result) const {
		/*Postcondition: If a record is in the Table with the specified key, then found is true and result is set to a copy of the record with that key.  Otherwise found is false and the result contains garbage. */
		node<RecordType>* cursor = data_field[hash(key)];

		found = false;
		while (cursor != NULL && cursor->data_field.key != key)
		{
			if (cursor->data_field.key == key)
			{ //we have found our match
				found = true;
				result = cursor->data_field;
				break;
			}
			//advance through list
			cursor = cursor->link_field;
		}
	}

	template <class RecordType>
	bool table<RecordType>::is_present(int key) const {
		node<RecordType>* cursor = data_field[hash(key)];

		bool found = false;
		while (cursor != NULL)
		{
			if (cursor->data_field.key == key)
			{ //we have found our match
				found = true;
				break; //escape while loop
			}
			cursor = cursor->link_field; //advance list
		}
		return found;
	}

	template <class RecordType>
	std::size_t table<RecordType>::hash(int key) const { //find which index we wish to slot our entry into
		return key % TABLE_SIZE;
	}

	template <class RecordType>
	void table<RecordType>::clear() {
		for (int i = 0; i < TABLE_SIZE; i++)
		{ //use toolkit clear on all indexes
			list_clear(data_field[i]);
		}
	}

}

//#include "table2.template" // Include the implementation

#endif
