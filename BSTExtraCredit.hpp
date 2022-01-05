/* Algorithm Design:

We have created a self-balancing binary search tree with the height property
that the difference between nodes with the highest height and the lowest height
is no more than 1.

We create a private member called balance factor. This is defined as the left
subtree height minus the right subtree height, which should be -1, 0, or 1 in a
balanced tree.

In order to keep the tree balanced, we will have private helper methods that
rotate nodes. When we insert a node into this self-balancing tree, we need to
check to see if the tree is still balanced. If it is not balanced, we need to
perform a rotation, which is a rearrangement of the BST that maintains the BST
ordering property while rebalancing the tree according to the height requirment.

We perform the rotate method at a node.

We will have the following methods:
- UpdateHeight: this method uses an algorithm to update a node's height
  value by taking the greater of the two child subtree heights and adding 1

  It does this by taking in a node as a paramter and intializing a local variable
  called "leftHeight" to -1.
  It then checks if the input node's left child exists. If the input node's left
  child exists, then it update's the leftHeight to the left child of the input node's
  height.
  It then initializes the rightHeight local variable to -1 regardless.
  It then similarly checks to see if the right child of the node exists. If it
  exists, then it updates the rightHeight to the right child of the input node's
  height.
  Finally, it set's the input node's height to the maximum of the leftHeight and
  right height + 1. This essentially updates the tree height, as desired.

- SetChild: this method uses an algorithm to set a node as the parent's left
  or right child, updates teh child's parent pointer, and updates the parent
  node's height

  It does this by taking in three parameters: parent, whichChild, child. whichChild
  is a string that is either left or right
  If whichChild does not equal left and whichChild does not equal right, we return
  false and setChild did not occur.
  If whichChild = left, we update the parent's left child to the input child.
  Otherwise, we update the parent's right child to the input child.
  Next, we check if teh input child exists. If it exists, we update the input
  child's parent to the input parent.
  We then call UpdateHeight using the input parent as the parameter
  Finally, we return true to indicate that setChild executed.

- ReplaceChild: this method uses an algorithm to replace a node's existing child
  pointers with a new value, utilizing the SetChild to perform the replacement

  It does this by taking in 3 paramters: parent, currentChild, and newChild.
  It first checks if the parent's left child = the currentChild. If this is the
  case, it calls SetChild using input parent, "left", and newChild as parameters
  Else, if the parent' sright child = current child, it calls SetChild using
  input parent, "right", and newChild as parameters.
  Otherwise, it retursn false to indicate the replacement did not occur

- TreeGetBalance: this method uses an algorithm to calculate the node's balance
  factor by subtracitng the right subtree height from the left subtree height

  It does this by taking in one parameter: node
  It then initializes leftHeight = -1.
  If the input node's left child is not NULL, then it sets leftHeight to the
  input node's left child's height.
  It then initializes rightHeight = -1.
  If the input node's right child is not NULL, then it sets rightHeight to the
  input node's right child's height.
  It then returns the leftHeight - rightHeight.

- RightRotate: this method uses an algorithm to rotate the subtrees of a particular
  node.

  It does this by taking in a node as a parameter, which must have a left
  child.
  It then creates a local variable called leftRightChild, which is defined as
  the right child of the input node's left child.
  If the node taken in as a parameter has a parent, we call ReplaceChild
  using the node's parent, the node, and the node's left child as parameters.
  Otherwise, if the node has no parent, we set the tree's root to this node's
  left child and the tree's root's parent to NULL.
  We then call SetChild using the input node's left child, "right", and the node
  itself as parameters.
  We call SetChild again by this time using the node, "left", and leftRightChild
  as parameters.

- LeftRotate: this method uses an algorithm to rotate the subtrees of a particular
  node in the opposite orientation as RightRotate.

    It does this by taking in a node as a parameter, which must have a right
    child.
    It then creates a local variable called rightLeftChild, which is defined as
    the left child of the input node's right child.
    If the node taken in as a parameter has a parent, we call ReplaceChild
    using the node's parent, the node, and the node's right child as parameters.
    Otherwise, if the node has no parent, we set the tree's root to this node's
    right child and the tree's root's parent to NULL.
    We then call SetChild using the input node's right child, "left", and the node
    itself as parameters.
    We call SetChild again by this time using the node, "right", and rightLeftChild
    as parameters.

- Rebalance: this algorithm is called if the node in the tree has a balance factor
  of 2 or -2. This would only occur after insertion or removal. In this case, the
  tree must be rebalanced via rotations. This algorithm updates teh height value
  at a node, computes the balance factor, adn rotates if the factor is 2 or -2.

  It does this by taking in one parameter: node
  It then calls the updateHeight method on the input node.
  If the GetBalance(node) = -2, we check if the get the GetBalance(node's right child)
  is -1. In this case, we perform a double rotation calling RotateRight on the
  input node's right child.
  Otherwise, we perform rotateLeft on the node.
  Else if GetBalance(node) = 2, we check we check if the get the GetBalance(node's left child)
  is -1. In this case, we perform a double rotation calling RotateLeft on the
  input node's left child.
  Otherwise, we perform rotateRight on the node.
  We return the node to indicate the rebalance was performed.

- Insert: this method involves searching for the insert location, inserting the
  new node, updating balance factors, adn rebalancing.

  It does this by inserting with the standard BST insertion algorithm After inserting,
  all teh node's ancestors up to the root are rebalanced. A node is rebalanced
  by first ocmputing the node's balance factor, and then performing rotations
  if the balance factor is greater than 1 or less than -1.

*/


