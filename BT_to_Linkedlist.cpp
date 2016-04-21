//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 10, Project 8
//  3/13/2016
//  Binary tree to Linked list

#include "bt_class.h"
#include "list.h"
#include <iostream>
using namespace std;

//turn binary search tree to priority queue
template <typename T>
List<T>& turnToLinkedList(binary_tree<T> &bt){
    List<T> *list = new List<T>();
    bt.shift_to_root();
    loop(bt, list);
    return *list;
}

//inorder traverse and push into queue to make priority queue
template <typename T>
void loop(binary_tree<T> &bt, List<T> *list){
    if(bt.has_left_child()){
        bt.shift_left();
        loop(bt, list);
    }
    list->end();
    list->attach(bt.retrieve());
    if(bt.has_right_child()){
        bt.shift_right();
        loop(bt, list);
    }
    bt.shift_up();
}

int main(){
    binary_tree<int> bt;

    //make binary search tree
    bt.create_first_node(15);
    bt.add_left(3);
    bt.add_right(20);
    bt.shift_left();
    bt.add_left(1);
    bt.add_right(14);
    bt.shift_up();
    bt.shift_right();
    bt.add_left(17);
    bt.add_right(21);

    List<int> list = turnToLinkedList(bt);
    list.start();
    for(int i=0; i < list.size(); i++){
        cout << list.current() << " ";
        list.advance();
    }
    return 1;
}
