#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//#4

string swapCase(const string& s) {

	string s2;

	for (int i = 0; i < s.size(); i++) {

		isupper(s.at(i)) ? s2.push_back(toupper(s.at(i))) : s2.push_back(tolower(s.at(i)));
		//s2.at(i) = ((isupper(s.at(i)) ? toupper(s.at(i)) : tolower(s.at(i))));

	}

	return s2;

}


int main() {

	string mystr;

	cout << "enter a string: ";
	getline(cin, mystr);
	cout << swapCase(mystr) << endl;

	system("pause");
}