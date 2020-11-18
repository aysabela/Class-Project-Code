//ALYSSA'S CODE 
//Hi professor, I made sure all the error prompts were displayed at the top in proper order to be called.
//I worked closely with Ana on this code. She was mostly responsible for the complicated things such as
//the findStudentIndex (our own function) and the sort which should have utilized a heapsort.

//The find was especially useful and reminiscent of our Data Structures and Algorithm class as well as the heapsort.
//Overall, a very fun assignment.

//5. The statements:
//cin.clear();
//cin.ignore(32768, '\n');
//
//are used because the problem with strings and cin (which makes using cin by itself unreliable) 
//is that typically the '\n' gets left in the input stream. This means that when not clearing the stream
//and not putting an ignore, we are leaving the cin to take new input incorrectly which could of course
//cause faulty output. The clear makes sure we're not leaving anything in the stream (because we're using
//strings) and the ignore says to ignore 32768 characters (arbitrary number) until it hits newline, whichever
//comes first. 


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstring>

using namespace std;
struct Student {
	string ssn;
	string name;
	string gender;
};

class StudentMgr {
private:
	vector<Student> sList;
	void insertStudent(Student);
	void updateStudent(Student);
	void deleteStudent(Student);
	vector<Student>::iterator findStudentIndex(string);

public:
	StudentMgr();
	~StudentMgr();
	bool isStringDigit(string);
	void displayStudent(string);
	void displayAll();
	void sortBySSN();
};

StudentMgr::StudentMgr() {
	Student s;
	string word, name, gender, command, ssn;
	int i, holder;

	ifstream inputFile;
	stringstream ss;
	inputFile.open("students.txt");

	if (inputFile) {
		while (getline(inputFile, word)) {
			if (word.length() > 1) {
				i = word.find('\"');
				holder = word.find_last_of('\"');
				s.name = word.substr(i, holder - i + 1);
				word.erase(word.begin() + i, word.begin() + holder + 1);

				ss << word;
				ss >> command >> s.ssn >> s.gender;
				switch (command[0]) {
				case 'I':
					try {
						insertStudent(s);
					}
					catch (const char *msg) {
						clog << msg << " This ssn is invalid: " << s.ssn << endl;
					}
					break;
				case 'U':
					try {
						updateStudent(s);
					}
					catch (const char *msg) {
						clog << msg << " This ssn is invalid: " << s.ssn << endl;
					}
					break;
				case 'D':
					try {
						deleteStudent(s);
					}
					catch (const char *msg) {
						clog << msg << " This ssn is invalid: " << s.ssn << endl;
					}
					break;
				default:
					break;
				}

				ss.clear();
			}
		}
	}
	else {
		cout << "Error opening file.";
	}
	inputFile.close();
}

StudentMgr::~StudentMgr() {

}

//Professor's own isdigit given in the announcements.
bool StudentMgr::isStringDigit(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str.substr(i, 1)[0]))
			return false;
	}

	return true;
}

void StudentMgr::insertStudent(Student s) {
	if (!sList.empty()) {
		if (isStringDigit(s.ssn)) {
			auto a = findStudentIndex(s.ssn);
			if (a == sList.end()) {
				sList.push_back(s);
			}
			else {
				throw "Record already exists and therefore cannot be inserted!";
			}
		}
		else {
			throw "SSN is not made fully of numbers.";
		}
	}
	else {
		sList.push_back(s);
	}
}

void StudentMgr::updateStudent(Student s) {
	if (!sList.empty()) {
		if (isStringDigit(s.ssn)) {
			auto a = findStudentIndex(s.ssn);
			if (a != sList.end()) {
				(*a) = s;
			}
			else {
				throw "Record does not exist and therefore cannot be updated!";
			}
		}
		else {
			throw "SSN is not made fully of numbers.";
		}
	}
	else {
		throw "List is empty!";
	}
}

void StudentMgr::deleteStudent(Student s) {
	bool check = true;
	if (!sList.empty()) {
		if (isStringDigit(s.ssn)) {
			auto a = findStudentIndex(s.ssn);
			if (a != sList.end()) {
				sList.erase(a);
			}
			else {
				throw "Record does not exist and therefore cannot be deleted!";
			}
		}
		else {
			throw "SSN is not made fully of numbers.";
		}
	}
	else {
		throw "List is empty!";
	}
}

void StudentMgr::displayStudent(string ssn) {
	if (!sList.empty()) {
		auto a = findStudentIndex(ssn);
		if (a != sList.end()) {
			cout << endl << "Requested Student:\n" << (*a).ssn << " " << (*a).name << " " << (*a).gender << endl;
		}
		else {
			throw "Record does not exist and therefore cannot be displayed!";
		}
	}
	else {
		throw "List is empty!";
	}
}

void StudentMgr::displayAll() {
	if (!sList.empty()) {
		for (int i = 0; i < sList.size(); i++) {
			cout << sList.at(i).ssn << " " << sList.at(i).name << " " << sList.at(i).gender << endl;
		}
	}
	else {
		throw "Records do not exist and therefore cannot be displayed!";

	}
}

//Our own functions.
vector<Student>::iterator StudentMgr::findStudentIndex(string ssn) {
	return find_if(sList.begin(), sList.end(),
		[&](const Student &e) { return e.ssn == ssn; });
}

void StudentMgr::sortBySSN() {
	for (vector<Student>::iterator it = sList.begin(); it != sList.end();) {
		std::push_heap(sList.begin(), ++it, [](const Student &x, const Student &y) -> bool { return x.ssn < y.ssn; });
	}
	for (vector<Student>::iterator it = sList.end(); it != sList.begin();) {
		std::pop_heap(sList.begin(), it--, [](const Student &x, const Student &y) -> bool { return x.ssn < y.ssn; });
	}
}

//Professor's given main test code with sort being used.
int main() {
	StudentMgr sm;
	sm.sortBySSN();
	
	char input;

	do {
		cout << endl << endl << "Select an option:" << endl;
		cout << "-----------------" << endl << endl;
		cout << "A. Display all student info" << endl;
		cout << "S. Display specific student" << endl;
		cout << "Q. Quit the program" << endl;
		cout << "--------------------------------" << endl;
		cout << "Enter selection: ";
		cin >> input;
		cin.clear();
		cin.ignore(32768, '\n');
		input = tolower(input);
		switch (input) {
		case 'a':
			try {
				sm.displayAll();
			}
			catch (const char *msg) {
				clog << msg << endl;
			}
			break;
		case 's':
			try {
				cout << "Input SSN: ";
				string ssn;
				cin >> ssn;
				cin.clear();
				cin.ignore(32768, '\n');
				sm.displayStudent(ssn);
			}
			catch (const char *msg) {
				clog << msg << endl;
			}
		}
	} while (input != 'q');

	system("pause");
	return 0;
}