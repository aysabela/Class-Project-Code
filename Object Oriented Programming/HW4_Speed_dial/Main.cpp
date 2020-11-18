/// How does the use of the Manager class avoid memory leak?
/// Write your answer here.
//ALYSSA'S ANSWER :) : The use of the Manager class provides I would say a centralized place for control of the main phone array. With Manager class being the main
//owner of the array not only is it simpler to use, we also know where and when memory gets allocated. We also know because it belongs to Manager class that Manager class
//will be responsible for memory deallocation through its destructor. Also, within its cpp is where the file gets read, so there we have another instance of preventative measures
//for memory leak occuring. 

#include <iostream>
#include "PhoneMgr.h"
#include <stdlib.h>   /// For using atoi()
#include <sstream>
#include <cstdlib>

using namespace std;

int main()

{

	string input;
	PhoneMgr pm;
	/// TO DO: Get the record count of the phone system
	int recordCount = pm.getRecordCount();

	do
	{
		cout << "Enter D for listing, R for random choice, Q for quit, or an index number: ";
		cin >> input;
		if (input == "D" || input == "d") {
			pm.Display();
			cout << endl;
		}
		else if (input == "R" || input == "r") {
			pm.Random();
		}
		else if (input == "Q" || input == "q") {
			cout << "Bye.";
		}
		else {

			/// TO DO:  Convert the string to an int and check if is in the range.

			/// If it is, call Dial() function of PhoneMgr class.

			/// You may have to pass the converted int to the function.

			int number = stoi(input);

			if (number <= recordCount && (number >= 1)) {
				pm.Dial(number);
			}
			else {
				cout << "Not available. Please try again.";
			}

			cout << endl;

		}

	} while (input != "Q" && input != "q");


	system("pause");
	return 0;

}