// lab14
// Vincent Gabb
//
// 11/28/2020

#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree() 
  : size(0), root(nullptr)
    {}

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    this->clear();
  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return this->size;
  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
    this->clear(this->root);
    this->size = 0;
    this->root = nullptr;
  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
    return insert(data, root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    return printInOrder(this->root);
  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *leftChild;
    Node *rightChild;

    Node(T newData) : data(newData), leftChild(nullptr), rightChild(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  void clear(Node *&troot) {
    if (troot != nullptr) {
      clear (troot->leftChild);
      clear(troot->rightChild);
      delete troot;
      troot = nullptr;
      size--;
    }
  }

  bool insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      troot = new Node(newData);
      size++;
      return true;
    } else if (newData < troot->data) {
      return insert(newData, troot->leftChild);
    } else if (newData > troot->data) {
      return insert(newData, troot->rightChild);
    } else {
      return false;
    }
  }

  void printInOrder(Node *troot) {
    if (troot != nullptr) {
      printInOrder(troot->leftChild);
      cout << troot->data << endl;
      printInOrder(troot->rightChild);
    }
  }
};