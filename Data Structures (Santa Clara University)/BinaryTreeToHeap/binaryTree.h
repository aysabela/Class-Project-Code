#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>    // Provides NULL and size_t

namespace main_savitch_10
{
    template <class Item>
    class binary_tree_node
    {
    public:
        // TYPEDEF
        typedef Item value_type;
        // CONSTRUCTOR
        binary_tree_node(
            const Item& init_data = Item(),
            binary_tree_node* init_left = NULL,
            binary_tree_node* init_right = NULL
        )
        {
            data_field = init_data;
            left_field = init_left;
            right_field = init_right;
        }
        // MODIFICATION MEMBER FUNCTIONS
        Item& data() { return data_field; }
        binary_tree_node* left() { return left_field; }
        binary_tree_node* right() { return right_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(binary_tree_node* new_left) { left_field = new_left; }
        void set_right(binary_tree_node* new_right) { right_field = new_right; }
        // CONST MEMBER FUNCTIONS
        const Item& data() const { return data_field; }
        const binary_tree_node* left() const { return left_field; }
        const binary_tree_node* right() const { return right_field; }
        bool is_leaf() const
        {
            return (left_field == NULL) && (right_field == NULL);
        }
    private:
        Item data_field;
        binary_tree_node* left_field;
        binary_tree_node* right_field;
    };

    template <class BTNode, class Item, class SizeType>
    void treeToArray(BTNode* node_ptr, Item tempArr, SizeType& count) {
        if (node_ptr != NULL) {
            treeToArray(node_ptr->left(), tempArr, count);
            treeToArray(node_ptr->right(), tempArr, count);

            tempArr[count] = node_ptr->data();
            count++;
        }
    }

    template <class Item>
    size_t tree_size(const binary_tree_node<Item>* node_ptr) {
        if (node_ptr == NULL) {
            return 0;
        }
        else
            return
            1 + tree_size(node_ptr->left()) + tree_size(node_ptr->right());
    }

    binary_tree_node<int>* insert(int arr[], binary_tree_node<int>* node, int i, int array_size)
    {

        if (i < array_size) {
            binary_tree_node<int>* temp = new binary_tree_node<int>(arr[i]);
            node = temp;

            node->set_left(insert(arr, node->left(), 2 * i + 1, array_size));

            node->set_right(insert(arr, node->right(), 2 * i + 2, array_size));
        }

        return node;
    }

}

#endif
