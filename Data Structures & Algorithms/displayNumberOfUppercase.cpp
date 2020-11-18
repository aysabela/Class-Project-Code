//#2

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

//Write a program that prompts the user to enter a string and displays the number of the uppercase letters in
//the string.Here is a sample run :

//Restriction: only one loop and No conditions allowed(if / switch / ? : )

using namespace std;

int main() {

	string mystr;
	int num = 0;

	cout << "Enter a string: ";
	getline(cin, mystr);


	for (int i = 0; i < mystr.size(); i++) {
		num += (isupper(mystr.at(i)));
	}


	cout << "The number of uppercase letters is " << num << endl;


	system("pause");
}