
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
 if(find(item) == true) {
  return false;
 }
 else {
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }
  else {
    BSTNodeInt* curr = root;
    while (curr != NULL) {
      if (item < curr->data) {
        if(curr->left == NULL) { // same as (!curr->left) ?
          curr->left = new BSTNodeInt(item);
          curr->left->parent = curr;
          ++isize;
          return true;
        }
        else {
          curr = curr -> left;
        }
      }
      else {
        if(curr->right == NULL) {
          curr->right = new BSTNodeInt(item);
          curr->right->parent = curr;
          ++isize;
          return true;
        }
        else {
          curr = curr->right;
        }
      }

    } // end while loop
    return false;
  }
 }
}

/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if(item == curr->data) {
      return true; // Found
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      curr = curr->right;
    }
  }
  return false; // not found
}


/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const
{
  return isize;
}


/** Return the height of the BST.
    Height of tree with just root node is 0
    height of an empty tree is -1
 */
int BSTInt::height() const
{
  // TODO
 if(empty() == true) {
  return -1;
 }
 
 if(isize == 1) {
  return 0;
 }
 
 return depth(root);
 
}

int BSTInt::depth(BSTNodeInt* curr) const
{
  if(curr == NULL) {
   return 0;
  }
  else {
   int leftHeight = depth(curr->left);
   int rightHeight = depth(curr->right); 
   
   if(curr == root) {
    if(leftHeight > rightHeight) {
     return leftHeight;
    }
    else {
     return rightHeight;
    }
   }
   
   if(rightHeight > leftHeight){
    return rightHeight + 1; 
   }
  
   else {
    return (leftHeight + 1); 
   }
   
}
}


/** Return true if the BST is empty, else false.
 */
bool BSTInt::empty() const
{
  if(root == NULL) {
   return true; 
  }
 else {
  return false;
 }
}


/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  
 if(n == NULL) {
  return; 
 }
 deleteAll(n->left);
 deleteAll(n->right);
 delete(n); 
}


