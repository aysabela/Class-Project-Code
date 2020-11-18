#include <iostream>   
#include <string>
#include <locale>
#include <stack>
#include "bintree.h"
using namespace std;
using namespace main_savitch_10;


void build(binary_tree_node<string>*& leaf_ptr, const string);


int main()
{
	
    binary_tree_node<string>* prefix_root_ptr(NULL);

	string choice = "";
	int depth = 10;

	do {
		cout << "Enter a proper prefix expression or Q to quit: ";
		cin >> choice;

		if (choice == "Q" || choice == "q") {

			cout << "Thank you, goodbye." << endl;
		}
		else {
			if (!isalnum(choice.at(0))) {
				build(prefix_root_ptr, choice);
				cout << "Displaying prefix expression into tree: ";
				print(prefix_root_ptr, depth);
				choice.clear();
			}
			else {
				cout << "Please enter a prefix expression." << endl;
				choice.clear();
			}
		}
	} while (choice != "Q" && choice != "q" && !isalnum(choice.at(0)));


    return 0;
}


void build(binary_tree_node<string>*& root_ptr, const string data)
{

	int i = 0;
	binary_tree_node<string>* current_ptr;
	binary_tree_node<string>* child_ptr;

	stack <binary_tree_node<string>*> holder;
	current_ptr = root_ptr;

	do {
		if (root_ptr == NULL) {

			root_ptr = new binary_tree_node<string>(string(1, data.at(i)));

			current_ptr = root_ptr;

			if (!isalnum(data.at(i))) {
				holder.push(current_ptr);
				i++;
			}
		}
		else if (current_ptr->is_leaf()) {
			child_ptr = (new binary_tree_node<string>(string(1, data.at(i))));
			current_ptr->set_left(child_ptr);

			if (!isalnum(data.at(i))) {
				current_ptr->left();
				holder.push(current_ptr);
				i++;
			}
		}
		else {
			child_ptr = (new binary_tree_node<string>(string(1, data.at(i))));
			current_ptr->set_right(child_ptr);

			if (!isalnum(data.at(i))) {
				current_ptr->right();
				holder.push(current_ptr);
				i++;
			}

			else while (!((current_ptr->right())->is_leaf())) {
				current_ptr = holder.top();
				holder.pop();
			}
		}
	} while (i != data.size());
}

