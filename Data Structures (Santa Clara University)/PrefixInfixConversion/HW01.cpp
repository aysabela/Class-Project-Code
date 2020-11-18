/*
* Name: Alyssa Ysabela Flores
*
* Class: Data Structures CSCI61-MWF 20116
*
* Last Modified: 10/01/2020
*
* Description: This is my infix to prefix and vice versa code. It mostly utilizes the postfix pseudocode listed in the book
* for the prefix to infix function. It can handle unbalanced parentheses as well as unbalanced operators & numbers.
* 
* 3+X/2+(7-3)
*/

#include<iostream>
#include<stack>
#include<locale>
#include<algorithm>
using namespace std;

void Menu();
int Precedence(char);
string InfixToPostfix(string);
string InfixToPrefix(string);
string PrefixToInfix(string);


//Acts as the menu presented to the user and called back to when errors are encountered
void Menu() {
	string choice = "";

	do {
		cout << "Enter a proper mathematical expression (you can do either infix or prefix) or Q to quit: ";
		cin >> choice;

		if (choice == "Q" || choice == "q") {

			cout << "Thank you, goodbye." << endl;
		}
		else {
			if (isalnum(choice.at(0)) || choice.at(0) == '(' || choice.at(0) == ')') {
				cout << "Original: " << choice << " Infix to Prefix: " << InfixToPrefix(choice) << endl;
				choice.clear();
			}
			else {
				cout << "Original: " << choice << " Prefix to Infix: " << PrefixToInfix(choice) << endl;
				choice.clear();
			}
		}
	} while (choice != "Q" && choice != "q");
}


//Acts as the determiner of precedence for the operators: the higher the precedence, the higher the number
int Precedence(char op) {
	int precedenceVal = 0;

	if (op == '+' || op == '-') {
		precedenceVal = 1;

	}
	else if (op == '*' || op == '/') {
		precedenceVal = 2;

	}
	else if (op == '^') {
		precedenceVal = 3;
	}

	return precedenceVal;
}


//Does infix to postfix conversion
string InfixToPostfix(string input) {

	string postfix = "";
	stack<char> holder;

	for (int i = 0; i <= input.size()-1; i++) {

		if (input.at(i) == '(') {
			holder.push(input.at(i));

		}
		else if (isalnum(input.at(i))) {
			postfix += input.at(i);

		}
		else if (input.at(i) == ')') {

			while (holder.top() != '(' || holder.empty()) {
				try { //Does a check to see if the operands are only one more than the operators, otherwise throw an error. Since
					  //postfix won't be called at all due to the other functions handling the error, these aren't needed but I added
					  //them anyway to make the function fully proper
					if (holder.empty()) {
						throw invalid_argument("Unbalanced parentheses."); 
					}
					else {
						postfix += holder.top();
						holder.pop();
					}
				}
				catch (invalid_argument& e) {
					cout << "Unbalanced parentheses." << endl;
					Menu();
				}
				}
				holder.pop();
		}
		else {
			while (!holder.empty() && holder.top() != '(' && Precedence(holder.top()) > Precedence(input.at(i))) {
				postfix += holder.top();
				holder.pop();

			}
			holder.push(input.at(i));
		}
	}

	while (!holder.empty()) {
		try {
			if (holder.top() == '(') {
				throw invalid_argument("Unbalanced parentheses.");
			}
			else {
				postfix += holder.top();
				holder.pop();
			}
		}
		catch (invalid_argument& e) {
			cout << "Unbalanced parentheses." << endl;
			Menu();
		}
	}

return postfix;

}


//Does infix to prefix conversion by first reversing the input, running it through the InfixToPostfix function, then
//reversing it again to get the prefix equivalent
string InfixToPrefix(string input) {
	string temp = "";
	int parenCountLeft = 0;
	int parenCountRight = 0;
	int operatorCount = 0;
	int operandCount = 0;

	reverse(input.begin(), input.end());

	for (int i = 0; i <= input.size() - 1; i++) {
		if (isalnum(input.at(i))) {
			operandCount++;
		}
		else {
			operatorCount++;
		}
	}

	try {  //Does a check to see if the operands are only one more than the operators, otherwise throw an error
		if (operatorCount == (operandCount - 1)) {
			for (int i = 0; i <= input.size() - 1; i++) {
				if (input.at(i) == '(') {
					input.at(i) = ')';
					parenCountLeft++;
				}
				else if (input.at(i) == ')') {
					input.at(i) = '(';
					parenCountRight++;
				}
			}
			try {  //Does a check to see if the parentheses are equal, otherwise throw an error
				if (parenCountLeft != parenCountRight) {
					throw invalid_argument("Unbalanced parentheses.");
				}
				else {
					input = InfixToPostfix(input);
					reverse(input.begin(), input.end());
					return input;
				}
			}
			catch (invalid_argument& e) {
				cout << "Unbalanced parentheses. 3" << endl;
				Menu();
			}
		}
		else {
			throw invalid_argument("Unbalanced parentheses.");
		}
	}
	catch (invalid_argument& e) {
		cout << "Unbalanced operators." << endl;
		Menu();
	}
}


//Does prefix to infix conversion
string PrefixToInfix(string input) {
	string infix = "";
	string temp = "";
	string next = "";
	int operatorCount = 0;
	int operandCount = 0;
	int parenCountLeft = 0;
	int parenCountRight = 0;

	stack<string> holder;

	reverse(input.begin(), input.end());

	for (int i = 0; i <= input.size() - 1; i++) {
		if (isalnum(input.at(i))) {
			operandCount++;
		}
		else {
			operatorCount++;
		}
	}

	try { //Does a check to see if the operands are only one more than the operators, otherwise throw an error
		if (operatorCount == (operandCount - 1)) {
			for (int i = 0; i <= input.size() - 1; i++) {

				if (!isalnum(input.at(i))) {
					string temp1 = holder.top();
					holder.pop();
					string temp2 = holder.top();
					holder.pop();

					temp = "(" + temp1 + input.at(i) + temp2 + ")";
					holder.push(temp);
				}
				else {
					holder.push(string(1, input.at(i)));
				}
			}

			infix = holder.top();
		}
		else {
			throw invalid_argument("Unbalanced operators.");
		}
	}
	catch (invalid_argument& e) {
		cout << "Unbalanced operators." << endl;
		Menu();
	}
	return infix;
}


int main() {
	
	Menu();
	
	return 0;
}