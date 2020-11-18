//3

#include <iostream>
#include <string>

using namespace std;

void palindrome(string s1) {
	(string(s1.rbegin(), s1.rend()) == s1) ? cout << "YES IT IS YAY" : cout << "no haha";
}

int main() {

	string mystr;

	cout << "Enter a string: ";
	getline(cin, mystr);

	palindrome(mystr);

	system("pause");
}