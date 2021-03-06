//
//Yuya Oguchi Chapter 10 Project 8
//
#pragma once
#include <cstdlib>    // Provides NULL and size_t
#include <cassert>    // Provides assert
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

template <class Item>
class binary_tree_node
{
    public:
        // TYPEDEF
        typedef Item value_type;
        // CONSTRUCTOR
        binary_tree_node(
            const Item& init_data = Item( ),
            binary_tree_node* init_left = NULL,
            binary_tree_node* init_right = NULL,
            binary_tree_node* init_parent = NULL
        )
        {
          	data_field = init_data;
            left_field = init_left;
            right_field = init_right;
            parent_field = init_parent;
        }
        // MODIFICATION MEMBER FUNCTIONS
        Item& data( ) { return data_field; }
        binary_tree_node* left( ) { return left_field; }
        binary_tree_node* right( ) { return right_field; }
        binary_tree_node* parent( ) { return parent_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(binary_tree_node* new_left) { left_field = new_left; }
        void set_right(binary_tree_node* new_right) { right_field = new_right; }
        void set_parent(binary_tree_node* new_parent) { parent_field = new_parent; }
        // CONST MEMBER FUNCTIONS
        const Item& data( ) const { return data_field; }
        const binary_tree_node* left( ) const { return left_field; }
        const binary_tree_node* right( ) const { return right_field; }
        const binary_tree_node* parent( ) const { return parent_field; }
        bool is_leaf( ) const
            { return (left_field == NULL) && (right_field == NULL); }
    private:
        Item data_field;
        binary_tree_node *left_field;
        binary_tree_node *right_field;
        binary_tree_node *parent_field;
};

// NON-MEMBER FUNCTIONS for the binary_tree_node<Item>:
template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr);

template <class Item, class SizeType>
void print(binary_tree_node<Item>* node_ptr, SizeType depth);

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr);

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr, binary_tree_node<Item>* parent_ptr=NULL);

template <class Item>
std::size_t tree_size(const binary_tree_node<Item>* node_ptr);

template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr)
// Library facilities used: cstdlib
{
    if (node_ptr != NULL)
    {
        inorder(f, node_ptr->left( ));
        f( node_ptr->data( ) );
        inorder(f, node_ptr->right( ));
    }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr)
// Library facilities used: cstdlib
{
    if (node_ptr != NULL)
    {
        postorder(f, node_ptr->left( ));
        postorder(f, node_ptr->right( ));
        f(node_ptr->data( ));
    }
}

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr)
// Library facilities used: cstdlib
{
    if (node_ptr != NULL)
    {
        f( node_ptr->data( ) );
        preorder(f, node_ptr->left( ));
        preorder(f, node_ptr->right( ));
    }
}

template <class Item, class SizeType>
void print(binary_tree_node<Item>* node_ptr, SizeType depth)
// Library facilities used: iomanip, iostream, stdlib
{
    if (node_ptr != NULL)
    {
        print(node_ptr->right( ), depth+1);
        std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
        std::cout << node_ptr->data( ) << "(" << node_ptr->parent() << ")" << std::endl;
        print(node_ptr->left( ),  depth+1);
    }
}

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr)
// Library facilities used: cstdlib
{
    binary_tree_node<Item>* child;
    if (root_ptr != NULL)
    {
        child = root_ptr->left( );
        tree_clear( child );
        child = root_ptr->right( );
        tree_clear( child );
        delete root_ptr;
        root_ptr = NULL;
    }
}

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr, binary_tree_node<Item>* parent_ptr)
// Library facilities used: cstdlib
{
    binary_tree_node<Item> *l_ptr;
    binary_tree_node<Item> *r_ptr;

    if (root_ptr == NULL)
        return NULL;
    else
    {
        binary_tree_node<Item> *node = new binary_tree_node<Item>(root_ptr->data());
        l_ptr = tree_copy( root_ptr->left( ), node );
        r_ptr = tree_copy( root_ptr->right( ), node );
        node->set_left(l_ptr);
        node->set_right(r_ptr);
        node->set_parent(parent_ptr);
        return node;
    }
}

template <class Item>
size_t tree_size(const binary_tree_node<Item>* node_ptr)
// Library facilities used: cstdlib
{
    if (node_ptr == NULL)
        return 0;
    else
        return
    1 + tree_size(node_ptr->left( )) + tree_size(node_ptr->right( ));
}
