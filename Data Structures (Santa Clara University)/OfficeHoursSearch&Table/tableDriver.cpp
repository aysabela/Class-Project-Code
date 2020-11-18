#include <iostream>
#include <cstdlib>
#include <ctime>
#include "table2.h"
#include "node2.h"

using namespace std;
using namespace main_savitch_12B;
//using namespace main_savitch_6B;

struct GenericRecord {
	double data;
	int key;
};

void printTable(table<GenericRecord> t1, table<GenericRecord> t2) {

	cout << "\t\tTotal records in the first Table object is " << t1.size();
	cout << endl << "\t\tContains of the first object display at below: " << endl;

	for (int i = 0; i < 10; i++) {
		t1.print(i);
	}

	cout << "-------------------------------------------" << endl;
	cout << "\t\tTotal records in the second Table object is " << t2.size();
	cout << endl << "\t\tContains of the second object display at below: " << endl;

	for (int i = 0; i < 10; i++) {
		t2.print(i);
	}

	cout << "===========================================" << endl;

}

int main() {
	srand(time(NULL));
	table<GenericRecord> table1, table2;
	GenericRecord record;

	cout << "Instantiate two Table objects." << endl << endl;
	printTable(table1, table2);


	cout << endl << "**Using random number generator generates 70 numbers for the objects.**" << endl << endl;

	record.data = 2.5;
	for (int i = 0; i < 70; i++) { 
		record.key = rand() % 201;
		table1.insert(record);
		record.key = rand() % 201;
		table2.insert(record);
	}

	printTable(table1, table2);

	cout << endl << "**Calling clear function to clear all contents of first object.**" << endl << endl;
	table1.clear();

	printTable(table1, table2);

	cout << endl << "**Using table1 = table2 displays the assignment operator overloading.**" << endl << endl;
	table1 = table2;

	printTable(table1, table2);

	system("pause");

}

