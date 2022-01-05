#ifndef BSTNODEEC_HPP
#define BSTNODEEC_HPP
#include <iostream>
#include <iomanip>
#include <string>

/** Starter code for PA1, CSE 100 2016
 * Authors: Christine Alvarado, based on code by Paul Kube
 * ADD YOUR NAME AS AN AUTHOR HERE
 */

template<typename Data>
class BSTNodeEC {

public:

  BSTNodeEC<Data>* left;
  BSTNodeEC<Data>* right;
  BSTNodeEC<Data>* parent;
  Data const data;   // the const Data in this node.
  unsigned int height;

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNodeEC(const Data & d);

};


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

template <typename Data>
BSTNodeEC<Data>::BSTNodeEC(const Data & d) : left(0), right(0), parent(0), data(d), height(0) {}


/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNodeEC<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
