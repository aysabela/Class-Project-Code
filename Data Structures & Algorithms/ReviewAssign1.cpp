/***************************************************************
Problem:      Review Assignment #1 - Chars, Strings, Files
Question:     Converting a letter, number, and symbol into hex,
decimal, octal, and binary, then printing to the screen
and to a file

Name:  Alyssa Ysabela Flores
ID:    1662110
Date:  09/09/2018

Status:  complete
****************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bitset>


using namespace std;

void bitSet(char a) {
	string convert = (bitset<32>(a)).to_string();
	cout << convert.erase(0, convert.find_first_of('1')) << " ";
}

void bitSet(int a) {
	string convert = (bitset<32>(a)).to_string();
	cout << convert.erase(0, convert.find_first_not_of('10')) << " ";
}

void printline(ostream & line, string name, char letter, char symbol, int num) {
	line << name << " - Character Formatting" << endl;
	line << "letter = " << letter << "  " << "number = " << num << "  " << "symbol = " << symbol << endl;
	line << "------------------------------------------------" << endl;
	line << "Decimal " << static_cast<int>(letter) << " " << num << " " << static_cast<int>(symbol) << endl;
	line << "Hex " << hex << showbase << static_cast<int>(letter) << " " << static_cast<int>(num) << " " << static_cast<int>(symbol) << endl;
	line << "Octal " << oct << showbase << static_cast<int>(letter) << " " << static_cast<int>(num) << " " << static_cast<int>(symbol) << endl;
	line << "Binary ";
	bitSet(letter);
	bitSet(num);
	bitSet(symbol);

}

int main() {

	char symbol;
	char letter;
	int num;
	string name;
	string fileName;
	string mystr;


	cout << "What is your name? ";
	getline(cin, name);
	cout << endl << "OK " << name << ", please input a letter, a number, and a symbol separated by a space: ";

	getline(cin, mystr);
	stringstream(mystr) >> letter >> num >> symbol;

	cout << endl << "Please input a file name: ";
	getline(cin, fileName);


	cout << endl << "Output succeded." << endl << endl;

	ofstream myFile(fileName);
	printline(myFile, name, letter, symbol, num);
	printline(cout, name, letter, symbol, num);


	system("pause");
}