#ifndef BSTEXTRACREDIT_HPP
#define BSTEXTRACREDIT_HPP
#include "BSTNodeEC.hpp"
#include <iostream>
#include <string>

using namespace std;

template<typename Data>
class BSTExtraCredit {

public:

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BSTExtraCredit() : root(nullptr), isize(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BSTExtraCredit();

  // New methods:
  void AVLTreeUpdateHeight(BSTNodeEC<Data>* node);

  bool AVLTreeSetChild(BSTNodeEC<Data>* parent, string whichChild, BSTNodeEC<Data>* child);

  bool AVLTreeReplaceChild(BSTNodeEC<Data>* parent, BSTNodeEC<Data>* currentChild, BSTNodeEC<Data>* newChild);

  int AVLTreeGetBalance(BSTNodeEC<Data>* node);

  BSTNodeEC<Data>* AVLTreeRotateRight(BSTNodeEC<Data>* node);

  BSTNodeEC<Data>* AVLTreeRotateLeft(BSTNodeEC<Data>* node);

  BSTNodeEC<Data>* AVLTreeRebalance(BSTNodeEC<Data>* node);

  void insert(const Data& item);



  /** Return the number of items currently in the BST.
   */
  unsigned int size() const;

  /** Return the height of the BST.
      height of a tree starts with root at height 0
	  height of an empty tree is -1
   */
   int height() const;

  /** Helper method for height
   */
   int depth(BSTNodeEC<Data>* curr) const;


  /** Return true if the BST is empty, else false.
   */
  bool empty() const;



private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNodeEC<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNodeEC<Data>* n);
 };


// ********** Function definitions ****************

// Functions for AVL

template <typename Data>
void BSTExtraCredit<Data>::AVLTreeUpdateHeight(BSTNodeEC<Data>* node) {
   int leftHeight = -1;
   if (node->left != NULL) {
     leftHeight = node->left->height;
   }
   int rightHeight = -1;
   if (node->right != NULL) {
     rightHeight = node->right->height;
   }
   int max = 0;
   if(leftHeight > rightHeight) {
     max = leftHeight;
   }
   else {
     max = rightHeight;
   }
   node->height = max + 1;
}

template <typename Data>
bool BSTExtraCredit<Data>::AVLTreeSetChild(BSTNodeEC<Data>* parent, string whichChild, BSTNodeEC<Data>* child) {
   if (whichChild != "left" && whichChild != "right") {
     return false;
   }
   if (whichChild == "left") {
     parent->left = child;
   }
   else {
     parent->right = child;
   }
   if (child != NULL) {
     child->parent = parent;
   }
   AVLTreeUpdateHeight(parent);
   return true;
}

template <typename Data>
bool BSTExtraCredit<Data>::AVLTreeReplaceChild(BSTNodeEC<Data>* parent, BSTNodeEC<Data>* currentChild, BSTNodeEC<Data>* newChild) {
   if (parent->left == currentChild) {
     return AVLTreeSetChild(parent, "left", newChild);
   }
   else if (parent->right == currentChild) {
     return AVLTreeSetChild(parent, "right", newChild);
   }
   return false;
}

