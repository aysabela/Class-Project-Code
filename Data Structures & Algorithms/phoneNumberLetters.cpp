#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

//The international standard letter / number mapping for telephones is shown in the picture.
//The following function returns a number given an uppercase letter.Fill in the blank to complete the function
//Restrictions:
//• The function's body is 1 line,
//• No conditional operators / functions including ternary
//operator
//• Must correctly translate all the letters
//Write a test program that prompts the user to enter a phone
//number as a string.The input number may contain letters.The
//program translates a letter(uppercase or lowercase) to a digit and
//leaves all other characters intact.Here is a sample run of the
//program :

int getNumber(char uppercaseLetter) {
	return 2 * (uppercaseLetter == 'a' || uppercaseLetter == 'b' || uppercaseLetter == 'c') + 3 * (uppercaseLetter == 'd' || uppercaseLetter == 'e' || uppercaseLetter == 'f') + 4 * (uppercaseLetter == 'g' || uppercaseLetter == 'h' || uppercaseLetter == 'i') +
		5 * (uppercaseLetter == 'j' || uppercaseLetter == 'k' || uppercaseLetter == 'l') + 6 * (uppercaseLetter == 'm' || uppercaseLetter == 'n' || uppercaseLetter == 'o') + 7 * (uppercaseLetter == 'p' || uppercaseLetter == 'q' || uppercaseLetter == 'r' || uppercaseLetter == 's') +
		8 * (uppercaseLetter == 't' || uppercaseLetter == 'u' || uppercaseLetter == 'v') + 9 * (uppercaseLetter == 'w' || uppercaseLetter == 'x' || uppercaseLetter == 'y' || uppercaseLetter == 'z');

}

int main() {

	string mystr, num;
	int a, b;

	cout << "Enter a string: ";
	getline(cin, mystr);
	stringstream(mystr) >> a >> b >> num;

	num = num.substr(1, 7);
	cout << a << b << "-";

	for (int i = 0; i < num.size(); i++) {
		cout << getNumber(num.at(i));
	}


	system("pause");
}