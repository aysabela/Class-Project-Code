/*
	Goals: (A) Learn how to use array for storing objects
	(B) Learn how to use array for storing pointers
	(C) Compare the differences of these two methods
	Requirements:
	Follow the guidelines intertwined with the code to complete the works.
	Write comments on the top of the program to answer these questions:
	(1) Should we delete the data stored in studArr1? Why? 
	
	ALYSSA'S ANSWER: No we should not delete the data stored in studArr1 because once it
	is out of scope (end of program) it is automatically released from memory. 

	(2) Should we delete the data stored in studArr2? Why? When we delete the
	pointers, do we actually release the memory which was allocated for (1) the
	studArr2 array, (2) the pointer stored in the array, or (3) the student objects
	pointed by the pointers?
	
	ALYSSA'S ANSWER: Yes for the exact opposite reason as my answer above in which it is not 
	automatically released thus causing a memory leak. It releases the memory which was allocated for the
	pointer stored in the array.




	*/
#include <iostream>
#include <string>

	using namespace std;

	struct student
	{
		int ID = 0;
		string name = "";
		long long phone = 0;
		string addr = "";
	};

	int main()
	{
		const int SIZE = 10;
		/// TO DO: Declare a student object array here.
		student studArr1[SIZE];

		/// Check the size of the array
		cout << "The size of the studArr1: " << sizeof(studArr1) << endl;
		/// TO DO: Hard-code some data for two students
		/// Populate the 4 fields of studArr1[0] with the data: 12345, Amy, 9256776789,
		/// "123 Main St, Livermore, CA, 94550"
		studArr1[0].ID = 12345;
		studArr1[0].name = "Amy";
		studArr1[0].phone = 9256776789;
		studArr1[0].addr = "123 Main St, Livermore, CA, 94550";


		/// Populate the 4 fields of studArr1[3] with the data: 12666, Bill, 9256776000,
		/// "29 Johnson Dr, Livermore, CA, 94550"
		studArr1[3].ID = 12666;
		studArr1[3].name = "Bill";
		studArr1[3].phone = 9256776000;
		studArr1[3].addr = "29 Johnson Dr, Livermore, CA, 94550";

		cout << "Display the data in studArr1" << endl;
		/// TO DO: Use a for loop to display the data of studArr1[0] and studArr1[3]
		/// Use one line to display the information of a person
			for (int i = 0; i < SIZE; i++) {
				if (studArr1[i].ID != 0) {
					cout << studArr1[i].ID << " " << studArr1[i].name << " " << studArr1[i].phone << " " << studArr1[i].addr << endl;
				}
			}
		
		/// TO DO: Declare a student pointer array (Type 2 in the document) here. How
		/// can we initialize the pointer with nullptr ?
		student * studArr2[SIZE];

		for (int i = 0; i < SIZE; i++) {
			studArr2[i] = nullptr;
		}
		/// Check the size of the array
		cout << "The size of the studArr2: " << sizeof(studArr2) << endl;

		/// TO DO: Hard-code some data for two students
		/// Populate the 4 fields of studArr2[0] with the data: 12345, Amy, 9256776789,
		///"123 Main St, Livermore, CA, 94550"
		studArr2[0] = new student;
		studArr2[3] = new student;
		

		studArr2[0]->ID = 12345;
		studArr2[0]->name = "Amy";
		studArr2[0]->phone = 9256776789;
		studArr2[0]->addr = "123 Main St, Livermore, CA, 94550";


		/// Populate the 4 fields of studArr2[3] with the data: 12666, Bill, 9256776000,
		///"29 Johnson Dr, Livermore, CA, 94550"

		studArr2[3]->ID = 12666;
		studArr2[3]->name = "Bill";
		studArr2[3]->phone = 9256776000;
		studArr2[3]->addr = "29 Johnson Dr, Livermore, CA, 94550";

		cout << "Display the data in studArr2" << endl;
	
		/// TO DO: Use a for loop to display the data of studArr2[0] and studArr2[3]
		/// Use one line to display the information of a person
		for (int i = 0; i < SIZE; i++) {
			if (studArr2[i] != nullptr) {
				cout << studArr2[i]->ID << " " << studArr2[i]->name << " " << studArr2[i]->phone << " " << studArr2[i]->addr << endl;
			}
		}

		/// TO DO: Release data in studArr1, if needed. Answer the #1 question above.
		/// TO DO: Release data in studArr2, if needed. Answer the #2 question above.
		for (int i = 0; i < SIZE; i++) {
			if (studArr2[i] != nullptr) {
				delete studArr2[i];
			}
		}

		system("pause");
		return 0;
	}