template <typename Data>
int BSTExtraCredit<Data>::AVLTreeGetBalance(BSTNodeEC<Data>* node) {
   int leftHeight = -1;
   if (node->left != NULL) {
     leftHeight = node->left->height;
   }
   int rightHeight = -1;
   if (node->right != NULL) {
     rightHeight = node->right->height;
   }
   return leftHeight - rightHeight;
}

template <typename Data>
BSTNodeEC<Data>* BSTExtraCredit<Data>::AVLTreeRotateRight(BSTNodeEC<Data>* node) {
   BSTNodeEC<Data>* leftRightChild = node->left->right;
   if (node->parent != NULL) {
     AVLTreeReplaceChild(node->parent, node, node->left);
   }
   else { // node is root
      root = node->left;
      root->parent = NULL;
   }
   AVLTreeSetChild(node->left, "right", node);
   AVLTreeSetChild(node, "left", leftRightChild);
   return node;
}

template <typename Data>
BSTNodeEC<Data>* BSTExtraCredit<Data>::AVLTreeRotateLeft(BSTNodeEC<Data>* node) {
   BSTNodeEC<Data>* rightLeftChild = node->right->left;
   if (node->parent != NULL) {
     AVLTreeReplaceChild(node->parent, node, node->right);
   }
   else { // node is root
      root = node->right;
      root->parent = NULL;
   }
   AVLTreeSetChild(node->left, "right", node);
   AVLTreeSetChild(node, "right", rightLeftChild);
   return node;
}

template <typename Data>
BSTNodeEC<Data>* BSTExtraCredit<Data>::AVLTreeRebalance(BSTNodeEC<Data>* node) {
   AVLTreeUpdateHeight(node);
   if (AVLTreeGetBalance(node) == -2) {
      if (AVLTreeGetBalance(node->right) == 1) {
         // Double rotation case.
         AVLTreeRotateRight(node->right);
      }
      return AVLTreeRotateLeft(node);
   }
   else if (AVLTreeGetBalance(node) == 2) {
      if (AVLTreeGetBalance(node->left) == -1) {
         // Double rotation case.
         AVLTreeRotateLeft(node->left);
      }
      return AVLTreeRotateRight(node);
   }
   return node;
}

template <typename Data>
void BSTExtraCredit<Data>::insert(const Data& item) {
  BSTNodeEC<Data>* node = new BSTNodeEC<Data>(item);
   if (root == NULL) {
      root = node;
      node->parent = NULL;
      isize ++;
      return;
   }

   BSTNodeEC<Data>* cur = root;
   while (cur != NULL) {
      if (node->data < cur->data) {
         if (cur->left == NULL) {
            cur->left = node;
            node->parent = cur;
            cur = NULL;
         }
         else {
           cur = cur->left;
         }
      }
      else {
         if (cur->right == NULL) {
            cur->right = node;
            node->parent = cur;
            cur = NULL;
         }
         else {
           cur = cur->right;
         }
      }
   }

   node = node->parent;
   node->height = depth(node);
   isize ++;
   while (node != NULL) {
      AVLTreeRebalance(node);
      node = node->parent;
   }
}

/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BSTExtraCredit<Data>::~BSTExtraCredit() {
  deleteAll(root);
}


/** Return the number of items currently in the BST.
 */
template <typename Data>
unsigned int BSTExtraCredit<Data>::size() const
{
  return isize;
}

/** Return the height of the BST Node.
 */
template <typename Data>
int BSTExtraCredit<Data>::height() const
{

  if(empty() == true) {
   return -1;
  }

  if(isize == 1) {
   return 0;
  }

  return depth(root);
}

/** Helper method to height.
 */
template <typename Data>
int BSTExtraCredit<Data>::depth(BSTNodeEC<Data>* curr) const
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
template <typename Data>
bool BSTExtraCredit<Data>::empty() const
{
  if(root == NULL) {
    return true;
  }
  else {
    return false;
  }
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BSTExtraCredit<Data>::deleteAll(BSTNodeEC<Data>* n)
{
  if(n == NULL) {
    return;
  }
  deleteAll(n->left);
  deleteAll(n->right);
  delete(n);
}



#endif //BST_HPP
