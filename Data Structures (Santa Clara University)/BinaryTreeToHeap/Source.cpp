#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <iomanip>
#include "binaryTree.h"
using namespace main_savitch_10;
using namespace std;

binary_tree_node<int>* tree_fill();
void heapification(int*, int);
void printTree(binary_tree_node<int>*, int);

int main() {

	int count = 0;
	int* tempArr;
	binary_tree_node<int>* root_ptr = tree_fill();
	tempArr = new int[tree_size(root_ptr)];

	treeToArray(root_ptr, tempArr, count);
	heapification(tempArr, count);
	
	return 0;
}

binary_tree_node<int>* tree_fill() {

	binary_tree_node<int>* root_ptr(NULL);
	binary_tree_node<int>* child_ptr(NULL);

	const int n1(7);
	const int n2(6);
	const int n3(9);
	const int n4(8);
	const int n5(4);
	const int n6(5);

	root_ptr = new binary_tree_node<int>(n1);

	child_ptr = new binary_tree_node<int>(n2);
	child_ptr->set_left(new binary_tree_node<int>(n3));
	child_ptr->set_right(new binary_tree_node<int>(n4));
	root_ptr->set_left(child_ptr);

	child_ptr = new binary_tree_node<int>(n5);
	child_ptr->set_left(new binary_tree_node<int>(n6));
	root_ptr->set_right(child_ptr);

	return root_ptr;

}

void heapification(int* binaryTree, int binary_tree_size) {
	sort(binaryTree, binaryTree + binary_tree_size);

	binary_tree_node<int>* root_ptr(NULL);

	root_ptr = new binary_tree_node<int>(binaryTree[0]);
	printTree(insert(binaryTree, root_ptr, 0, binary_tree_size), binary_tree_size);
}


void printTree(binary_tree_node<int>* node_ptr, int depth) {
	
	if (node_ptr != NULL) {
		printTree(node_ptr->right(), depth + 1);
		cout << setw(5*depth) << "";
		cout << node_ptr->data() << endl;
		printTree(node_ptr->left(), depth + 1);
	}
}



