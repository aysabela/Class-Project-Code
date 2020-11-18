#include "PhoneMgr.h"
#include <iostream>  // for using cin and cout
#include <cstdlib>   // for using atoi()
#include <fstream>   // for processing input files
#include <sstream>
#include <string>
#include <random>

using namespace std;

PhoneMgr::PhoneMgr()

{

	fstream inputFile;
	long long number;
	string firstName, lastName, temp;
	string fileName = "phonenumbers.txt";
	inputFile.open(fileName, ios::in);
	stringstream s1;
	int recordcount = 0;
	int i = 0;

	/// The array is already initialized with nullptr.

	/// TO DO:

	/// Populate the array by "newing" phone objects and save their pointers

	/// in the array, and get the total record count of the input file.

	/// Close input file to avoid memory leak.

	if (inputFile) {
		while (getline(inputFile, temp)) {
			recordCount++;
			s1 << temp;
			s1 >> number >> firstName >> lastName;
				arrPhone[i] = new Phone;
				arrPhone[i]->setPhoneNumber(number);
				arrPhone[i]->setFirstName(firstName);
				arrPhone[i]->setLastName(lastName);
				i++;
				s1.clear();
		}

	}
	else {
		cout << "Error opening file.";
	}

	inputFile.close();

	
}



PhoneMgr::~PhoneMgr() {

	for (int i = 0; i < SIZE; i++) {
		if (arrPhone[i] != nullptr) {
			delete arrPhone[i];
		}
	}

}



void PhoneMgr::Display()

{

	for (int i = 0; i < 15; i++)
	{
		cout << arrPhone[i]->getPhoneNumber() << " " << arrPhone[i]->getFirstName() << " " << arrPhone[i]->getLastName() << endl;
	}

}



void PhoneMgr::Random()

{

	/// TO DO:

	/// Randomly display a phone number, its corresponding first name and last

	/// name in three columns

	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(0, 14);
	int dice_roll = distribution(generator);
	cout << arrPhone[dice_roll]->getPhoneNumber() << " " << arrPhone[dice_roll]->getFirstName() << " " << arrPhone[dice_roll]->getLastName() << endl << endl;

}



void PhoneMgr::Dial(int number)

{

	/// TO DO:

	/// Get a number i from the user and display the phone number at the ith

	/// position, its corresponding first name and last name in three columns

	/// To the user, the first position is 1, not 0.

	/// You may have to add a parameter to the function.

	number -= 1;
	cout << arrPhone[number]->getPhoneNumber() << " " << arrPhone[number]->getFirstName() << " " << arrPhone[number]->getLastName() << endl << endl;




}



int PhoneMgr::getRecordCount() const

{

	return recordCount;

}


